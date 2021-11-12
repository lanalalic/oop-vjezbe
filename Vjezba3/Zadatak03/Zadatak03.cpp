#include <iostream>
#include <vector>
#include <algorithm>
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
void vector_sort(vector <int>& v1)
{
	int i, sum = 0, size1 = v1.size();
	sort(v1.begin(), v1.end());
	for (i = 0; i < size1; i++)
	{
		sum += v1[i];
	}
	v1.insert(v1.begin(), 0);
	v1.push_back(sum);
}

int main()
{
	vector<int> v1;
	int v_size = 5, n;

	cout << "Input vector: " << endl;
	vector_input(v1, v_size);

	vector_sort(v1);
	vector_print(v1, v1.size());
}
