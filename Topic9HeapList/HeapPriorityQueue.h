#pragma once
#include "ArrayMaxHeap.h"
#include "PrecondViolatedExcept.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType>
{
	HeapPriorityQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	ItemType peekFront() const throw(PrecondViolatedExcept);
};

