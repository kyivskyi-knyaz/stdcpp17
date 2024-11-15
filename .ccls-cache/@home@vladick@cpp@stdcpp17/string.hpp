#ifndef __STRING_H
#define __STRING_H
#include "IO.hpp"

namespace m34 {
template <ssize_t Size> class String {
  private:
    char buffer[Size];
  public:
	String() 
	{
		for(int i = 0; i < Size; ++i)
		{
			this->buffer[i] = 0;
		}
	}

	String(char buffer[])
	{
		for(int i = 0; i < Size; ++i)
		{
			this->buffer[i] = buffer[i];
		}
	}
	
	void operator=(String &other) 
	{
		for(int i = 0; i < Size; ++i)
		{
			this->buffer[i] = other.buffer[i];
		}
	}

    char operator[](int i) { return buffer[i]; }

    ssize_t getSize(String string) { return Size; }

    const char* c_str() { return buffer; }

};
} // namespace m34

#endif
