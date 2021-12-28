#pragma once
#include "Heap.h"
#include "HeapManager.h"

struct AllocHeader {
	Heap* pHeap;
	int nSize;
	AllocHeader* previous = NULL;
	AllocHeader* next = NULL;
};

	void* operator new(size_t size, Heap* pHeap);
	void* operator new(size_t size);
	void operator delete(void* pMem);

