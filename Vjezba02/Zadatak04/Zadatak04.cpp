#include <iostream>
#include <iomanip>
#include <cstddef>
using namespace std;

struct Vector
{
    int* arr;
    size_t size, capacity;


    void vector_new(size_t sz = 0);
    void vector_delete();
    void vector_push_back(int n);/* adds a new element at the end of the vector */
    void vector_pop_back();/* removes the last element in the vecto\r */
    int& vector_front();/* returns a reference to the first element in the vector*/
    int& vector_back(); /* returns a reference to the last element in the vector */
    size_t vector_size(); /* returns the number of the elements in the vector */

    void print_vector();
};
void Vector::vector_new(size_t sz)
{
    int n;
    cout << "How many elements? " << endl;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Input elements: " << endl;
        cin >> arr[i];
        sz++;
    }
    capacity = sz;
    size = n;

}
void Vector::vector_delete()
{
    delete[] arr;

}
void Vector::vector_push_back(int n)
{
    if (capacity > size)
    {
        arr[size] = n;
        size++;
    }
    else
    {
        int* arr2;
        arr2 = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = arr2[i];
        }
        size++;
        arr[size - 1] = n;
    }

}



void Vector::vector_pop_back()
{

    if ((capacity / 2) >= size - 1)
    {
        int* arr2;
        size--;
        arr2 = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        capacity /= 2;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr2[i];
        }
    }
    else
    {
        int* arr2;
        size--;
        arr2 = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr2[i];
        }
    }
}

int& Vector::vector_front()
{
    return arr[0];
}
int& Vector::vector_back()
{
    return arr[size - 1];
}

size_t Vector::vector_size()
{
    return size;
}


void Vector::print_vector()
{
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << std::endl;
}


int main()
{
    Vector mv;
    mv.vector_new();

    int m;
    cout << "Input element, Ctrl+d (linux) ili Ctrl+z (win) for end" << endl;
    while (cin >> m)
        mv.vector_push_back(m);

    cout << "first element " << mv.vector_front() << endl;
    cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "size " << mv.vector_size() << endl;
    cout << "capacity " << mv.capacity << endl;
    mv.print_vector();
    mv.vector_delete();

}