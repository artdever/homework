#include "ObjectCount.h"
#include <iostream>

ObjectCount::ObjectCount() {
	count++;
}

ObjectCount::~ObjectCount() {
	count--;
}

ObjectCount::ObjectCount(const ObjectCount& obj) {
	*this = obj;
	count++;
}

void ObjectCount::printCount() {
	std::cout << count<< "\n";
}

int ObjectCount::count = 0;