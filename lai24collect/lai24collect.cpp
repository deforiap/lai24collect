/* Copyright (C) 2015-2018 IAPRAS - All Rights Reserved */

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <ctime>

#include "util.h"
#include "parameters.hpp"

const char *ini_file_name = "lai24collect.ini";

int adc_thread_sleep = 10;

int gain0 = 1;
int gain1 = 1;
int gain2 = 1;
int gain3 = 1;

bool verbose = false;

struct Parameters : public ParametersRegister {
	PARAMETER(int, adc_thread_sleep, 100);	// milliseconds

	PARAMETER(std::string, board_name, "LAI24USB");
	PARAMETER(unsigned, device_id, 1);
	PARAMETER(double, sample_freq, 800.0);
	PARAMETER(unsigned, channel_number, 4);

	PARAMETER(unsigned, buffer_size, 256);
	PARAMETER(unsigned, buffers_count, 10);

	PARAMETER(int, gain0, 1);
	PARAMETER(int, gain1, 1);
	PARAMETER(int, gain2, 1);
	PARAMETER(int, gain3, 1);

	PARAMETER(bool, verbose, false);
};


// Data write stuff
int write_data();

extern std::string BoardName;
//Номер устройства. Если в системе установлено несколько одинаковых устройств, можно выбрать, к какому из них подключаться. Нумерация начинается с 1.
extern unsigned DeviceID;
// Частота дискретизации (на канал).
extern double SampleFreq;
// Количество задействованных каналов
extern unsigned ChannelNumber;


// Размер внутреннего буфера (на канал). Когда буфер заполнится, произойдет прерывание
extern unsigned InternalBufferSize;
// Сколько таких буферов будет собрано до остановки (и записано в отдельный файл).
extern unsigned InternalBufferCount;

std::string FileName("output.dat");

int main(int argc, char *argv[]) {
	Parameters p = Parameters();
	p.parse(ini_file_name);

	BoardName = p.board_name;
	DeviceID = p.device_id;
	SampleFreq = p.sample_freq;
	ChannelNumber = p.channel_number;

	InternalBufferSize = p.buffer_size;
	InternalBufferCount = p.buffers_count;

	gain0 = p.gain0;
	gain1 = p.gain1;
	gain2 = p.gain2;
	gain3 = p.gain3;

	verbose = p.verbose;

	// redefine parameters from command line

	for (int i = 1; i < argc; ++i)
	{
		if (strncmp(argv[i], "-s", 2) == 0) {
			++i; if (i >= argc) break;
			InternalBufferSize = atoi(argv[i]);
		}
		if (strncmp(argv[i], "-n", 2) == 0) {
			++i; if (i >= argc) break;
			InternalBufferCount = atoi(argv[i]);
		}
		if (strncmp(argv[i], "-r", 2) == 0) {
			++i; if (i >= argc) break;
			SampleFreq = atof(argv[i]);
		}
		if (strncmp(argv[i], "-k", 2) == 0) {
			++i; if (i >= argc) break;
			int g = atoi(argv[i]);
			gain0 = g;
			gain1 = g;
			gain2 = g;
			gain3 = g;
		}
		if (strncmp(argv[i], "-c", 2) == 0) {
			++i; if (i >= argc) break;
			ChannelNumber = atoi(argv[i]);
		}
		if (strncmp(argv[i], "-fn", 3) == 0) {
			++i; if (i >= argc) break;
			FileName = argv[i];
		}
		if (strncmp(argv[i], "-h", 2) == 0) {
			std::cout << "lai24collect" << std::endl
				<< "\t" << "-s <buffer size:32,64,128,256,512,1024,2048,4096,8192,16384>" << std::endl
				<< "\t" << "-n <number of collected buffers>" << std::endl
				<< "\t" << "-r <sample rate>" << std::endl
				<< "\t" << "-k <gain, same for all channels>" << std::endl
				<< "\t" << "-c <channels number:1,2,3,4>" << std::endl
				<< "\t" << "-fn <file name>" << std::endl;
			return 1;
		}
	}

	if (verbose) {
		std::cout << "verbose mode" << std::endl;
	}

	write_data();


	return 0;
}


#include <RshApi.cpp>

IRshDevice* device = nullptr;

// Язык вывода ошибок. (В случае проблем с кодировкой выбирайте английский язык)
// const RSH_LANGUAGE ErrorLanguage = RSH_LANGUAGE_RUSSIAN;
const RSH_LANGUAGE ErrorLanguage = RSH_LANGUAGE_ENGLISH;


//======================ПАРАМЕТРЫ СБОРА===========================
// Служебное имя устройства, с которым будет работать программа.
std::string BoardName("LAI24USB");
//Номер устройства. Если в системе установлено несколько одинаковых устройств, можно выбрать, к какому из них подключаться. Нумерация начинается с 1.
unsigned DeviceID = 1;
// Частота дискретизации (на канал).
double SampleFreq = 800.0;
// Количество задействованных каналов
unsigned ChannelNumber = 4;


// Размер внутреннего буфера (на канал). Когда буфер заполнится, произойдет прерывание
unsigned InternalBufferSize = 256;
// Сколько таких буферов будет собрано до остановки (и записано в отдельный файл).
unsigned InternalBufferCount = 100;


//Функция выводит сообщение об ошибке и завершает работу программы
/*
U32 SayGoodBye(RshDllClient& Client, U32 st, const char* desc = 0)
{
	if (desc) {
		std::cout << "Error on " << desc << " call." << std::endl;
	}

	RshError::PrintError(st, ErrorLanguage, true);

	Client.Free(); // выгружает все загруженные классом RshDllClient библиотеки.

	return st;
}
*/

class RshException {
	std::string description;
	U32 status;
public:
	RshException(U32 st, const std::string &desc) :
		status(st), description(desc)
	{}

	const std::string get_description() {
		return description;
	}
};


int write_data()
{
	//Статус выполнения операции. RSH_API_SUCCESS в случае успеха, либо код ошибки
	U32 st = RSH_API_SUCCESS;
	//Указатель на объект с интерфейсом IRshDevice, который используется для доступа к устройству.
	device = nullptr;
	//Класс для загрузки библиотеки абстракции.
	RshDllClient Client;

	{
		try
		{

			//===================== ПОЛУЧЕНИЕ СПИСКА ЗАРЕГИСТРИРОВАННЫХ БИБЛИОТЕК =====================
			//В данном примере результаты этого вызова не используются,
			//так как мы заранее знаем имя библиотеки (константа BoardName)

			std::vector<std::string> allDevices;
			st = Client.GetRegisteredList(allDevices);
			if (st == RSH_API_SUCCESS)
			{
				if (verbose) {
					for (std::vector<std::string>::iterator it = allDevices.begin();
						it != allDevices.end(); ++it)
					{
						std::cout << *it << std::endl;
					}
				}
			}

			//===================== ЗАГРУЗКА КЛАССА ДЛЯ РАБОТЫ С УСТРОЙСТВОМ ИЗ БИБЛИОТЕКИ =====================
			//Инициализируем интерфейсный ключ.
			if (verbose) {
				std::cout << "BoardName " << BoardName << std::endl;
			}
			RshDllInterfaceKey DevKey(BoardName.c_str(), device);

			// Получаем экземляр класса устройства.
			st = Client.GetDeviceInterface(DevKey);
			if (st != RSH_API_SUCCESS)
				// return SayGoodBye(Client, st, );
				throw RshException(st, "Client.GetDeviceInterface(DevKey)");

			//После успешного выполнения вызова Client.GetDeviceInterface()
			//указатель device ссылается на инстанцированный объект,
			//который можно использовать для управления устройством


			//===================== ИНФОРМАЦИЯ ОБ ИСПОЛЬЗУЕМЫХ БИБЛИОТЕКАХ =====================
			RSH_S8P libname = 0;
			st = device->Get(RSH_GET_LIBRARY_FILENAME, &libname);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_LIBRARY_FILENAME)");
			else {
			}

			RSH_S8P libVersion = 0;
			st = device->Get(RSH_GET_LIBRARY_VERSION_STR, &libVersion);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_LIBRARY_VERSION_STR)");
			else {
			}

			RSH_S8P libCoreName = 0;
			st = device->Get(RSH_GET_CORELIB_FILENAME, &libCoreName);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_CORELIB_FILENAME)");
			else {
			}

			RSH_S8P  libCoreVersion = 0;
			st = device->Get(RSH_GET_CORELIB_VERSION_STR, &libCoreVersion);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_CORELIB_VERSION_STR)");
			else {
			}


			{
				//============================= ПРОВЕРКА СОВМЕСТИМОСТИ =============================
				// Проверим, поддерживает ли устройство сбор данных в непрерывном режиме.
				RSH_U32 caps = RSH_CAPS_SOFT_PGATHERING_IS_AVAILABLE;
				st = device->Get(RSH_GET_DEVICE_IS_CAPABLE, &caps);
				if (st != RSH_API_SUCCESS)
					throw RshException(st, "device->Get(RSH_GET_DEVICE_IS_CAPABLE)");
			}

			{
				//============================= ПРОВЕРКА СОВМЕСТИМОСТИ =============================
				// Проверим, есть ли возможность управлять цифровыми портами.
				RSH_U32 caps = RSH_CAPS_SOFT_DIGITAL_PORT_IS_AVAILABLE;
				st = device->Get(RSH_GET_DEVICE_IS_CAPABLE, &caps);
				if (st != RSH_API_SUCCESS)
					throw RshException(st, "device->Get(RSH_GET_DEVICE_IS_CAPABLE)");
			}

			{
				//============================= ПРОВЕРКА СОВМЕСТИМОСТИ =============================
				// Проверим, есть ли возможность внешнего старта
				RSH_U32 caps = RSH_CAPS_DEVICE_EXTERNAL_START;
				st = device->Get(RSH_GET_DEVICE_IS_CAPABLE, &caps);
				if (st != RSH_API_SUCCESS)
					throw RshException(st, "device->Get(RSH_CAPS_DEVICE_EXTERNAL_START)");
			}


			//========================= ПОДКЛЮЧЕНИЕ К УСТРОЙСТВУ ====================================
			// Создаем ключ, по которому будет выполняться подключение (в данном случае используется базовый адрес)
			RshDeviceKey connectKey(DeviceID);

			// Подключаемся к устройству	
			if (verbose) {
			}
			st = device->Connect(&connectKey);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Connect()");

			// Полное (точное) имя устройства и заводской номер доступны только после подключения к устройству
			RSH_S8P fullDeviceName = 0;
			st = device->Get(RSH_GET_DEVICE_NAME_VERBOSE, &fullDeviceName);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_DEVICE_NAME_VERBOSE)");
			else {
			}

			RSH_U32 serialNumber = 0;
			st = device->Get(RSH_GET_DEVICE_SERIAL_NUMBER, &serialNumber);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_DEVICE_SERIAL_NUMBER)");
			else {
			}

			/*
			RSH_BUFFER_U32 size_list;
			st = device->Get(RSH_GET_DEVICE_SIZE_LIST, &size_list);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_DEVICE_SIZE_LIST )");
			else {
				if (verbose) {
					for (size_t i = 0; i < size_list.size(); ++i) {
						std::cout
							<< std::setw(2) << std::setfill('0') << now_hours << ":" << std::setw(2) << std::setfill('0') << now_minutes << ":" << std::setw(2) << std::setfill('0') << now_seconds << "\t"
							<< "Possible size " << size_list[i] << std::endl;
					}
				}
			}
			*/

			//========================= ИНИЦИАЛИЗАЦИЯ ====================================

			// Структура для инициализации параметров работы устройства.
			RshInitDMA  p;

			// Запуск сбора данных - программный.
			// p.startType = RshInitDMA::Program;
			// p.startType = RshInitDMA::External;
			p.startType = RshInitDMA::Persistent;

			//Ставим флаг "непрерывный режим"
			p.dmaMode = RshInitDMA::Persistent;
			// p.dmaMode = RshInitDMA::Single;
			// Размер блока данных (в отсчетах на канал)
			p.bufferSize = InternalBufferSize;
			// Частота дискретизации.
			p.frequency = SampleFreq;

			//настройка измерительных каналов
			p.channels.SetSize(ChannelNumber);
			for (unsigned i = 0; i < ChannelNumber; ++i)
			{
				//Сделаем канал активным.
				p.channels[i].SetUsed();

				//Зададим коэффициент усиления
			}

			p.channels[0].gain = gain0;
			p.channels[1].gain = gain1;
			p.channels[2].gain = gain2;
			p.channels[3].gain = gain3;

			// Инициализация параметров работы устройства и драйвера. 
			if (verbose) {
				std::cout
					<< "Initializing device ... ";
			}
			st = device->Init(&p);
			// Параметры могут быть скорректированны, это отразится в структуре "p".
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Init(&p)");

			// ИНФОРМАЦИЯ О ПРЕДСТОЯЩЕМ СБОРЕ ДАННЫХ
			RSH_U32 activeChanNumber = 0;
			st = device->Get(RSH_GET_DEVICE_ACTIVE_CHANNELS_NUMBER, &activeChanNumber);
			if (st != RSH_API_SUCCESS)
				throw RshException(st, "device->Get(RSH_GET_DEVICE_ACTIVE_CHANNELS_NUMBER)");

			if (activeChanNumber == 0)
			{
				throw RshException(RSH_API_PARAMETER_CHANNELWASNOTSELECTED, "ActiveChanNumber is zero, something is wrong!");
			}

			if (verbose) {
				std::cout << "Initialization parameters:" << std::endl << p << std::endl;
				std::cout << "  The number of active channels: " << activeChanNumber << std::endl;
				std::cout << "  Real buffer size: " << p.bufferSize << std::endl;
				std::cout << "  Real InternalBufferCount: " << InternalBufferCount << std::endl;
				std::cout << "  Data to be collected per channel: " << (p.bufferSize * InternalBufferCount) << std::endl;
				std::cout << "  The estimated time of gathering completion: " << (p.bufferSize * InternalBufferCount / p.frequency) << "s" << std::endl;
			}

			// Номер цикла (для именования файлов)  
			U32 loopNum = 0;
			//Буфер с данными, получаемый от устройства

			// Размер буфера в байтах.
			// U32 bBufSize = iBuffer.TypeSize() * p.bufferSize * activeChanNumber.data;

			// std::cout << "Buffer size in bytes " << bBufSize << std::endl;
			// std::cout << "InternalBufferCount " << InternalBufferCount << std::endl;
			// std::cout << "Allocate userBuffer parameter " << bBufSize * InternalBufferCount << std::endl;

			//Буфер с "непрерывными" данными. Конструктор по умолчанию создает буфер на RSH_MAX_LIST_SIZE элементов.
			// RSH_BUFFER_U8 userBuffer;
			//Выделим память, используя найденный размер в байтах. 
			// userBuffer.Allocate(bBufSize * InternalBufferCount);
			// Максимальное время ожидания готовности данных (в мс) - час

			RSH_U32 timeToWait = 3600 * 1000;

			{
				if (verbose) {
					std::cout
						<< "Starting device..." << std::endl;
				}
				//Запускаем сбор данных в непрерывном режиме
				st = device->Start();

				if (st != RSH_API_SUCCESS)
					throw RshException(st, "device->Start()");

				//собираем данные в непрерывном режиме
				std::string fileName;

				int current_buffers_count = InternalBufferCount;

				for (U32 Loops = 0; Loops < current_buffers_count; ++Loops)
				{
					RSH_BUFFER_S32 iBuffer(p.bufferSize * activeChanNumber.data);

					std::cout << "Collecting " << Loops << " of " << current_buffers_count << "..." << std::endl;
					if (verbose) {
						std::cout
							<< "waiting RSH_GET_WAIT_BUFFER_READY_EVENT..." << std::endl;
					}

					if (adc_thread_sleep > 0)
						std::this_thread::sleep_for(std::chrono::milliseconds(adc_thread_sleep));

					st = device->Get(RSH_GET_WAIT_BUFFER_READY_EVENT, &timeToWait);
					if (st != RSH_API_SUCCESS)
					{
						{
							if (st == RSH_API_EVENT_WAITTIMEOUT)
							{
								std::cout << "Error: RSH_API_EVENT_WAITTIMEOUT" << std::endl;
							}
							else
							{
								std::cout << "Error: unknown" << st << std::endl;
							}
						}
						throw RshException(st, "device->Get(RSH_GET_WAIT_BUFFER_READY_EVENT)");
					}

					// После первого запуска ждать больше 40 секунд нельзя

					if (verbose) {
						std::cout
							<< "getting data to " << iBuffer.ptr << std::endl;
					}

					if (verbose) {
						std::cout
							<< "iBuffer type " << std::hex << iBuffer._type << " "
							<< "size" << iBuffer._typeSize
							<< std::dec << std::endl;
					}
					constexpr int itries_max_n = 4;
					int try_i = 0;
					for (; try_i < itries_max_n; ++try_i) {
						try {
							st = device->GetData(&iBuffer);
							if (st != RSH_API_SUCCESS)
								throw RshException(st, "device->GetData(&iBuffer)");
							break;
						}
						catch (RshException&) {
							std::cout
								<< "Retry get data..." << std::endl;

						}
					}
					if (try_i == itries_max_n) {
						std::cout << "After " << try_i << " tries device->GetData failed" << std::endl;

						throw RshException(st, "device->GetData(&iBuffer)");
					}

					if (verbose) {
						std::cout
							<< "data in buffer " << iBuffer.ptr << std::endl;
					}

					// Скопируем данные в "непрерывный" буфер, используя прямой доступ
					// к внутреннему представлению буфера (RshBufferType->ptr)
					// memcpy(userBuffer.ptr + Loops * bBufSize, iBuffer.ptr, iBuffer.ByteSize());

					// create file name

					// Сохраняем буфер с данными в мзр-формате на жесткий диск.
					// st = userBuffer.WriteBufferToFile(fileName);
					{
						std::ofstream of(FileName.c_str(), std::ios::app | std::ios::binary);
						of.write(reinterpret_cast<const char*>(iBuffer.ptr), iBuffer.ByteSize());
					}

				} // for (Loops...

				if (verbose) {
					std::cout
						<< "Stopping device..." << std::endl;
				}

				device->Stop();

				//таймаут - 15 секунд
				RSH_U32 timeout = 15000;
				//ждем завершения процесса
				U32 res = device->Get(RSH_GET_WAIT_GATHERING_COMPLETE, &timeout);
				if (res != RSH_API_SUCCESS)
				{
					std::cout
						<< "RSH_GET_WAIT_GATHERING_COMPLETE error!" << std::endl;
				}
			}

		}
		catch (RshException &ex) {
			std::cout
				<< "Error on " << ex.get_description() << " call." << std::endl;

			RshError::PrintError(st, ErrorLanguage, true);

			Client.Free(); // выгружает все загруженные классом RshDllClient библиотеки.
		}

		if (verbose) {
			std::cout
				<< "Next loop of data acquisition cycle" << std::endl;
		}

	}

	Client.Free();
	return RSH_API_SUCCESS;

}
