#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void vector_of_strings(vector <string>& vs1)
{
	string s;
	cin >> s;
	while (s != "0") {
		reverse(s.begin(), s.end());
		vs1.push_back(s);
		cin >> s;
	}
	sort(vs1.begin(), vs1.end());
}



void vector_printstr(vector <string>& v, int vector_size)
{

	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";

}
int main()
{
	vector<string> vs;
	cout << "Input strings, 0 for end of input" << endl;
	vector_of_strings(vs);
	vector_printstr(vs, vs.size());
}

