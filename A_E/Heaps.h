#pragma once
#include <iostream>


template<class ItemType>


struct HeapType
{
	void ReheapDown(int root, int bottom);
	void Swap(ItemType& x, ItemType& y);
	void ReheapUp(int root, int bottom);
	ItemType* elements; 						// Array to be allocated dynamically
	int numElements;
};

template<class ItemType>			     
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::Swap(ItemType& x, ItemType& y) {

	ItemType z(x);
	x = y;
	y = z;
}

template<class ItemType>			    
void HeapType<ItemType>::ReheapUp(int root, int bottom)

{
	int parent;
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			Swap(elements[parent],elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}




