#pragma once

struct Chunk {
	
	Chunk* next;
};



class memoryPool
{
public:
	memoryPool(size_t chunksPerBlock)
	{
		mChunksPerBlock = chunksPerBlock;
	}

	void* allocate(size_t size);
	void deallocate(void* ptr, size_t size);

private:
	size_t mChunksPerBlock;
	Chunk* chunk = nullptr;
	Chunk* allocateBlock(size_t chunkSize);
};

