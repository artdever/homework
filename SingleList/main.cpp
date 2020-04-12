#include"SingleList.h"
#include<iostream>

int main() {


	SingleList<int> a;

	SingleList<int> c{1,2,3,4};
	SingleList<int> d{ };

	a.insert(1, 111);
	a.insert(2, 222);
	a.insert(2, 333);
	a.insert(3, 444);
	a.insert(5, 555);
	a.insert(5, 77);
	SingleList<int>::iterator i3 = a.begin();
	a.insert(3, 666);
	a.pop_front();
	a.pop_back();
	a.erase(3);
	a.erase(2);

	SingleList<int> b;
	SingleList<int>::iterator f = b.begin();
	b.insert(f, 999);
	b.insert(f, 888);

	b.insert(1, 111);
	b.insert(2, 222);
	b.insert(2, 333);
	b.insert(3, 444);
	b.insert(5, 555);
	b.insert(5, 77);

	
	SingleList<int>::iterator k = b.begin();
	k++;
	++k;

	b.erase(k);//erase iterator

	b.insert(k, 888); //insert iterator

	//b.insert(3, 666);
	//b.pop_front();
	//b.pop_back();
	//b.erase(3);
	//b.erase(2);

	if (a.front() == b.front())
		std::cout << "True first element ==" << std::endl;
	else
		std::cout << "false first element ==" << std::endl;

	if (a == b)
		std::cout << "True ==" << std::endl;
	else
		std::cout << "false ==" << std::endl;

	

	SingleList<int>::iterator i = a.begin();
	SingleList<int>::iterator j = a.begin();
	if (i == j)
		std::cout << "True" << std::endl;
	else
		std::cout << "false" << std::endl;
	SingleList<int>::iterator i1 = ++i;
	SingleList<int>::iterator i2 = i++;
	if (i1 != i2)
		std::cout << "True" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (j != i3)
		std::cout << "True" << std::endl;
	else
		std::cout << "false" << std::endl;



	return 0;
}