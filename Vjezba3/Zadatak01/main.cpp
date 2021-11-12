#include <iostream>
#include <vector>
#include <string>
#include "vektori.hpp"
using namespace std;


int main()
{
	vector<int> v1, v2;
	
	int v_size = 5, a, b;




	vector_input(v1,v_size);
	vector_print(v1, v_size);
	cout << endl;

	cout << "Input interval : " << endl;
	cin >> a;
	cin >> b;
	cout << "Input elements : " << endl;
	vector_input_interval(v2, a, b);
	vector_print(v2,  v2.size());
	cout << "\n";
}