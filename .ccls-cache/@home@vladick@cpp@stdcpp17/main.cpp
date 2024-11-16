#include "list.hpp"
#include "vector.hpp"
#include "string.hpp"
#include <iostream>
#include <cstdint>
#include "hash.h"

int
main (void) {
/*
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
*/

	unordered_map mapa;

	char* guba = "gubami";
	char* gol  = "keng";
	char* porn = "anal";
	char* onyame = "penis";

	vaddPair(mapa, 4, (void*)guba, (void*)gol, (void*)porn, (void*)onyame);
	
	std::cout << (char*)getVal(mapa, guba) << " " << (char*)getVal(mapa, porn) << "\n";

}
