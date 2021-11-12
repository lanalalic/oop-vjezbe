#include <iostream>
#include <iomanip>
using namespace std;

int& reference(int* arr, int n)
{
	return arr[n - 1];
}


int main()
{
	int arr[] = { 1,4,25,6,17,8 };
	int n;
	cout << "Input element: " << endl;
	cin >> n;


	reference(arr, n) += 1;

	cout << "Element +1: " << arr[n - 1] << endl;

}