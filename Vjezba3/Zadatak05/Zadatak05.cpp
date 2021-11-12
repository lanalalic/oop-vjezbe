#include <iostream>
#include <string>
using namespace std;

int num_of_substrings(string& s1, string& s2)
{
	int cnt = 0, pos;
	pos = s1.find(s2);

	while (pos != string::npos) {
		pos = s1.find(s2, pos + s2.size());
		cnt += 1;
	}

	return cnt;

}

int main()
{
	int n;
	string s1 = "kkbananjdsjddjbaanajsjdjdbananajddjlaabanana", s2 = "banana";

	n=num_of_substrings(s1, s2);
	cout <<"Number of substrings in a string: " << n;
}

