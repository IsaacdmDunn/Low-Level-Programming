#include "HeapManager.h"

std::unordered_map <std::string, Heap*> HeapManager::heapMap;
Heap HeapManager::defaultHeap = Heap("Default Heap");

Heap* HeapManager::CreateHeap(std::string name)
{
	//std::string heapName = name;
	Heap* heap = new Heap(name);
	heapMap.insert(std::make_pair(name, heap));
	return heap;
}

Heap* HeapManager::GetHeap(std::string name)
{
	return heapMap[name];
}

void HeapManager::CleanHeaps()
{
	heapMap.clear();
}

Heap& HeapManager::GetDefaultHeap()
{
	return defaultHeap;
}
