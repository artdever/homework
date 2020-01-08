#pragma once

class DynamicArray {

public:
	DynamicArray();
	void allocate(void*);
	void deallocate(void*);
	void malloc(void*);
	void free();
	bool empty();

private:
	void* mem;
};