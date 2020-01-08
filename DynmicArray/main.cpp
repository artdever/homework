#include"DynmicArray.h"

int main() {
	DynmicArray<int> a0;
	DynmicArray<int>* a1 = new DynmicArray<int>(1);
	DynmicArray<int> a2(2);
	DynmicArray<int>* a3 = new DynmicArray<int>(3);
	DynmicArray<int> a4(4);
	DynmicArray<int> a5(5);
	DynmicArray<int> a6(6);
	//DynmicArray<int> a7(a6);
	
	a4.operator=(a2);
	
	


	return 0;
}