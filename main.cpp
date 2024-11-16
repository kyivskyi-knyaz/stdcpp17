#include "list.hpp"
#include "vector.hpp"
#include "string.hpp"
#include <iostream>

int
main (void) {
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

	
	char* gubami = "an";
	m34::String<2> pivo(gubami); 
    m34::vector<m34::String<2>> vec(1);

	char* nogami = "al";
	m34::String<2> vod(nogami);


	vec.add(pivo);
	vec.add(pivo);
	vec.push_back(vod);	

	for(auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << (*it).c_str() << "\n";	
	}

	std::cout << "\nCurrent length: " << vec.length() << "\n";
}
