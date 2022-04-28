#pragma once
//Dan Blakeman
//CIS 2207-502
//04-04-2022
//Implement a to-do list using the class HeapPriorityQueue

#include <memory>
#include "HeapInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
	const int ROOT_INDEX = 0;
	static const int DEFAULT_CAPACITY = 21;
	ItemType items[21];
	int itemCount;
	int maxItems;

	int getLeftChildIndex(const int nodeIndex);
	int getRightChildIndex(int nodeIndex) const;
	int getParentIndex(int nodeIndex) const;
	bool isLeaf(int nodeIndex) const;
	void heapRebuild(int nodeIndex);
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);
	virtual ~ArrayMaxHeap();

	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const throw(PrecondViolatedExcept);
	bool add(const ItemType& newData);
	bool remove();
	void clear();
};

