// zadatak04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int recursion_min_max(int* arr, int* mini, int* maxi, int i)
{
    if (i < 0)
        return 0;
    if(arr[i] > *maxi)
        *maxi = arr[i];
    if (arr[i] < *mini)
        *mini = arr[i];
    return recursion_min_max(arr, mini, maxi, i - 1);

}

int main()
{
    int arr[21], max, min, size, i=0;
    cout << "Number of elements? (up to 20)\n";
    cin >> size;
    cout << "Enter elements: \n";
    for (i; i < size; i++)
        cin >> arr[i];

    max = arr[0];
    min = arr[0];

    recursion_min_max(arr, &min, &max, size-1);

    cout << "Minimum element: " << min << "\nMaximum element: " << max << endl;
}
