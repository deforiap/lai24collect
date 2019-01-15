/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBaseType.h
 * \date 12.01.2016
 * \version 1.0 [SDK 2.1]
 *
 * \~english
 * \brief
 * RshBaseType class and dependent types declaration.
 *
 * \~russian
 * \brief
 * Класс  RshBaseType и связанные с ним типы данных.
 *
 */
 
 #ifndef RSH_BASETYPE_H
 #define RSH_BASETYPE_H
 
 #include "RshDefChk.h"
 #include "RshConsts_RshDataTypes.h"
 
#pragma pack(push, 8)
 
/*!
 * 
 * \~english
 * \brief
 * Base class for all other SDK classes.
 * 
 * All SDK classes, data types and data
 * structures are deriverd from this one.\n
 * Every deriverd class has its own ID
 * (stored in _type field) and can be
 * identified. It allows easily implement 
 * polymophic behaviour for classes and methods.
 *
 *
 * \warning
 * To maintain binary compatibility with SDK version 2.0
 * virtual destructor is disabled.
 * Every derived type has built in type info (e.g. _type field),
 * so user should NEVER use destructor on base type.\n
 * If you need to delete one of derived classes passed as RshBaseType* pointer,
 * make explicit cast first, using _type and _typeSize information.
 *
 * \code 	 
 * RshBaseType* ptr;  //some class pointer obtained from external call
 *
 * //Check if real type is what we expect here
 * if(ptr && ptr->_type == rshBufferTypeU8)
 * {
 *   RSH_BUFFER_U8* buffer = static_cast<RSH_BUFFER_U8*>(ptr);
 * if (buffer)
 *   {
 *		delete buffer;
 *		ptr = 0;
 *	}
 * }
 * \endcode 
 *
 * 
 * \~russian
 * \brief
 * Базовый класс для всех классов SDK.
 * 
 * Все остальные классы, структуры и типы данных
 * SDK унаследованы от этого базового класса.\n
 * Каждый класс-потомок имеет свой уникальный 
 * идентификатор (хранящийся в поле _type), по которому
 * можно определить тип данных. Использование
 * базового класса позволяет легко реализовать полиморфизм
 * для методов и классов.
 *
 * \warning
 * Для сохранения бинарной совместимости с SDK версии 2.0
 * виртуальный деструктор не используется.
 * Каждый производный от RshBaseType класс имеет встроенную
 * информацию о типе (поле _type), поэтому можно избежать вызова
 * деструктора для указателя на базовый класс.\n
 * Если есть необходимость динамически удалять объекты, на которые указывает 
 * указатель типа RshBaseType*, нужно определить тип объекта и сделать явное
 * преобразование типа, после чего применять операцию delete.
 * 
 * \code 	 
 * RshBaseType* ptr; //указатель на объект, производный от RshBaseType, получен извне
 *
 * //Проверим, совпадает ли тип с ожидаемым
 * if(ptr && ptr->_type == rshBufferTypeU8)
 * {
 *	//приведем указатель к реальному типу
 *   RSH_BUFFER_U8* buffer = static_cast<RSH_BUFFER_U8*>(ptr);
 *   //если приведение прошло удачно, удалим объект
 *   if (buffer)
 *   {
 *		delete buffer;
 *		ptr = 0;
 *	}
 * }
 * \endcode 
 *
 */
struct RshBaseType {

	/*!
	* 
	* \~english
	* \brief
	* Size of the data structure or class.
	* 
	* Size in bytes of data structure or class.
	* 
	* \warning
	* Size of complex structures depends on
	* used <b>#pragma pack</b> preprocessor directive.
	* If you change this in your source code,
	* compilled libraries may be not compatible with
	* your program, because most data structure transfer
	* method check this field to determine is structure 
	* corrupted or not.\n
	* 
	* \~russian
	* \brief
	* Размер структуры данных или класса.
	* 
	* Размер в байтах структуры данных или класса.
	* 
	* \warning
	* Размер структур зависит от используемой
	* директивы препроцессора <b>#pragma pack</b>.
	* Если изменить эту директиву в своем коде,
	* скомпилированные ранее
	* библиотеки могут стать несовместимыми с вашей
	* программой, т.к. все методы, в которых передаются
	* структуры данных, используют это поле для проверки 
	* переданной структуры.\n
	*
	*/
	const size_t _typeSize;

	/*!
	* 
	* \~english
	* \brief
	* Data type ID.
	* 
	* One of the RshDataTypes enum constants.
	* This field (and _typeSize field too) is
	* used to determine data type of passed data
	* structure.
	* 
	* \~russian
	* \brief
	* Идентификатор типа данных.
	* 
	* Одна из констант перечисления RshDataTypes.
	* Это поле (наряду с _typeSize) исползуется
	* для определения типа данных переданного объекта
	* в различных методах SDK.
	*
	*/
	const RshDataTypes _type;

	/*!
	* 
	* \~english
	* \brief
	* Constructor
	* 
	* Don't forget to set constructor parameters in
	* initialization list of derived class, otherwise
	* it will have "default" type and size!
	*
	* Default constructor form is only left for compatibility.
	* For example, Q_DECLARE_METATYPE need class to have default constructor.
	*
	* \~russian
	* \brief
	* Конструктор
	* 
	* Не забудьте явно указать параметры конструктора в 
	* списке инициализации производного класса, иначе
	* этот производный класс будет иметь "дефолтный" тип и размер!
	*
	* Дефолтные параметры в конструкторе оставлены для совместимости.
	* Например, Q_DECLARE_METATYPE требует наличия конструктора по умолчанию.
	*
	* 
	*/
	explicit RshBaseType(const RshDataTypes type = rshTypeUndefined, const size_t typeSize = sizeof(RshBaseType));

	//Disabled. More info in class description.
	//virtual ~RshBaseType();

	/*!
	* 
	* \~english
	* \brief
	* Get type name as string literal
	* 
	* \returns
	* Pointer to const char* string with type name.
	* 
	* This method can be used to get type name as 
	* constant char* string. It can be useful for debug
	* or log tasks.
	*
	* \~russian
	* \brief
	* Получение названия типа данных.
	* 
	* \returns
	* Указатель на строку с названием в виде const char*.
	* 
	* Этот метод может быть использован для получения
	* названия типа данных в виде строки (const char*),
	* что может быть удобно для вывода отладочных сообщений
	* или записи в логи.
	* 
	*/
	static const char* GetTypeName(const RshDataTypes typeCode);

	const char* GetTypeName() const;
};

#pragma pack(pop)


#endif//RSH_BASETYPE_H