#include "ArrayMaxHeap.h"

template<class ItemType>
inline int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex)
{
	return (2 * nodeIndex) + 1;
}// end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
	return (2 * nodeIndex) + 2;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
	if (nodeIndex == NULL) {
		return true;
	}
	else {
		return false;
	}
	
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int nodeIndex)
{
	int largerChildIndex = 0;
	largerChildIndex = getLeftChildIndex(nodeIndex); //Assume right child exists and is the larger

	//Check whether right child exists; if so, is left child larger?
	//If no right child, left one is larger
	if ((largerChildIndex >= itemCount) || (items[getLeftChildIndex(nodeIndex)] > items[getRightChildIndex(nodeIndex)]))
		largerChildIndex = getLeftChildIndex(nodeIndex); //Assumption was wrong


	if (items[nodeIndex] < items[largerChildIndex]) { //Swap index with larger child index
		ItemType temp = items[nodeIndex];
		items[nodeIndex] = items[largerChildIndex];
		items[largerChildIndex] = temp;
	}
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2 - 1; index < 0; index--)
	{
		//Assertion: The tree rooted at index is a semiheap
		heapRebuild(index);
		//Assertion: The tree rooted at index is a heap
	}
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{
	int itemCount = 0;
	int maxItems = 5;
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{  
	//Copy given values into the array
	for (int i = 0; i < itemCount; i++)
		items[i] = someArray[i];

	//Reorganize the array into a heap
	heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	if (itemCount == 0)
		return true;
	else return false;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	return floor(log2(itemCount)) + 1;
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcept)
{
	return items[0];
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
	items[itemCount] = newData;

	//Make new item bubble up to the appropriate spot in tree
	int newDataIndex = itemCount;
	bool inPlace = false;
	while ((newDataIndex >= 0) && !inPlace)
	{
		int parentIndex = getParentIndex(newDataIndex);
		if (items[newDataIndex] <= items[parentIndex])
			inPlace = true; // The data is in the correct place in the tree
		else
		{
			//Swap parent index and new data index
			ItemType temp = items[newDataIndex];
			items[newDataIndex] = items[parentIndex];
			items[parentIndex] = temp;
			newDataIndex = parentIndex;
		}
	}
	itemCount++;
	return inPlace;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	items[0] = items[itemCount - 1]; //Copy the item from the last node into the root
	itemCount--; //remove the last node
	heapRebuild(0);
	return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount == 0;
}
