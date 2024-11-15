#ifndef __VECTOR_H
#define __VECTOR_H

#include "iterator.hpp"

namespace m34 {
template <class T> void swap(T &first, T &second) {
    T tmp = first;
    first = second;
    second = tmp;
}

template <class T> class vector {
private:
    T *buffer;
    unsigned int size;
    unsigned int putchar = 0;

public:
    vector(unsigned int value) : size(value)
	{
        buffer = new T[value * sizeof(T)]();
    }

	vector(unsigned int value, const T&& element) : size(value)
	{
		buffer = new T[value * sizeof(T)];

		for(unsigned int i = 0; i < size; ++i)
		{
			buffer[i] = element;
		}
	}

    ~vector() { delete[] buffer; }

	unsigned int length()
	{
		return this->size;
	}

	void resize(unsigned int newSize)
	{
		T* newBuffer = new T[newSize * sizeof(T)];
		for(unsigned int i = 0; i < size; ++i)
		{
			newBuffer[i] = buffer[i];
		}	
		delete[] buffer;	
		buffer = newBuffer;
		size = newSize;
	}

    void add(unsigned int value) 
	{
		if(putchar >= size)
		{
			this->resize(size*2);	
		}
        buffer[putchar] = value;
        ++putchar;
    }

    T &operator[](unsigned int index) {
        if (index > putchar)
            putchar = index;
        return buffer[index];
    }

    T &operator=(T other) {
        swap(buffer, other.buffer);
        return *this;
    }

	class iterator
	{
		T* pointer;		
	public:
		iterator(T* ptr) : pointer(ptr) {}
		
		T& operator*() 
		{
			return *pointer;
		}

		iterator& operator++()
		{
			++pointer;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp = *this;
			operator++();			
			return tmp;
		}

		iterator& operator+=(unsigned int value)
		{
			pointer = pointer + value;
			return *this;
		}

		iterator& operator+(unsigned int value)
		{
			pointer = pointer + value;
			return *this;
		}

		iterator& operator--()
		{
			--pointer;
			return *this;
		}
		
		iterator& operator--(int)
		{
			iterator tmp = *this;
			operator--();
			return tmp;
		}

		iterator& operator-=(unsigned int value)
		{
			pointer = pointer - value;
			return *this;
		}
		
		iterator& operator-(unsigned int value)
		{
			pointer = pointer - value;
			return *this;
		}

		friend bool operator==(const iterator& lhs, const iterator& rhs)
		{
			return lhs.pointer == rhs.pointer;	
		}

		friend bool operator!=(const iterator& lhs, const iterator& rhs)
		{
			return !(lhs.pointer == rhs.pointer);
		}

	};

	iterator begin()
	{
		return iterator(&(buffer[0]));
	}	

	iterator end()
	{
		return iterator(&(buffer[size]));
	}


};
} // namespace m34

#endif
