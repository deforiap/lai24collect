/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file IRshFactory.h
 * \date 11.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * IRshFactory interface - abstract class factory.
 *
 * 
 * \~russian
 * \brief
 * Интерфейс IRshFactory - абстрактная фабрика классов.
 * 
 * 
 */

#ifndef RSH_FACTORY_H
#define RSH_FACTORY_H


#include "RshDefChk.h"
#include "RshBaseType.h"

#pragma pack(push, 8)

/*!
 * 
 * \~english
 * \brief
 * IRshFactory interface - abstract factory.
 * 
 * Objects with this interface are used to instantinate
 * classes like device abstraction classes (IRshDevice),
 * base classes (IPLX9054 etc), algorithm libraries (IDPA)
 * and other. 
 * 
 * \see
 * IRshDevice | RshDllClient
 * 
 * \~russian
 * \brief
 * Интерфейс IRshFactory - абстрактная фабрика классов.
 * 
 * Объекты с этим интерфейсом (фабрика) используются
 * для инстанцирования других объектов, таких как классы абстракции 
 * устройств (IRshDevice), базовые классы (IPLX9054 и др.), классы
 * алгоритмической библиотеки (IDPA).
 * 
 * \see
 * IRshDevice | RshDllClient
 * 
 */
struct  IRshFactory 
{
 	/*!
	 * 
	 * \~english
	 * \brief
	 * Create new instance of the class.
	 * 
	 * \param[in] libIName
	 * Interface name of the class that should be
	 * instantioned by factory. Usualy each concrete factory
	 * class can instantinate objects with certain interface only
	 * (for example, objects for device control with IRshDevice
	 * interface). If interface name passed is not supported
	 * by factory, error code will be returned.
	 * 
	 * \param[in, out] libInterface
	 * Pointer to pointer to object need to be instantioned.
	 * After successfull method call, will be point to
	 * actual interface class created by factory.
	 * 
	 * \param[in] factoryParameter
	 * Additional data passed to factory. Not used in
	 * most cases.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 * 
	 * This method is the main method of factory class and
	 * used to inctantinate objects (factory purpuse).\n
	 * Created object pointer will be returned in
	 * libInterface parameter.
	 * 
	 * \remarks
	 * Be careful with pointers! Usually you need declare
	 * interface class variable and then to pass pointer to it:
	 * \code 
	 * IRshDevice* device;
	 * factory->CreateInstance("IRSHDevice",(void**)&device);
	 * \endcode 
	 * 
	 * \see
	 * RshDllClient
	 * 
	 * \~russian
	 * \brief
	 * Инстанцирование объекта класса.
	 * 
	 * \param[in] libIName
	 * Имя интерфейса класса, который необходимо
	 * инстанцировать. Обычно, каждая конкретная реализация
	 * класса фабрики порождает объекты с определенным интерфейсом
	 * (например, объекты для управления устройствами с интерфейсом
	 * IRshDevice). Если переданное имя интерфейса не поддерживается
	 * фабрикой, будет возвращена ошибка.
	 * 
	 * \param[in, out] libInterface
	 * Указатель на указатель на объект класса, который необходимо
	 * инстанцировать. После успешного вызова метода, указатель 
	 * будет ссылаться на фактически созданный фабрикой объект
	 * класса с нужным интерфейсом.
	 * 
	 * \param[in] factoryParameter
	 * Дополнительные параметры инстанцирования, в большинстве
	 * случаев не используется.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 * 
	 * Основной метод класса фабрики, используется для инстанцирования
	 * объектов (предназначение фабрики).\n
	 * Указатель на созданный экземлпяр класса будет возвращен
	 * в параметре libInterface.
	 * 
	 * \remarks
	 * Будьте осторожны при работе с указателями!
	 * Внтури метода проверяется только то, что указатель ненулевой, тип 
	 * данных проверить невозможно.\n
	 * В большинстве случаев, нужно объявить переменную как указатель на интерфейс
	 * класса, который нужно инстанцировать, и передать в метод указатель на нее:
	 * \code 
	 * IRshDevice* device;
	 * factory->CreateInstance("IRSHDevice",(void**)&device);
	 * \endcode 
	 * 
	 * \see
	 * RshDllClient
	 * 
	 */
	virtual U32   __RSHCALLCONV CreateInstance(IN const char* libIName, OUT void** libInterface, IN void* factoryParameter = NULL) = 0; 

	/*!
	 * 
	 * \~english
	 * \brief
	 * Free object resources and delete object
	 * 
	 * \param[in, out] objectAddress
	 * Address of the object previously created by factory.
	 * Every time CreateInstance() method is successfully called,
	 * created object reference is saved in internal factory storage.
	 * When you don't need this object anymore, pass pointer to it
	 * as parameter to this method, and object will be properly delited,
	 * including all assostiated resources.\n
	 * Pointer will be NULL after successfull call of this method.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 * 
	 * Free resources allocated for 'objectAddress' which was created
	 * by CreateInstance() method, and then delete object. If object
	 * address is not found in internal storage, error code will be returned.
	 * 
	 * \remarks
	 * You can call Free() method as alternative, which is perform Release()
	 * on every object, created by this factory.
	 * 
	 * \see
	 * Free()
	 * 
	 * \~russian
	 * \brief
	 * Освобождение ресурсов и удаление объекта
	 * 
	 * \param [in, out] objectAddress
	 * Адрес объекта, который ранее был инстанцирован фабрикой.
	 * Каждый раз при успешном вызове метода CreateInstance()
	 * адрес порожденного фабрикой объекта сохраняется во внутреннем хранилище.
	 * Если данный объект уже не нужен, можно передать указатель на 
	 * него в этот метод, и объект будет надлежащим образом удален, а
	 * все связанные с ним ресурсы выгружены.\n
	 * Переданный указатель, при этом, станет равным NULL.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 * 
	 * Освобождение ресурсов, выделенных для объекта 'objectAddress',
	 * который был ранее создан с помощью метода CreateInstance(), 
	 * и последующее удаление объекта. Если переданный адрес не найден
	 * во внутреннем хранилище (т.е. переданный объект не создавался 
	 * данной фабрикой) будет возвращен код ошибки.
	 * 
	 * \remarks
	 * Можно также использовать метод Free(), который последовательно
	 * вызывает Release() для всех объектов, ранее порожденных фабрикой.
	 * 
	 * \see
	 * Free()
	 * 
	 */
	virtual U32   __RSHCALLCONV Release(IN OUT void** objectAddress) = 0; 

	/*!
	 * 
	 * \~english
	 * \brief
	 * Free all resources allocated by instancinated objects.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 * 
	 * Using this method one can properly clear all
	 * allocated resources and delete objects, created 
	 * by factory.\n
	 * Typical scenario is to call this method, when you
	 * dont need any objects instancinated by this factory
	 * anymore - on exit application, for example.
	 * 
	 * \remarks
	 * After successfull call to this method all created
	 * object links will be equal to NULL or not valid!
	 * 
	 * \see
	 * Release()
	 * 
	 * \~russian
	 * \brief
	 * Освобождение всех ресурсов и удаление всех объектов, порожденных фабрикой.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 * 
	 * Используя данный метод можно гарантированно освободить все выделенные
	 * ресурсы и удалить созданные фабрикой объекты.\n
	 * Типичный сценарий использования - вызов данного метода в тот момент,
	 * когда созданные фабрикой объекты уже не нужны - в деструкторе
	 * основного класса, или при выходе из приложения.
	 * 
	 * \remarks
	 * После успешного вызова данного метода все созданные фабрикой
	 * объекты будут удалены, и указатели на них станут недействительными
	 * либо равными NULL!\n
	 * 
	 * 
	 * \see
	 * Release()
	 * 
	 */
	virtual U32   __RSHCALLCONV Free() = 0;

	/*!
	 * 
	 * \~english
	 * \brief
	 * Get additional information about factory.
	 * 
	 * \param[in] code
	 * One of the ::RSH_GET enum codes.
	 * 
	 * \param[in, out] address
	 * Where to store information. Different
	 * codes require different data types, but all
	 * of them must be inherited from RshBaseType.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS or error code.
	 * 
	 * This method is analog of IRshDevice::Get() method.\n
	 * For factories exported from dlls one can obtain
	 * such information as file path(::RSH_GET_LIBRARY_PATH),
	 * library version(::RSH_GET_LIBRARY_VERSION_STR) and so on.
	 * 
	 * \see
	 * ::RSH_GET
	 * 
	 * \~russian
	 * \brief
	 * Получение дополнительной информации о фабрике.
	 * 
	 * \param[in] code
	 * Один из кодов перечисления ::RSH_GET.
	 * 
	 * \param[in, out] address
	 * Адрес объекта, в котором будет передана нужная информация.
	 * Различные коды требуют различных типов данных, но все они
	 * должны быть унаследованы от RshBaseType.
	 * 
	 * \returns
	 * ::RSH_API_SUCCESS или код ошибки.
	 * 
	 * Этот метод - аналог метода IRshDevice::Get().\n
	 * Для классов фабрики, экспортируемых из dll, можно
	 * получить такую информацию, как путь к файлу (::RSH_GET_LIBRARY_PATH),
	 * версию библиотеки (::RSH_GET_LIBRARY_VERSION_STR) и др.
	 * 
	 * \see
	 * ::RSH_GET
	 * 
	 */
	virtual U32   __RSHCALLCONV Get(IN U32 code, IN OUT RshBaseType* address) = 0;
};

#pragma pack(pop)

#endif //RSH_FACTORY_H
