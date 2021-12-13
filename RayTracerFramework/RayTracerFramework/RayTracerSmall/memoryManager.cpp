#include "memoryManager.h"
#include <iostream>

void* operator new(size_t size, Heap* pHeap)
{
	size_t nRequestedBytes = size + sizeof(AllocHeader);
	char* pMem = (char*)malloc(nRequestedBytes);
	AllocHeader* pHeader = (AllocHeader*)pMem;
	pHeader->pHeap = pHeap;
	pHeader->nSize = size;

	pHeap->allocate(pHeader->nSize, pHeader);
	void* pStartMemBlock = pMem + sizeof(AllocHeader);
	
	return pStartMemBlock;
}

void* operator new(size_t size)
{
	return ::operator new(size, &HeapManager::GetDefaultHeap());
}

void operator delete(void* pMem)
{
	AllocHeader* pHeader = (AllocHeader*)((char*)pMem - sizeof(AllocHeader));
	pHeader->pHeap->free(pHeader->nSize, pHeader);
	free(pHeader);
}
