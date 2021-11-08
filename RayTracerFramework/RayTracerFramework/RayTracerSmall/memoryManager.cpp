#include "memoryManager.h"
#include <iostream>

void* memoryManager::operator new(size_t size)
{
    std::cerr << "allocating " << size << " bytes\n";
    void* mem = malloc(size);
    if (mem)
        return mem;
    else
        throw std::bad_alloc();
}

void memoryManager::operator delete(void* p, size_t size)
{
    cerr << "deallocating at " << ptr << endl;
    free(ptr);
}
