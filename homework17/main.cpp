/*
// If an element is 0, set row and column to 0
#include <iostream>
#include <vector>

void matrix(int**, int, int);

int main() {

	int n = 4;
	int m = 5; // imput matrix length MxN
	// create Matrix
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	//assign matrix
	for (int i = 0, k = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 1;
	//Assign matrix element to 0
	arr[2][3] = 0;
	arr[3][2] = 0;
	//arr[1][1] = 0;

	// print matrix
	for (int i = 0; i < n; i++) {
		std::cout << '\n';
		for (int j = 0; j < m; j++)
			std::cout << arr[i][j] << " ";
	}
	std::cout << '\n' << '\n';

	matrix(arr, n, m); // Function call

	// delete matrix
	for (int i = 0; i < n; ++i)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

void matrix(int** matrix, int n, int m) {
	
	struct Pair { 
		Pair(int i, int j) :i(i), j(j) {};
		int i, j;
	};

	std::vector<Pair*> vec;

	//add in vector coordinant 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0)
				vec.push_back(new Pair(i, j));
		}
	}
	//set 0 column and ruw
	for (int v = 0; v < vec.size(); v++)
	{
		for (int i = 0; i < m; i++)
			matrix[vec[v]->i][i] = 0;
		for (int i = 0; i < n; i++)
			matrix[i][vec[v]->j] = 0;
	}

	
	// print result
	for (int i = 0; i < n; i++) {
		std::cout << '\n';
		for (int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
	}
	std::cout << '\n' << '\n';

}
*/

// If an element is 0, set row and column to 0
#include <iostream>
#include <string>

std::string add(const std::string, const std::string);

int main() {
	std::string a("11");
	std::string b("1111");

	std::string val = add(a, b);
	std::cout << val << std::endl;
	return 0;
}

std::string add(const std::string a, const std::string b) {
	std::string min,max;
	if (a.size() > b.size())
	{
		max =a ;
		min = b;
	}
	else {
		max = b;
		min = a;
	}

	char* arr = new char[max.size() + 1]{0};
	arr[max.size() + 1] = '\0';

	int mnacord = 0;
	for (int  m_size = max .size(), n_size = min.size(); m_size ; m_size--)
	{
		
		
		if (max[m_size - 1] -48)
			if (n_size != 0 && min[n_size-1]-48)
			{
				arr[m_size] = mnacord+48;
				mnacord = 1;
			}
			else
			{
				if(mnacord==0)
				arr[m_size] = '1';
				else
				{
				arr[m_size] = '0';
				mnacord = 1;
				}
			}
		else
		{
			if (n_size != 0 && min[n_size-1] - 48)
			{
				if (mnacord)
				{
					arr[m_size] = '0';
					mnacord = 0;
				}
				else
					arr[m_size] = '1';
			}
			else
			{
			arr[m_size] = mnacord+48;
			mnacord = 0;
			}
		};
		if (n_size)
			n_size--;
	}
	if (mnacord)
		arr[0] = mnacord + 48;
	else
		return &arr[1];
	return arr;
}

