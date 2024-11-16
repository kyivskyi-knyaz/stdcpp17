#ifndef __HASH_H
#define __HASH_H

#include <stdint.h> 
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

size_t hash(const void* key) {
   
	size_t ptr_value = (size_t)key;

    ptr_value ^= (ptr_value >> 33);
    ptr_value *= 0xff51afd7ed558ccd;
    ptr_value ^= (ptr_value >> 33);
    ptr_value *= 0xc4ceb9fe1a85ec53;
    ptr_value ^= (ptr_value >> 33);

    return ptr_value;
}

struct pair 
{
	void* Key;
	void* Value;
};
typedef struct pair pair;

struct unordered_map 
{
	struct pair buffer[100];
};
typedef struct unordered_map unordered_map;

void addPair(unordered_map& map, void* key, void* value)
{
	uint32_t index = hash(key) % 100;
	map.buffer[index].Key = key;
	map.buffer[index].Value = value;
}

void vaddPair(unordered_map& map, int count, ...)
{
	va_list pairs;
	va_start(pairs, count);

	for(int i = 0; i < count; ++i)
	{
		void* key = va_arg(pairs, void*);
		uint32_t index = hash(key) % 100;
		map.buffer[index].Key = key;
		map.buffer[index].Value = va_arg(pairs, void*);
	}

	va_end(pairs);
}

pair at(unordered_map& map, void* key)
{
	return map.buffer[hash(key) % 99]; 
}

void* getVal(unordered_map& map, void* key)
{
	return map.buffer[hash(key) % 100].Value;
}
#endif
