#include <iostream>
#include <vector>
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
void vector_erase(vector <int>& v1, int position)
{
	v1.erase(v1.begin() + position);
	v1.insert(v1.begin() + position, v1.back());
	v1.pop_back();
}

int main()
{
	vector<int> v1;
	int v_size = 5, position;

	cout << "Input vector: " << endl;
	vector_input(v1, v_size);
	
	cout << "Input positon of the element you want to remove: " << endl;
	cin >> position;
	vector_erase(v1, 1);
	vector_print(v1, v1.size());
}

