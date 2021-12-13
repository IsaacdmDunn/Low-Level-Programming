#pragma once

#include <unordered_map>
#include "Heap.h"

class HeapManager {
public:
	static Heap* CreateHeap(std::string name);
	static Heap* GetHeap(std::string name);
	static void CleanHeaps();
	static Heap& GetDefaultHeap();


private:
	static std::unordered_map <std::string, Heap*> heapMap;
	static Heap defaultHeap;
};