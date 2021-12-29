#include "memoryPool.h"
#include <corecrt_malloc.h>
#include <iostream>

void* memoryPool::allocate(size_t size)
{
	if (chunk == nullptr) {
		chunk = allocateBlock(size);
	}
	Chunk* freeChunk = chunk;

	chunk = chunk->next;

	return freeChunk;
}

void memoryPool::deallocate(void* ptr, size_t size)
{
	reinterpret_cast<Chunk*>(ptr)->next = chunk;

	// And the allocation pointer is now set
	// to the returned (free) chunk:

	chunk = reinterpret_cast<Chunk*>(ptr);
}

Chunk* memoryPool::allocateBlock(size_t chunkSize)
{
	std::cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";

	size_t blockSize = mChunksPerBlock * chunkSize;

	// The first chunk of the new block.
	Chunk* blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));

	// Once the block is allocated, we need to chain all
	// the chunks in this block:

	Chunk* chunk = blockBegin;

	for (int i = 0; i < mChunksPerBlock - 1; ++i) {
		chunk->next =
			reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
		chunk = chunk->next;
	}

	chunk->next = nullptr;

	return blockBegin;
}

