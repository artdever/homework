#include <iostream>
#include "DynmicArray.h"



template <class T>
DynmicArray<T>::DynmicArray(int size):capacity(size){
	array = new T[size];
	head = array;
	this->size = 0;
}

template <class T>
DynmicArray<T>::~DynmicArray() {
	array = head;
	int i = capacity;
	while (i--) {
		delete array;
		array++;
	}
}

//template <class T>
//DynmicArray<T>& DynmicArray<T>::operator()( DynmicArray& obj) {
//	for (int i = 0; i < capacity; i++)
//	{
//		*this + i = obj.array + i;
//	}
//}

template <class T>
DynmicArray<T>::DynmicArray(const DynmicArray<T>& obj) {
	for (int i=0;  i < capacity ; i++)
	{
		*this+i = obj.array + i;
	}
}

template <class T>
DynmicArray<T>::DynmicArray(DynmicArray<T>&& obj) {
	if (*this == obj)
		return;
	*this = obj;
}

template <class T>
DynmicArray<T>& DynmicArray<T>::operator=(DynmicArray<T>& obj) {
	if(this->capacity >= obj.capacity)
	for (int i = 0; i < capacity; i++)
	{
		*this + i = obj + i;
	}
	else
	{
		std::cout << "error capacity is large";
	}
}

template <class T>
DynmicArray<T>& DynmicArray<T>::operator=(DynmicArray<T>&& obj) {
	if (*this == obj)
		return;
	*this = obj;
}

template <class T>
T* DynmicArray<T>::operator[](int n) {
	if (n <= capacity)
		return *this->head + n;
	else
		std::cout << " Number is large";
}

void TemporaryFunction()
{
	DynmicArray<int> TempObj;
}