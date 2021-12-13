#pragma once
#include "Heap.h"
#include "HeapManager.h"

struct AllocHeader {
	Heap* pHeap;
	int nSize;
	AllocHeader* previous = NULL;
	AllocHeader* next = NULL;
};

class memoryManager
{
public:
	static void* operator new(size_t size, Heap* pHeap);
	static void* operator new(size_t size);
	static void operator delete(void* pMem);


private:

};
