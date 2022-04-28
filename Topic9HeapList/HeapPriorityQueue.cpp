#include "HeapPriorityQueue.h"

template<class ItemType>
HeapPriorityQueue <ItemType>::HeapPriorityQueue()
{
	ArrayMaxHeap<ItemType>();
}//end constructor

template<class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}//end add

template<class ItemType>
bool HeapPriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
} //end add

template<class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
	return ArrayMaxHeap<ItemType>::remove();
}//end remove

template<class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	try
	{
		return ArrayMaxHeap<ItemType>::peekTop();
	}
	catch (PrecondViolatedExcept e)
	{
		throw PrecondViolatedExcept("Attempted peek into an emptry priority queue.");
	}//end try/catch
} //end peekFront