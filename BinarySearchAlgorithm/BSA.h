#pragma once

bool BSA(int* array, const int size, const int& val) {

	if (size == 0)
		return false;
	if (val == array[size / 2])
		return true;
	if (val < array[size / 2])
		return	BSA(array, size / 2, val);
	if (val > array[size / 2])
		return	BSA(array + size / 2  , 1 + size / 2, val);
	return false;
}