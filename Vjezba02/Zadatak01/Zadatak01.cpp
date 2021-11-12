#include <iostream>
#include <iomanip>
using namespace std;

void min_and_max(int* arr, int& min, int& max, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
}

int main()
{
	int arr[] = { 1,4,5,6,7,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int min = arr[0], max = arr[0];
	cout << size << endl;
	min_and_max(arr, min, max, size);
	cout << "min: " << min << "max:" << max << endl;
	return 1;
}
