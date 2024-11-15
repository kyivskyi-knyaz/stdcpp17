#include "list.hpp"
#include "vector.hpp"
#include <iostream>

int
main (void) {
    int a = 7;
    m34::Node<int> *root = m34::Node<int>::CreateNode(a);
    root->next = m34::Node<int>::CreateNode(10);
    root->next->next = m34::Node<int>::CreateNode(17);
    root->next->next->next = nullptr;
    /*root->next = m34::Node<int>::CreateNode(b);
    root->next->next = m34::Node<int>::CreateNode(c);
    */
    /*nm34::iterators::Iterator<m34::Node<int>> beg = root->begin();
    auto it = *beg;

    std::cout << it.data;*/
    /*
    m34::iterators::Iterator<m34::Node<int>> beg = root->begin();
    m34::iterators::Iterator<m34::Node<int>> end = root->end();
    auto it = beg;
    while(it != end)
      {
          std::cout << it.pointer->data << std::endl;
          ++it;
      }
    */ //deprecated iterator
    /*fake v;

      v.f<int>();*/ /* m34::iterators::Iterator<T> * operator don't work with data structures    in which name of field is not 'date'

pls. Check fake.cpp */
    //std::cout << it << std::endl;

    m34::vector<int> vec(2);

	vec.add(1);
	vec.add(2);
	vec.add(3);
	vec.add(4);
	vec.add(5);
    vec.add(6);
    vec.add(7);
    vec.add(8);


	for(auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";	
	}

	std::cout << "\nCurrent length: " << vec.length() << "\n";
}
