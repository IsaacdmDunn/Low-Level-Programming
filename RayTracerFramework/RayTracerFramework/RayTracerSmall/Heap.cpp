#include "Heap.h"
#include "memoryManager.h"

Heap::Heap(std::string name)
{
	m_Name = name;
}

const char* Heap::GetName() const
{
	return nullptr;
}

void Heap::allocate(size_t size, AllocHeader* header)
{
	
	allocated += size;
	header->nSize = size;
	header->previous = NULL;
	header->next = head;
	if (head != NULL)
	{
		head->previous = header;
	}
	head = header;
}

//fix mem leak
void Heap::showAllocatedMemory(std::string name)
{
	if (head != NULL)
	{


		std::cout << name << " allocated with:" << allocated << std::endl;

		AllocHeader* current = head;
		while (current != NULL)
		{
			if (current == NULL) break;
			std::cout << "Address: " << current << "   Size: " << current->nSize << std::endl;
			if (current->next == NULL) { break; }
			current = current->next;
		}
	}
}

void Heap::free(size_t size, AllocHeader * header)
{
	allocated -= size;

	if (head == header)
	{
		head = header->next;
	}
	if (header->next != NULL)
	{
		header->next->previous = header->previous;
	}
	if (header->previous != NULL)
	{
		header->previous->next = header->next;
	}
}
