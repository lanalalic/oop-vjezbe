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


void vector_intersect(vector <int>& v1, vector <int>& v2, vector <int>& v3)
{
	int i, j;
	int size1 = v1.size();
	int size2 = v2.size();
	int br = 0;
	for (i = 0; i < size1; i++)
	{
		br = 0;
		for (j = 0; j < size2; j++)
		{
			if (v1[i] == v2[j])
				br++;
		}
		if (br == 0)
			v3.push_back(v1[i]);
	}
}
int main()
{
	vector<int> v1, v2, v3;
	int v_size = 5;

	cout << "Input first vector: " <<endl;
	vector_input(v1,v_size);
	cout << "\nInput second vector : " <<endl;
	vector_input(v2, v_size);
	cout << "\n";
	cout << "Vector with elements from the fist but not from the second vector: " << endl;
	vector_intersect(v1, v2, v3);
	vector_print(v3, v3.size());
	cout << "\n";
}

