#pragma once
#include "Heaps.h"
#include <iostream>
using namespace std;


template<class ItemType>
class PQType
{
		public:
			PQType(int);          						// parameterized class constructor
			~PQType();							       // class destructor
			void MakeEmpty();
			bool IsEmpty() const;
			bool IsFull() const;
			void Enqueue(ItemType newItem);
			void Dequeue(ItemType& item);
			void Print();

		
		private:
			int numItems;
			HeapType<ItemType> items;
			int maxItems;
};

//Constructor
template<class ItemType>
PQType<ItemType>::PQType(int max)
{
	maxItems = max;
	items.elements = new ItemType[max];
	numItems = 0;
}

//Destructor
template<class ItemType>
PQType<ItemType>::~PQType()
{
	delete[] items.elements;
}

//Empty contents of queue
template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
	numItems = 0;
}

//Checks if the queue is empty
template<class ItemType>
bool PQType<ItemType>::IsEmpty() const

{
	return numItems == 0;
}


//Checks if the queue is full
template<class ItemType>
bool PQType<ItemType>::IsFull() const

{
	return numItems == maxItems;
}


//Add item to queue
template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)

{
	numItems++;
	items.elements[numItems - 1] = newItem;
	items.ReheapUp(0, numItems - 1);
	items.ReheapDown(0, numItems - 1);
}


//Remove item to queue - one with the highest priority
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)

{
	item = items.elements[0];
	items.elements[0] = items.elements[numItems - 1];
	numItems--;
	items.ReheapDown(0, numItems - 1);
	items.ReheapUp(0, numItems - 1);
}

template <class ItemType>
void PQType<ItemType>::Print() {
	for (int i = 0; i <= numItems - 1; i++) {
		cout << items.elements[i].name <<"\t " 
			<< items.elements[i].priority 
			<< endl;
	}
	
}

