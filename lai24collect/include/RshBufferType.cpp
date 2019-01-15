/*!
 * \copyright JSC "Rudnev-Shilyaev"
 *
 * \file RshBufferType.h
 * \date 25.12.2015
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
 
#include "RshBufferType.h"
#include "RshConsts_StatusCodes.h"

#include <list>
#include <limits>
#include <algorithm>    // for sort
#include <functional>   // for less & greater
#include <fstream>
#include <ios>

#undef max
#undef min

#if defined(PARTIAL_STL_COMPATIBILITY_ENABLED)

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::iterator RshBufferType<T, dataCode>::begin()
{
	return ptr;
}

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::const_iterator RshBufferType<T, dataCode>::begin() const
{
	return ptr;
}

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::iterator RshBufferType<T, dataCode>::end()
{
	return ptr + m_size;
}

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::const_iterator RshBufferType<T, dataCode>::end() const
{
	return ptr + m_size;
}

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::size_type RshBufferType<T, dataCode>::size() const
{
	return m_size;
}

template <typename T, RshDataTypes dataCode>
typename RshBufferType<T, dataCode>::size_type RshBufferType<T, dataCode>::max_size() const
{
	return m_psize;
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::empty() const
{
	return (m_size == 0);
}

template <typename T, RshDataTypes dataCode>
void RshBufferType<T, dataCode>::swap(RshBufferType<T, dataCode>& obj)
{
	std::swap(this->m_size, obj.m_size);
	std::swap(this->m_psize, obj.m_psize);
	std::swap(this->ptr, obj.ptr);
}
#endif  //PARTIAL_STL_COMPATIBILITY_ENABLED



template <typename T, RshDataTypes dataCode>
	RshBufferType<T, dataCode>::RshBufferType(size_t bufferSize):
	RshBaseType(dataCode, sizeof (RshBufferType<T, dataCode>)),
	m_size(0),
	m_psize(0),
	ptr(nullptr)
	{
		try
		{
			this->ptr = new T[bufferSize];

			m_psize = bufferSize;		
		}
		catch (...)
		{
			m_psize = 0;
			this->ptr = nullptr;
		}
	}

template <typename T, RshDataTypes dataCode>
	RshBufferType<T, dataCode>::RshBufferType(const RshBufferType<T, dataCode>& obj):
	RshBaseType(obj._type, obj._typeSize)
	{
		try
		{
			this->ptr = new T[obj.m_psize];

			m_psize = obj.m_psize;

			Copy(obj);
		}
		catch (...)
		{
			m_psize = 0;
			this->ptr = nullptr;
		}
	}

template <typename T, RshDataTypes dataCode>
RshBufferType<T, dataCode>::~RshBufferType()
{
	if (ptr)
	{
		delete [] ptr;
		ptr = nullptr;
	}
}

template <typename T, RshDataTypes dataCode>
U32 RshBufferType<T, dataCode>::Allocate(size_t bufferSize)
{

	if( bufferSize == 0 ) return RSH_API_BUFFER_ALLOCATIONZEROSIZE;

	if (ptr)
	{
		if( m_psize == bufferSize ) return RSH_API_SUCCESS; //  if requested the same size  then nothing happens
		else
			delete [] ptr;
	}

	m_size = 0;
	this->ptr = nullptr;

	try
	{
		this->ptr = new T[bufferSize];

		m_psize = bufferSize;
		memset(ptr, 0, bufferSize * sizeof (T));
		
	}
	catch (...)
	{
		m_psize = 0;
		this->ptr = nullptr;

		return RSH_API_MEMORY_ALLOCATIONERROR;
	}

	return RSH_API_SUCCESS;
}

template <typename T, RshDataTypes dataCode>
	void RshBufferType<T, dataCode>::Copy(const T* iptr, size_t psize, size_t size)
	{
		size_t copySize;
		if( size == 0 )
		{			
			copySize = m_psize > psize ? psize : m_psize;
			m_size = copySize;
		}
		else
		{
			copySize = m_psize > size ? size : m_psize;
			m_size = copySize;
		}


		for (size_t i = 0; i < copySize; ++i)
			this->ptr[i] = iptr[i];
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::CopyTo(T* iptr, size_t iptrSize) const
	{
		size_t copySize = m_psize > iptrSize ? iptrSize : m_psize;

		for (size_t i = 0; i < copySize; i++)
			iptr[i] = this->ptr[i];

		return copySize;
	}

template <typename T, RshDataTypes dataCode>
	void RshBufferType<T, dataCode>::Copy(const RshBufferType<T, dataCode>& srcBuffer)
	{
		size_t copySize = 0;
		if( srcBuffer.m_size == 0 )
		{
			copySize = m_psize > srcBuffer.m_psize ? srcBuffer.m_psize : m_psize;
			m_size = 0;
		}
		else
		{
			copySize = m_psize > srcBuffer.m_size ? srcBuffer.m_size : m_psize;
			m_size = copySize;
		}		

		for (size_t i = 0; i < copySize; i++)
			this->ptr[i] = srcBuffer.ptr[i];
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::SortAscending()
	{
		if( ptr && (m_psize != 0))
		{
			if( m_size == 0 )
				std::sort(this->ptr + 0, this->ptr + m_psize, std::less<T>());
			else
				std::sort(this->ptr + 0, this->ptr + m_size, std::less<T>());
		}
		else
			return RSH_API_BUFFER_NOTINITIALIZED;

		return RSH_API_SUCCESS;
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::SortDescending()
	{
		if( ptr && (m_psize != 0))
		{
			if( m_size == 0 )
				std::sort(this->ptr + 0, this->ptr + m_psize, std::greater<T>());
			else
				std::sort(this->ptr + 0, this->ptr + m_size, std::greater<T>());
		}
		else
			return RSH_API_BUFFER_NOTINITIALIZED;

		return RSH_API_SUCCESS;
	}

template <typename T, RshDataTypes dataCode>
	void RshBufferType<T, dataCode>::Print(size_t size) const
	{
		std::cout << "Buffer " << "[0x" << std::hex << this << std::dec << "], type: " << this->GetTypeName() << std::endl;
		std::cout << "Psize: " << m_psize <<", Size: " << m_size << std::endl;
		if( this->ptr && (m_psize != 0))
		{
			size_t printSize = 0;
			if(m_size > 0)						 
				printSize = (size > m_size || size == 0) ? m_size : size;

			else
				printSize = (size > m_psize || size == 0) ? m_psize : size;

			std::cout <<"Elements[0 - " << printSize << "]:" << std::endl;

			for(size_t i=0; i<printSize; ++i)
				std::cout << std::setw(6) << i << ": " << this->ptr[i] << std::endl;
		}
		else
			std::cout << std::endl << "Buffer is not initialized!";
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::WriteBufferToFile(const wchar_t* fileName, size_t elements) const
	{
		std::wstring tmp(fileName);
		std::string sFileName = std::string(tmp.begin(), tmp.end());
		return WriteToFile(sFileName.c_str(), elements);
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::WriteBufferToFile(const char* fileName, size_t elements) const
	{
		return WriteToFile(fileName, elements);
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::WriteBufferToFile(const std::string& fileName, size_t elements) const
	{		
		return WriteToFile(fileName.c_str(), elements); 
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::WriteBufferToFile(const std::wstring& fileName, size_t elements) const
	{
		std::string sFileName = std::string(fileName.begin(), fileName.end());
		return WriteToFile(sFileName.c_str(), elements);
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::ReadBufferFromFile(const wchar_t* fileName, size_t elements)
	{
		std::wstring tmp(fileName);
		std::string sFileName = std::string(tmp.begin(), tmp.end());
		return ReadFromFile(sFileName.c_str(), elements);
	}
template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::ReadBufferFromFile(const char* fileName, size_t elements)
	{
		return ReadFromFile(fileName, elements);
	}
template <typename T, RshDataTypes dataCode>	
	U32 RshBufferType<T, dataCode>::ReadBufferFromFile(const std::string& fileName, size_t elements)
	{
		return ReadFromFile(fileName.c_str(), elements); 
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::ReadBufferFromFile(const std::wstring& fileName, size_t elements)
	{
		std::string sFileName = std::string(fileName.begin(), fileName.end());
		return ReadFromFile(sFileName.c_str(), elements);
	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::ReadFromFile(const char* fileName, size_t elements)
	{
		std::ifstream fileStream;

		fileStream.open(fileName, std::fstream::in| std::fstream::binary);

		if(!fileStream.is_open())
			return RSH_API_FILE_CANTOPEN;

		//get file size
		std::streamoff begin = fileStream.tellg();
		//set get position to end of file
		fileStream.seekg(0, std::ios::end);
		std::streamoff end = fileStream.tellg();
		std::streamoff sizeInBytes = end - begin;

		//check if filesize is too big for RshBuffer (max elements is max of size_t)
		std::streamoff realFileSizeInElements = sizeInBytes/sizeof(T);		
		if(realFileSizeInElements > std::numeric_limits<size_t>::max() && elements == 0)
		{
			//return only if we want full file to be read (parameter elements == 0)
			return RSH_API_BUFFER_SIZEISEXCEEDED;
		}

		//file size in limit, its fine to cast it
		size_t fileSizeInElements = static_cast<size_t>(realFileSizeInElements);

		//set get position to begin again 
		fileStream.seekg(0);

		//memory allocation/reallocation
		size_t elementsToRead = 0;
		if(elements == 0)
			elementsToRead = fileSizeInElements;
		else
			elementsToRead = elements;

		if(m_psize<elementsToRead)
		{

			U32 st = Allocate(elementsToRead);
			if(st != RSH_API_SUCCESS)
				return st;
		}

		fileStream.read(reinterpret_cast<char*>(ptr), elementsToRead*sizeof(T));
		if(!fileStream.good())
		{
			fileStream.close();
			return RSH_API_FILE_CANTREAD;
		}

		//set buffer size to number of elements read
		m_size = elementsToRead;

		fileStream.close();
		return RSH_API_SUCCESS;

	}

template <typename T, RshDataTypes dataCode>
	U32 RshBufferType<T, dataCode>::WriteToFile(const char* fileName, size_t elements) const
	{
	
		size_t elementsToWrite = 0;
		if(elements == 0)
		{
			elementsToWrite = m_size >0 ? m_size : m_psize;
		}
		else
		{
			elementsToWrite = elements <= m_psize ? elements: m_psize;
		}

		if(elementsToWrite == 0)
			return RSH_API_BUFFER_ISEMPTY;

		std::ofstream fileStream;
		fileStream.open(fileName, std::fstream::out| std::fstream::binary | std::fstream::trunc);

		if(!fileStream.is_open())
			return RSH_API_FILE_CANTCREATE;

		fileStream.write(reinterpret_cast<const char*>(ptr), elementsToWrite*sizeof(T));
		if(!fileStream.good())
		{
			fileStream.close();
			return RSH_API_FILE_CANTWRITE;
		}
		fileStream.close();
		return RSH_API_SUCCESS;
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::ByteSize() const
	{
		return m_size * sizeof (T);
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::BytePSize() const
	{
		return m_psize * sizeof (T);
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::TypeSize() const
	{
		return sizeof (T);
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::Size() const
	{
		return m_size;
	}

template <typename T, RshDataTypes dataCode>
	size_t RshBufferType<T, dataCode>::PSize() const
	{
		return m_psize;
	}

template <typename T, RshDataTypes dataCode>
	T& RshBufferType<T, dataCode>::operator[](size_t i)
	{
		return ptr[i];
	}

template <typename T, RshDataTypes dataCode>
	const T& RshBufferType<T, dataCode>::operator[](size_t i) const
	{
		return ptr[i];
	}

template <typename T, RshDataTypes dataCode>
	void RshBufferType<T, dataCode>::Clear()
	{
		m_size = 0;
	}

template <typename T, RshDataTypes dataCode>
	void RshBufferType<T, dataCode>::SetSize(size_t size)
	{
		if( size < 0 )
		{
			m_size = 0;
			return;
		}
		if( size > m_psize )
		{
			m_size = m_psize;
			return;
		}

		m_size = size;
	}

template <typename T, RshDataTypes dataCode>
	RshBufferType<T, dataCode>&	RshBufferType<T, dataCode>::operator=(const RshBufferType<T, dataCode>& obj)
	{
		if(this == &obj)
			return *this;
        Allocate(obj.m_psize);
		Copy(obj.ptr, obj.m_psize, obj.m_size);
		return *this;
	}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator==(RshBufferType<T, dataCode>& obj) const
{
	if (m_psize != obj.m_psize)
		return false;
	if (m_size != obj.m_size)
		return false;

	for (size_t i = 0; i < m_size; ++i)
	{
		if (this->ptr[i] != obj.ptr[i])
			return false;
	}
	return true;
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator!=(RshBufferType<T, dataCode>& obj) const
{
	return !( operator==(obj) );
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator<(RshBufferType<T, dataCode>& obj) const
{
	if (m_psize < obj.m_psize)
		return true;
	if (m_size < obj.m_size)
		return true;

	for (size_t i = 0; i < m_size; ++i)
	{
		if (obj.ptr[i] < this->ptr[i])
			return false;
	}
	return true;
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator>(RshBufferType<T, dataCode>& obj) const
{
	return (!operator<(obj) && operator!=(obj) );
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator<=(RshBufferType<T, dataCode>& obj) const
{
	return (operator<(obj) || operator==(obj) );
}

template <typename T, RshDataTypes dataCode>
bool RshBufferType<T, dataCode>::operator>=(RshBufferType<T, dataCode>& obj) const
{
	return !operator<(obj);
}

template <typename T, RshDataTypes dataCode>
U32 RshBufferType<T, dataCode>::PushBack(T obj)
{
	if( m_psize == m_size )
		return RSH_API_BUFFER_INSUFFICIENTSIZE;

	ptr[m_size++] = obj;

	return RSH_API_SUCCESS;
}
	
//Template instantiation
template class RshBufferType< U8    , rshBufferTypeU8>;
template class RshBufferType< S8    , rshBufferTypeS8>;
template class RshBufferType< U16   , rshBufferTypeU16>;
template class RshBufferType< S16   , rshBufferTypeS16>;
template class RshBufferType< U32   , rshBufferTypeU32>;
template class RshBufferType< S32   , rshBufferTypeS32>;
template class RshBufferType< U64   , rshBufferTypeU64>;
template class RshBufferType< S64   , rshBufferTypeS64>;
template class RshBufferType< float , rshBufferTypeFloat>;
template class RshBufferType< double, rshBufferTypeDouble>;
template class RshBufferType< bool  , rshBufferTypeBool>;
template class RshBufferType< U8*   , rshBufferTypeU8P>;

template class RshBufferType< RshBaseType*, rshBufferTypeBaseP>;
