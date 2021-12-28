#pragma once
#include "Heap.h"
#include "HeapManager.h"

struct AllocHeader {
	Heap* pHeap;
	int nSize;
	AllocHeader* previous = NULL;
	AllocHeader* next = NULL;
	int checkVal = 0xDEADC0DE;
};

struct Footer {
	int reserved;

	int checkVal = 0xDEADC0DE;
};

	void* operator new(size_t size, Heap* pHeap);
	void* operator new(size_t size);
	void operator delete(void* pMem);

