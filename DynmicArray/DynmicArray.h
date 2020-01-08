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