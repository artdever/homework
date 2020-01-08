#include <iostream>

class myClass {

public:
	myClass(int n = 0) :x(n) {};
	int& operator++(int n)
	{
		int temp = this->x;
		temp += 1;
		x = temp;
		std::cout << x;
		return x;
		
	}
	int operator++()
	{
		this->x += 1;
		std::cout << x;
		return this->x;
	}

private:
	int x;
};
int main() {
	myClass a;
	++a;
	a++;
	return 0;
}

