#include"ObjectCount.h"

int main() {
	{
		ObjectCount a1;
		ObjectCount a2;
		a1.printCount();
		a2.printCount();
	}
	ObjectCount a3;
	ObjectCount a4(a3);
	a3.printCount();

	return 0;
}