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
	try
	{
		allocated += size;
		header->checkVal = 0xDEADC0DE;
		header->nSize = size;
		header->previous = NULL;
		header->next = head;
		if (head != NULL)
		{
			head->previous = header;
		}
		head = header;
	}
	catch (std::exception e)
	{
		std::cout << "exception thrown." << std::endl;
		throw;
	}
	
}

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

void Heap::DebugHeap()
{
	std::cout << "Checking integrity of " << m_Name << std::endl;

	unsigned int errorCount = 0;

	if (head != NULL) {
		AllocHeader* pCurrent = head;

		while (pCurrent != NULL) {
			if (pCurrent->checkVal != 0xDEADC0DE) {
				std::cout << "Error mismatch header check code" << std::endl;
				errorCount++;
			}

			void* pFooterAddr = ((char*)pCurrent + sizeof(AllocHeader) + pCurrent->nSize);
			Footer* pFooter = (Footer*)pFooterAddr;
			if (pFooter->checkVal != 0xDEADC0DE) {
				std::cout << "Error mismatch footer check code" << std::endl;
				errorCount++;
			}

			pCurrent = pCurrent->next;
		}
	}

	std::cout << "Errors in " << m_Name << ": " << errorCount << std::endl;
}
