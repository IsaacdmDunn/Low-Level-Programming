#include "memoryPool.h"
#include <iostream>

memoryPool::memoryPool(size_t chunksPerBlock)
{
	mChunksPerBlock = chunksPerBlock;
}

Chunk* memoryPool::allocateBlock(size_t size)
{
	std::cout << "Allocating new block with " << mChunksPerBlock << " chunks." << std::endl;

	size_t blockSize = mChunksPerBlock * size;
	Chunk* blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));
	Chunk* chunk = blockBegin;

	for (int i = 0; i < mChunksPerBlock - 1; i++) {
		chunk->mNext = reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + size);
		chunk = chunk->mNext;
	}

	chunk->mNext = nullptr;

	return blockBegin;
}

void* memoryPool::allocate(size_t size)
{
	if (chunk == nullptr) 
	{
		chunk = allocateBlock(size);
	}
	Chunk* freeChunk = chunk;
	chunk = chunk->mNext;

	return freeChunk;
}

void memoryPool::deallocate(void* ptr, size_t size)
{
	std::cout << "Deallocating block with " << mChunksPerBlock << " chunks." << std::endl;
	reinterpret_cast<Chunk*>(ptr)->mNext = chunk;
	chunk = reinterpret_cast<Chunk*>(ptr);
}



