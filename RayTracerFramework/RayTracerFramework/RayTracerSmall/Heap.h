#pragma once

#define NAMELENGTH 20
#include <iostream>

struct AllocHeader;

class Heap
{
public:
	Heap(std::string name);
	const char* GetName() const;

	void allocate(size_t size, AllocHeader* header);
	void showAllocatedMemory();
	void free(size_t size, AllocHeader * header);

	AllocHeader* head = NULL;
private:
	std::string m_Name;
	unsigned allocated = 0;
};
