#pragma once

#define NAMELENGTH 20
#include <iostream>
#include "memoryManager.h"

class Heap
{
public:
	Heap(std::string name);
	const char* GetName() const;

	void allocate(size_t size);
	void showAllocatedMemory();
	void free(size_t size);

	AllocHeader head = NULL;
private:
	std::string m_Name;
	unsigned allocated = 0;
};
