#pragma once


struct Chunk {
	
	Chunk* mNext;
};

class memoryPool
{
public:
	memoryPool(size_t chunksPerBlock);


	void* allocate(size_t size);
	void deallocate(void* pMem, size_t size);

private:
	size_t mChunksPerBlock;
	Chunk* chunk;
	Chunk* allocateBlock(size_t size);
};

