#include <iostream> 
#include <vector>
#include "vektori.hpp"

using namespace std;

void vector_input(vector <int>& v, int vector_size)
{
	int n;
	for (int i = 0; i < vector_size; i++)
	{
		cin >> n;
		v.push_back(n);
	}
}

void vector_print(vector <int>& v, int vector_size)
{
	for (int i = 0; i < vector_size; i++)
	{
		cout << v[i] << " ";
	}

}

void vector_input_interval(vector<int>& v, int a, int b)
{
	int n;
	cin >> n;
	while (n >= a && n <= b)
	{
		v.push_back(n);
		cin >> n;
	}
}