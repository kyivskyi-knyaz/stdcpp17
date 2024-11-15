#ifndef __STD__ITERATOR_H
#define __STD__ITERATOR_H

namespace m34 
{
	template<class T>
	class iterator 
	{
		T* pointer;

		
		
	};

	template<class T>
	class forwardIterator : public iterator<T>
	{

	};

	template<class T>
	class backwardIterator : public forwardIterator<T>
	{

	};
}

#endif
