#pragma once

class memoryManager
{
public:
	static void* operator new(size_t size);
	static void operator delete(void* p, size_t size);


private:

};
