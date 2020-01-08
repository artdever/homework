#pragma once

template <class T>
class DynmicArray {

public:
	DynmicArray(int size = 0);
	~DynmicArray();
	//DynmicArray& operator()( DynmicArray&);
	DynmicArray(const DynmicArray<T>& obj);
	DynmicArray(DynmicArray<T>&& obj);
	DynmicArray& operator=(DynmicArray<T>&);
	DynmicArray& operator=(DynmicArray<T>&&);

	T* operator[](int n);
private:
	int size;
	int capacity;
	T* array;
	T* head;
};

#include <iostream>



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
	capacity = obj.capacity;
	size = obj.size;
	array = new T[capacity];
	head = array;
	for (int i=0;  i < capacity ; i++)
	{
		*(array + i) = *(obj.array + i);
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
	if (this->capacity >= obj.capacity)
	{
		capacity = obj.capacity;
		size = obj.size;
		array = new T[capacity];
		head = array;
		for (int i = 0; i < capacity; i++)
		{
			*(array + i) = *(obj.array + i);
		}
	}
	else
	{
		std::cout << "error capacity is large";
	}
	return *this;
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

//void TemporaryFunction()
//{
//	DynmicArray<int> TempObj;
//}
