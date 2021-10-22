// zadatak03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void min_max(int* arr, int size,int *mini, int *maxi)
{
    
    for (int i=1; i < size; i++)
    {
        if (arr[i] > *maxi)
            *maxi = arr[i];
        if (arr[i] < *mini)
            *mini = arr[i];
    }

}



int main()
{
    int arr[21], max, min, size,i;
    cout << "Number of elements? (up to 20)\n";
    cin >> size;
    cout << "Enter elements: \n";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    max = arr[0];
    min = arr[0];

    min_max(arr, size, &min, &max);


    cout << "Minimum element: " << min << "\nMaximum element: " << max << endl;

    
}


