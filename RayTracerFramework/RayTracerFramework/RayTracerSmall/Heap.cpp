#include "Heap.h"

Heap::Heap(std::string name)
{
	m_Name = name;
}

const char* Heap::GetName() const
{
	return nullptr;
}

void Heap::allocate(size_t size)
{
	allocated += size;
}

void Heap::showAllocatedMemory()
{
	std::cout << allocated << std::endl;
}

void Heap::free(size_t size)
{
	allocated -= size;
}
