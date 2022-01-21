#include "Header.h"


template<typename T>
void sort(T arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; i < j; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

template<>
void sort<char>(char arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; i < j; j--) {
			if (tolower(arr[j]) < tolower(arr[j - 1]))
				swap(arr[j], arr[j - 1]);
		}
	}
}

int main()
{
	char arr[30] = {};
	int sizeOfInputArray;
	cout << "How many elements are in your array? (30 max)" << endl;
	cin >> sizeOfInputArray;
	cout << "Input: " << endl;
	for (int i = 0; i < sizeOfInputArray; i++)
	{
		cin >> arr[i];
	}
	
	sort<char>(arr, sizeOfInputArray);
	cout << "Your array sorted : ";
	for (int i = 0; i < sizeOfInputArray; i++)
		cout << arr[i] << " ";
	cout << endl;

	//z2

	Stack<int> stack;

	if(stack.is_empty())
		cout << "Empty stack" << endl;
	else
		cout << "Stack not empty" << endl;
	
	stack.push(1);

	if (stack.is_empty())
		cout << "Empty stack" << endl;
	else
		cout << "Stack not empty" << endl;
	
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);

	cout << "The popped element is: " << stack.pop() << endl;

}