/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBufferType.h
 * \date 29.12.2015
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshBufferType class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс RshBufferType и связанные с ним типы данных.
 *
 */
 
#ifndef RSH_BUFFER_TYPE
#define RSH_BUFFER_TYPE
 
#include "RshDefChk.h"
#include "RshBaseType.h"
#include "RshConsts_Common.h"
#include "RshConsts_RshDataTypes.h"

#include <iostream>
#include <iomanip>
#include <cstddef> //size_t, ptrdiff_t

//undef if you have problems or don't need this functionality
#define PARTIAL_STL_COMPATIBILITY_ENABLED

#pragma pack(push, 8)

 /*!
 * 
 * \~english
 * \brief
 * Template class for buffer construction.
 * 
 * This template is used to construct
 * data buffer container classes derived from RshBaseType.\n
 * Also contains some useful methods to work with data,
 * such as sorting and saving to file.
 * 
 * \remarks
 * Data buffers created are used to pass
 * data to polymorfic methods of SDK, such as
 * IRshDevice::GetData() and so on.
 * 
 * \see
 * RshBaseType
 * 
 * \~russian
 * \brief
 * Шаблонный класс для конструирования буферов данных.
 * 
 * Данный шаблон используется для создания
 * классов-контейнеров (массивов данных), унаследованных
 * от RshBaseType.\n
 * Также содержит полезные методы для работы
 * с массивами данных - сортировка, запись в файл и др.
 * 
 * \remarks
 * Созданные буферы данных использутся, как правило,
 * для передачи массивов данных при вызове полиморфных
 * методов SDK, таких как IRshDevice::GetData() и др.
 * 
 * \see
 * RshBaseType
 * 
 */
template <typename T, RshDataTypes dataCode>
class RshBufferType : public RshBaseType
{

public:

#if defined(PARTIAL_STL_COMPATIBILITY_ENABLED)
	//STL compatibility definitions and methods
	
	/*!
	 * 
	 * \brief
	 * Container data type
	 * 
	 */
	typedef T value_type;

	/*!
	 * 
	 * \brief
	 * Reference to data type
	 * 
	 */
	typedef T& reference;

	/*!
	 * 
	 * \brief
	 * const reference to data type
	 * 
	 */
	typedef const T& const_reference;

	/*!
	 * 
	 * \brief
	 * Iterator type.
	 * Pointer to data stored in container is used,
	 * because RshBufferType is array based
	 * 
	 */
	typedef T* iterator;
	
	/*!
	 * 
	 * \brief
	 * const iterator type
	 * 
	 */
	typedef const T* const_iterator;
	
	/*!
	 * 
	 * \brief
	 * size type
	 * 
	 */
	typedef size_t size_type;

	/*!
	 * 
	 * \brief
	 * ptrdiff type
	 * 
	 */
	typedef ptrdiff_t difference_type;

	/*!
	 * 
	 * \brief
	 * begin() method. Just return internal array pointer.
	 * 
	 */
	iterator begin();

	/*!
	 * 
	 * \brief
	 * const begin() method. Just return internal array pointer.
	 * 
	 */
	const_iterator begin() const;

	/*!
	 * 
	 * \brief
	 * end() method. Return pointer to one-after-last element.
	 * 
	 */
	iterator end();

	/*!
	 * 
	 * \brief
	 * const end() method. Return pointer to one-after-last element.
	 * 
	 */
	const_iterator end() const;

	/*!
	 * 
	 * \brief
	 * Container size. Number of actual elements.
	 * Same as Size(), used for STL compatibility only.
	 * 
	 */
	size_type size() const;

	/*!
	 * 
	 * \brief
	 * Maximum number of elements container can hold.
	 * Same as PSize(), used for STL compatibility only.
	 * We are not implementing "on the fly" allocation
	 * as std::vector, for example.
	 * 
	 */
	size_type max_size() const;

	/*!
	 * 
	 * \brief
	 * Is container empty? Used for STL
	 * compatibility
	 * 
	 */
	bool empty() const;

	/*!
	 * 
	 * \brief
	 * Swap values of two containers.	 
	 * 
	 */
	void swap(RshBufferType<T, dataCode>& obj);
	

#endif //PARTIAL_STL_COMPATIBILITY_ENABLED

   /*!
	* 
	* \~english
	* \brief
	* Direct pointer to allocated memory.
	* 
	* One can use this pointer to access to
	* buffer data (there is also overloaded []
	* operator, but this method is faster - 
	* for long buffers its preferable).
	* 
	* \warning
	* Do not delete or change this pointer!
	* All operations with memory allocation
	* and release must be performed using class
	* methods. This pointer is set as public
	* only because performance issuses.\n
	* Also, always refer to RshBufferType::PSize() when indexing.
	* 
	* \~russian
	* \brief
	* Указатель на выделнную для данных память.
	* 
	* Можно использовать данный указатель для доступа
	* к данным, хранящимся в буфере (также, есть
	* перегруженный оператор [], но прямой доступ быстрее -
	* для больших массивов данных индексирование лучше
	* производить, используя указатель ptr).
	* 
	* \warning
	* Используйте данных указатель только для доступа к данным -
	* попытки выделить или удалить память или поменять адрес,
	* на который ссылается указатель могут быть фатальными.
	* Для управления памятью используйте методы класса.
	* Данный указатель имеет публичный доступ только из соображений
	* производительности и удобства.\n
	* Также, всегда используйте RshBufferType::PSize() в качестве референса
	* при индексировании.
	* 
	*/
	T* ptr;

	//! Constructor
	RshBufferType(size_t bufferSize = RSH_MAX_LIST_SIZE);
	
	//! Copy constructor
	RshBufferType(const RshBufferType<T, dataCode>& obj);
	
	//! Destructror
	~RshBufferType();

	/*!
	* 
	* \~english
	* \brief
	* Allocate memory for buffer data
	* 
	* \param[in] bufferSize
	* Desired size of buffer (elements number).
	* If system will fail to allocate memory,
	* error code will be returned and RshBufferType::PSize()
	* field will be equal to zero.
	* 
	* \returns
	* ::RSH_API_SUCCESS or error code.
	* 
	* Use this method to set buffer size you need and 
	* allocate memory for data. After successfull
	* call of this method RshBufferType::PSize() will be equal
	* to buffer size (number of elements), and
	* RshBufferType::ptr will point to allocated memory.
	* 
	* \remarks
	* If buffer size before call of this method was
	* different from bufferSize parameter passes,
	* old memory block will be delited, and all data
	* will be lost.
	* 
	* \~russian
	* \brief
	* Выделение памяти для данных буфера
	* 
	* \param[in] bufferSize
	* Желаемый размер буфера (количество элементов).
	* Если система не сможет выделить необходимый
	* размер памяти, будет возвращен соответствующий код
	* ошибки, а значение поля RshBufferType::PSize()
	* станет равным нулю.
	* 
	* \returns
	* ::RSH_API_SUCCESS или код ошибки.
	* 
	* Используйте этот метод для установки
	* необходимого размера буфера и выделения
	* памяти для данных. После успешного
	* вызова данного метода в поле RshBufferType::PSize()
	* будет содержаться размер (количество элементов) буфера,
	* а указатель RshBufferType::ptr будет
	* указывать на выделенный блок памяти.
	* 
	* \remarks
	* Если метод вызывается для буфера, который уже содержит
	* какие-то данные, и новый размер буфера отличается
	* от старого, старый блок памяти будет удален, и все
	* данные потеряны.
	* 
	*/
	U32 Allocate(size_t bufferSize = RSH_MAX_LIST_SIZE);	

	/*!
	* 
	* \~english
	* \brief
	* Copy data to buffer from memory location
	* 
	* \param[in] iptr
	* Pointer to memory block from where data
	* will be copied to buffer.
	* 
	* \param[in] psize
	* Physical size (in samples) of memory block
	* pointed by <b>iptr</b> parameter.
	* 
	* \param[in] size
	* How many samples need to be copied
	* from <b>iptr</b> memory location.\n
	* If zero, maximum avaliable samples
	* will be copied.
	* 
	* Use this method to fill buffer with data.
	* If allocated buffer size is less than size,
	* only part of data will be copied to buffer.
	* Always check RshBufferType::Size() after operation
	* complition to check how many elements buffer contain.
	* 
	* \~russian
	* \brief
	* Копирование данных в буфер из указанной области памяти
	* 
	* \param[in] iptr
	* Указатель на блок памяти, из которого
	* будут скопированы данные в буфер.
	* 
	* \param[in] psize
	* Размер (в отсчетах) блока памяти, на который
	* ссылается указатель, переданный в параметре <b>iptr</b>.\n
	* Если, например, копируются значения из массива, то 
	* размер psize должен быть равен размеру массива.
	* 
	* \param[in] size
	* Сколько всего элементов нужно скопировать в буфер из
	* области памяти, на которую указывает <b>iptr</b>\n
	* Если передать в качестве этого параметра ноль (дефолтное значение),
	* будет скопировано максимально возможное количество элементов.
	*
	* Этот метод можно использовать для заполнения буфера данными.
	* Если размер буфера (RshBufferType::PSize() ) меньше, чем заданное
	* для копирования количество элементов, только часть данных
	* будет скопирована в буфер. Всегда проверяйте состояние поля
	* RshBufferType::Size() после выполнения операции копирования,
	* чтобы определить актуальное количество элементов в буфере.
	*
	*/
	void Copy(const T* iptr, size_t psize, size_t size = 0);

	/*!
	* 
	* \~english
	* \brief
	* Copy data from buffer to memory location.
	* 
	* \param[in, out] iptr
	* Address of memory block where data 
	* from buffer will be placed.
	* 
	* \param[in] iptrSize
	* Maximum size (in samples) of memory
	* available for data.
	* 
	* \returns
	* Number of buffer elements copied to destination memory.
	* 
	* Copy data block from buffer to memory
	* block with address specified in <b>iptr</b> parameter.\n
	* If buffer size is smaller than <b>iptrSize</b>,
	* only RshBufferType::PSize() elements will be copied.
	*
	* \remarks
	* This method always try to copy maximum elements
	* availiable. If you need copy only, say, ten
	* elements to destination memory, specify
	* parameter iptrSize=10.
	* 
	* \~russian
	* \brief
	* Копирование данных из буфера в область памяти.
	* 
	* \param[in, out] iptr
	* Адрес (указатель на блок памяти),
	* куда нужно поместить данные из буфера.
	* 
	* \param[in] iptrSize
	* Максимальный размер (в отсчетах) блока памяти,
	* доступный для копирования.
	* 
	* \returns
	* Количество скопированных элементов буфера.
	* 
	* Данный метод копирует данные из буфера в заданную
	* параметром <b>iptr</b> область памяти.\n
	* Если размер буфера меньше, чем запрашиваемый 
	* размер (<b>iptrSize</b>), будет скопировано
	* только RshBufferType::PSize() элементов буфера.
	* 
	* \remarks
	* Данный метод всегда пытается скопировать максимально
	* возможное количество элементов из буфера. Если нужно,
	* к примеру, взять первые десять элементов, можно задать
	* параметр iptrSize=10.
	*
	*/
	size_t CopyTo(T* iptr, size_t iptrSize) const;

	/*!
	* 
	* \~english
	* \brief
	* Copy data from another buffer of the same type
	* 
	* \param[in] srcBuffer
	* Buffer of the same type from which
	* data will be copied to caller buffer.
	* 
	* Using this method one can fill buffer
	* with data from another buffer.
	* 
	* \remarks
	* No memory allocation is performed!
	* If destination buffer psize is smaller
	* than source buffer size, only
	* psize first elements will be copied.\n
	* If you want create identical buffer,
	* use copy constructor (dstBuffer = srcBuffer).
	* 
	* \~russian
	* \brief
	* Копирование данных из другого буфера того же типа
	* 
	* \param[in] srcBuffer
	* Буфер того же самого типа, что и вызывающий 
	* данный метод буфер.
	* 
	* Используя данный метод, можно заполнить
	* буфер данными из другого буфера.
	* 
	* \remarks
	* При вызове этого метода не производится
	* выделения памяти! Если буфер имеет 
	* размер (psize) меньший, чем количество 
	* элементов (m_size) в другом буфере, будут скопированы
	* только первые psize элементов.\n
	* Если требуется создать точную копию буфера, можно
	* использовать конструктор копий (dstBuffer = srcBuffer).
	* 	
	*/
	void Copy(const RshBufferType<T, dataCode>& srcBuffer);

	/*!
	* 
	* \~english
	* \brief
	* Sort buffer elements in assending order.
	* 
	* \returns
	* ::RSH_API_SUCCESS or error code.
	* 
	* This method use std::sort algorithm
	* to sort elements in assending orfer.
	*
	* \~russian
	* \brief
	* Сортировка буфера по возрастанию.
	* 
	* \returns
	* ::RSH_API_SUCCESS или код ошибки.
	* 
	* Данный метод использует алгоритм
	* std::sort для сортировки
	* элементов буфера в порядке возрастания.
	* 
	*/
	U32 SortAscending();

	/*!
	* 
	* \~english
	* \brief
	* Sort buffer elements in descending order.
	* 
	* \returns
	* ::RSH_API_SUCCESS or error code.
	* 
	* This method use std::sort algorithm
	* to sort elements in descending orfer.
	*
	* \~russian
	* \brief
	* Сортировка буфера по убыванию.
	* 
	* \returns
	* ::RSH_API_SUCCESS или код ошибки.
	* 
	* Данный метод использует алгоритм
	* std::sort для сортировки
	* элементов буфера в порядке убывания.
	* 
	*/
	U32 SortDescending();
		
	/*!
	* 
	* \~english
	* \brief
	* Print buffer values in standart output
	* 
	* \param[in] size
	* Number of elements to print. If zero (default) value
	* is passed, all available elements will be printed.
	* 
	* Output buffer content to console. If <b>size</b>
	* parameters is specified, only first size elements will be printed.
	* Otherwise, RshBufferType::Size() elements will be printed
	* (for initialized buffer with size>0). If RshBufferType::Size() is equal
	* to zero too, all data (RshBufferType::PSize()) will be printed.
	* 
	* \~russian
	* \brief
	* Печать содержимого буфер в стандартный поток вывода.
	* 
	* \param[in] size
	* Количество элементов, которые нужно напечатать. Если это число
	* равно нулю (дефолт), будут напечатаны все доступные элементы.
	* 
	* Вывод содержимого буфера на консоль. Если задан параметр
	* <b>size</b>, только первые size элементов буфера будут
	* напечатаны. Иначе, будет выведено RshBufferType::Size()
	* элементов (для буферов с RshBufferType::size>0). Если
	* RshBufferType::Size() тоже равен нулю, будут напечатаны все
	* данные буфера (RshBufferType::PSize()).
	*
	*/	
	void Print(size_t size=0) const;

   /*!
	*
	* \~english
	* \brief
	* Save buffer content to file
	* 
	* \param[in] fileName
	* Path to file where buffer must be written.
	* 
	* \param[in] elements
	* Number of elements to write.
	* If passed elements == 0, actual number of elements
	* to write will be Size() if buffer Size() > 0 or
	* PSize() otherwise.
	*
	* \returns
	* ::RSH_API_SUCCESS or error code.
	* 
	* Using this method, one can write RshBufferType::Size()
	* elements to file specified by <b>fileName</b>.
	* 
	* \~russian
	* \brief
	* Запись содержимого буфера в файл (актуальный размер)
	* 
	* \param[in] fileName
	* Путь к файлу, в который нужно записать данные.
	* 
	* \param[in] elements
	* Количество элементов, которые нужно записать в файл.
	* Если передано значение elements == 0, количество элементов
	* будет определено размером Size() буфера (если  Size() > 0 )
	* или размером PSize(), если Size() == 0.
	*
	* \returns
	* ::RSH_API_SUCCESS или код ошибки.
	* 
	* Используя данный метод, можно записать RshBufferType::Size()
	* элементов буфера в файл, заданный с помощью параметра <b>fileName</b>.
	* 
	*/
	U32 WriteBufferToFile(const char* fileName, size_t elements = 0) const;	

	U32 WriteBufferToFile(const std::string& fileName, size_t elements = 0) const;

	/*!
	*
	* \~english
	* \warning This method will have problems with non-latin characters in current SDK release
	*
	* \todo Fix character encoding issues.
	*
	* \~russian
	* \warning Данный метод имеет проблемы с кодировкой в текущей реализации,
	* если используются символы не из нижней части ASCII, или символы из других языков,
	* отличные от латинских.
	*
	* \todo Исправить проблемы с кодировками и преобразованием строки
	*/
	U32 WriteBufferToFile(const wchar_t* fileName, size_t elements = 0) const;	

	/*!
	* 
	* \~english
	* \warning This method will have problems with non-latin characters in current SDK release
	*
	* \todo Fix character encoding issues.
	*
	* \~russian
	* \warning Данный метод имеет проблемы с кодировкой в текущей реализации,
	* если используются символы не из нижней части ASCII, или символы из других языков,
	* отличные от латинских.
	*
	* \todo Исправить проблемы с кодировками и преобразованием строки
	*/
	U32 WriteBufferToFile(const std::wstring& fileName, size_t elements = 0) const;

	/*!
	* 
	* \~english
	* \brief
	* Fill buffer with data from file
	* 
	* \param[in] fileName
	* Path to the file which will be used
	* as data source to fill the buffer.
	*
	* \param[in] elements
	* Number of elements to read from file.
	* If zero, all file content will be placed in buffer.
	* 
	* \returns
	* ::RSH_API_SUCCESS or error code.
	* 
	* Using this method, one can fill buffer
	* with data stored in binary file. 
	* 
	* \remarks
	* Memory will be allocated automaticaly to 
	* store data in buffer, if current psize is not enough.
	* If not empty buffer is used for this operation,
	* its content will be lost.
	* 
	* \~russian
	* \brief
	* Заполнение буфера данными из файла
	* 
	* \param[in] fileName
	* Путь к файлу, который будет использован
	* в качестве источника данных для заполнения буфера.
	*
	* \param[in] elements
	* Количество элементов, которые нужно поместить в буфер.
	* Если переданное значение равно нулю, будет прочитано все содержимое файла.
	* 
	* \returns
	* ::RSH_API_SUCCESS или код ошибки.
	* 
	* Используя данный метод, можно прочитать данные
	* из указанного файла и заполнить ими буфер.
	* 
	* \remarks
	* Если текущий размер буфера (psize) недостаточен, чтобы вместить данные,
	* память будет выделена автоматически. Если в буфере
	* содержались какие-либо данные, они будут утеряны
	* после выполнения данного метода.
	* 
	*/
	U32 ReadBufferFromFile(const char* fileName, size_t elements = 0);

	U32 ReadBufferFromFile(const std::string& fileName, size_t elements = 0);

	/*!
	*
	* \~english
	* \warning This method will have problems with non-latin characters in current SDK release
	*
	* \todo Fix character encoding issues.
	*
	* \~russian
	* \warning Данный метод имеет проблемы с кодировкой в текущей реализации,
	* если используются символы не из нижней части ASCII, или символы из других языков,
	* отличные от латинских.
	*
	* \todo Исправить проблемы с кодировками и преобразованием строки
	*/
	U32 ReadBufferFromFile(const wchar_t* fileName, size_t elements = 0);	

	/*!
	*
	* \~english
	* \warning This method will have problems with non-latin characters in current SDK release
	*
	* \todo Fix character encoding issues.
	*
	* \~russian
	* \warning Данный метод имеет проблемы с кодировкой в текущей реализации,
	* если используются символы не из нижней части ASCII, или символы из других языков,
	* отличные от латинских.
	*
	* \todo Исправить проблемы с кодировками и преобразованием строки
	*/
	U32 ReadBufferFromFile(const std::wstring& fileName, size_t elements = 0);

	/*!
	* 
	* \~english
	* \brief
	* Get actual buffer data size.
	* 
	* \returns
	* Size of actual data in buffer in bytes.
	* 
	* Using this method one can obtain size
	* of actual data (RshBufferType::Size() elements)
	* in bytes.
	* 
	* \~russian
	* \brief
	* Получение размера актуальной части данных в буфере.
	* 
	* \returns
	* Размер актуальной части данных в байтах.
	* 
	* Используя данный метод, можно получить размер 
	* актуальной части буфера (RshBufferType::Size() элементов)
	* в байтах.
	* 
	*/
	size_t ByteSize() const;

	/*!
	* 
	* \~english
	* \brief
	* Get real buffer size in bytes.
	* 
	* \returns
	* Physical size of a buffer in bytes.
	* 
	* Using this method one can obtain physical size
	* of a buffer (RshBufferType::BytePSize() elements)
	* in bytes.
	* 
	* \~russian
	* \brief
	* Получение реального размера буфера в байтах. 
	* 
	* \returns
	* Физический размер буфера в байтах.
	* 
	* Используя данный метод, можно получить физический  
	* размер буфера (RshBufferType::BytePSize элементов)
	* в байтах.
	* 
	*/
	size_t BytePSize() const;

	/*!
	* 
	* \~english
	* \brief
	* Get buffer element size.
	* 
	* \returns
	* Size of buffer element in bytes.
	* 
	* Using this method one can obtain size
	* of buffer element in bytes.
	* 
	* \~russian
	* \brief
	* Получение размера элемента в буфере
	* 
	* \returns
	* Размер элеметна буфера в байтах
	* 
	* Используя данный метод, можно получить размер 
	* элемента буфера в байтах.
	* 
	*/
	size_t TypeSize() const;

	/*!
	* 
	* \~english
	* \brief
	* Get actual buffer size in data elements.
	* 
	* \returns
	* Size of actual data in buffer in elements.
	* 
	* Using this method one can obtain size
	* of actual data ( field RshBufferType::size )
	* in elements.
	* 
	* \~russian
	* \brief
	* Количество элементов в буфере (актуальный размер).
	* 
	* \returns
	* Размер актуальной части буфера данных в элементах.
	* 
	* Используя данный метод, можно получить размер 
	* актуальной части буфера ( поле RshBufferType::size)
	* в элементах.
	* 
	*/
	size_t Size() const;

	/*!
	* 
	* \~english
	* \brief
	* Get real buffer size in elements.
	* 
	* \returns
	* Physical size of a buffer in elements.
	* 
	* Using this method one can obtain physical size
	* of a buffer (RshBufferType::psize field)
	* in elements.
	* 
	* \~russian
	* \brief
	* Получение реального размера буфера в элементах. 
	* 
	* \returns
	* Физический размер буфера в элементах.
	* 
	* Используя данный метод, можно получить физический  
	* размер буфера (поле RshBufferType::psize)
	* в элементах.
	* 
	*/
	size_t PSize() const;

	T& operator[](size_t i);
	const T& operator[](size_t i) const;

	/*!
	* 
	* \~english
	* \brief
	* Set actual buffer size to zero value.
	* 
	* \remarks
	* Good to use before an invoke of IRshDevice::GetData().
	*
	* \~russian
	* \brief
	* Присваивает полю RshBufferType::size нулевое значение.
	* 
	* \remarks
	* Рекомендуется использовать этот метод перед вызовом
	* IRshDevice::GetData().
	* 
	*/
	void Clear();

	/*!
	* 
	* \~english
	* \brief
	* Set actual buffer size.
	*
	* Sometimes it is convenient to reuse buffer without memory allocation,
	* that can be performance hit. Setting buffer size value manualy one can
	* tell users of that buffer, that buffer only contains Size() elements
	* of useful data.
	*
	* \param[in] size
	* Actual buffer size to set
	* 
	* \remarks
	* Most internal methods in RshApi use this information when iterating
	* over buffers.
	* If passed size is more than buffer PSize(), it will be truncated.
	*
	* \~russian
	* \brief
	* Установка действительного размера массива
	*
	* Иногда удобно выделить память в буфере заранее, и затем использовать
	* его несколько раз для передачи массивов разного размера.
	* Перевыделение памяти с помощью Allocate() может быть накладным
	* с точки зрения производительности.
	* Устанавливая фактический размер данных в буфере с помощью этого метода,
	* можно избежать этих проблем
	* 
	* \param[in] size
	* Фактический размер полезных данных в буфере
	*
	* \remarks
	* Большинство внутренних методов RshApi используют этот размер при 
	* обходе буфера вместо PSize().
	* Если переданный параметр size будет превышать PSize(), размер буфера
	* будет установлен на максимально допустимый.
	* 
	*/
	void SetSize(size_t size);


	RshBufferType<T, dataCode>&	operator=(const RshBufferType<T, dataCode>& obj);

	bool operator==(RshBufferType<T, dataCode>& obj) const;

	bool operator!=(RshBufferType<T, dataCode>& obj) const;

	bool operator<(RshBufferType<T, dataCode>& obj) const;
	bool operator>(RshBufferType<T, dataCode>& obj) const;

	bool operator<=(RshBufferType<T, dataCode>& obj) const;
	bool operator>=(RshBufferType<T, dataCode>& obj) const;

	/*!
	*
	* \~english
	* \brief
	* Output buffer to std stream.
	*
	* This overloaded operation only prints first 32 elements,
	* or less, if buffer is smaller.
	* If you need to print large buffer, or specify exact number
	* of elements to print, use Print() method.
	*
	*
	* \~russian
	* \brief
	* Вывод буфера в стандартный поток вывода.
	*
	* Данная перегруженная операция печатает максимум 32 элемента буфера, или меньше,
	* если размер буфера меньше 32.
	* Если необходимо полностью вывести на печать больший буфер,
	* или определенное заранее заданное число элементов,
	* используйте метод Print().
	*
	*/
	friend std::ostream& operator<< (std::ostream &out, const RshBufferType<T, dataCode>& obj)
	{

		const size_t maxPrint = 32;

		out << "Buffer " << "[0x" << std::hex << &obj << std::dec << "], type: " << obj.GetTypeName() << std::endl;
		out << "Psize: " << obj.m_psize << ", Size: " << obj.m_size << std::endl;
		if (obj.ptr && (obj.m_psize != 0))
		{
			size_t printSize = 0;
			if (obj.m_size>0)
				printSize = obj.m_size< maxPrint ? obj.m_size : maxPrint;
			else
				printSize = obj.m_psize< maxPrint ? obj.m_psize : maxPrint;

			out << "Elements[0 - " << printSize << "]:" << std::endl;

			for (size_t i = 0; i<printSize; ++i)
				out << std::setw(6) << i << ": " << obj.ptr[i] << std::endl;

			return out;
		}
		else
			return out << "\nBuffer is not initialized!";
	}

	/*!
	* 
	* \~english
	* \brief
	* Add new element to buffer.
	* 
	* Adds new element to buffer end and increase its
	* size by one. If there is no more space left in buffer
	* (see RshBufferType::PSize()), error code will be returned
	*
	* \returns
	* ::RSH_API_SUCCESS or error code
	*
	* \param[in] obj
	* Value to push in buffer.
	*
	* \~russian
	* \brief
	* Добавление элемента в буфер.
	*
	* Данный метод добавляет элемент в конец буфера и увеличивает
	* его размер. Если в буфере не осталось места (см. RshBufferType::PSize()),
	* будет возвращен код ошибки.
	* 
	*
	* \returns
	* ::RSH_API_SUCCESS или код ошибки
	*
	* \param[in] obj
	* Значение, которое нужно поместить в буфер
	* 
	*/
	U32 PushBack(T obj);

private:
	/*!
	* 
	* \~english
	* \brief
	* Valid data samples in buffer.
	* 
	* This field determine, how many samples
	* are actually copied (or initialized) in buffer
	* data. For example, if buffer with size <b>psize</b>=1024
	* passed to IRshDevice::GetData() method, and GetData
	* have only 512 samples to store in buffer, after method call
	* <b>m_size</b> will be equal to 512.
	* 
	* \remarks
	* Good practice is to set buffer size to zero before any
	* method call, and check if this parameter changed after.
	* If not, no data is placed in buffer and some error occured
	* in method.
	* 
	* \~russian
	* \brief
	* Актуальное количество элеменов в буфере.
	* 
	* Данное поле определяет, какое количество данных
	* было фактически помещено в буфер. Например, если 
	* буфер с размером <b>psize</b>=1024 , был 
	* передан в метод IRshDevice::GetData(), и в него 
	* было помещено 512 элементов, после вызова метода
	* значение <b>m_size</b> будет равно 512.
	* 
	* \remarks
	* Хорошая практика - установить значение m_size равным нулю
	* перед вызовом метода, который должен заполнить буфер, 
	* и проверить это значение после. Если значение не изменилось,
	* значит произошла какая-либо ошибка при обработке  и заполнении
	* буфера.
	* 
	*/
	size_t m_size;

	/*!
	* 
	* \~english
	* \brief
	* Physical size of buffer in samples.
	* 
	* This field determine, how many samples
	* can buffer contain. Usually, this size
	* is defined in buffer constructor or
	* by call to RshBufferType::Allocate() method.
	*
	* \~russian
	* \brief
	* Физический размер (выделенная память) буфера в элементах.
	* 
	* Данное поле определяет максимальное количество элементов,
	* которые могут быть помещены в буфер. Обычно, этот
	* размер задается в конструкторе, или при вызове
	* метода RshBufferType::Allocate().
	* 
	*/
	size_t m_psize;

	//helper methods to save/load data from file
	U32 WriteToFile(const char* fileName, size_t elements) const;
	U32 ReadFromFile(const char* fileName, size_t elements);
};
 
// RshBufferType typedefs

/*!
 * 
 * \~english
 * \brief
 * Buffer of U8 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных U8.
 * 
 */
typedef RshBufferType< U8, rshBufferTypeU8> RSH_BUFFER_U8;

/*!
 * 
 * \~english
 * \brief
 * Buffer of S8 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных S8.
 * 
 */
typedef RshBufferType< S8, rshBufferTypeS8> RSH_BUFFER_S8;

/*!
 * 
 * \~english
 * \brief
 * Buffer of U16 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных U16.
 * 
 */
typedef RshBufferType< U16, rshBufferTypeU16> RSH_BUFFER_U16;

/*!
 * 
 * \~english
 * \brief
 * Buffer of S16 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных S16.
 * 
 */
typedef RshBufferType< S16, rshBufferTypeS16> RSH_BUFFER_S16;

/*!
 * 
 * \~english
 * \brief
 * Buffer of U32 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных U32.
 * 
 */
typedef RshBufferType< U32, rshBufferTypeU32> RSH_BUFFER_U32;

/*!
 * 
 * \~english
 * \brief
 * Buffer of S32 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных S32.
 * 
 */
typedef RshBufferType< S32, rshBufferTypeS32> RSH_BUFFER_S32;

/*!
 * 
 * \~english
 * \brief
 * Buffer of U64 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных U64.
 * 
 */
typedef RshBufferType< U64, rshBufferTypeU64> RSH_BUFFER_U64;

/*!
 * 
 * \~english
 * \brief
 * Buffer of S64 data.
 * 
 * \~russian
 * \brief
 * Буфер для типа данных S64.
 * 
 */
typedef RshBufferType< S64, rshBufferTypeS64> RSH_BUFFER_S64;

/*!
 * 
 * \~english
 * \brief
 * Buffer of float data.
 * 
 * \~russian
 * \brief
 * Буфер для данных типа float.
 * 
 */
typedef RshBufferType< float, rshBufferTypeFloat> RSH_BUFFER_FLOAT;

/*!
 * 
 * \~english
 * \brief
 * Buffer of double data.
 * 
 * \~russian
 * \brief
 * Буфер для данных типа double.
 * 
 */
typedef RshBufferType< double, rshBufferTypeDouble> RSH_BUFFER_DOUBLE;

/*!
 * 
 * \~english
 * \brief
 * Buffer of bool data.
 * 
 * \~russian
 * \brief
 * Буфер для данных типа bool.
 * 
 */
typedef RshBufferType< bool, rshBufferTypeBool> RSH_BUFFER_BOOL;

/*!
 * 
 * \~english
 * \brief
 * Buffer of U8* (pointer to U8) data.
 * 
 * \~russian
 * \brief
 * Буфер для данных типа U8* (указатель на U8).
 * 
 */
typedef RshBufferType< U8*, rshBufferTypeU8P> RSH_BUFFER_U8P;

/*!
 * 
 * \~english
 * \brief
 * Buffer of RshBaseType* (pointer to RshBaseType) data.
 * 
 * \~russian
 * \brief
 * Буфер для данных типа RshBaseType* (указатель на RshBaseType).
 * 
 */
typedef RshBufferType< RshBaseType*, rshBufferTypeBaseP > RSH_BUFFER_BASETYPEP;
 
#pragma pack(pop)
 
#endif //RSH_BUFFER_TYPE
