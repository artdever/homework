#include <iostream>
#include "BSA.h"
int main() {

	int array[] = { 1,2,3,4,6,8,9,15,34,79,444,3664 };

	if (BSA(array,12,1))
		std::cout << "true";
	else
		std::cout << "false";

	return 0;
}