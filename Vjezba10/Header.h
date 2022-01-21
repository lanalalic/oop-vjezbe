#pragma once
#include <iostream>
using namespace std;
#define N 10 // size of array in stack


template <class T>
class Stack {
private:
	T array[N];
	int head = -1;
public:
	void push(T n);
	T pop();
	bool is_empty();
};

template <class T> void Stack<T>::push(T n)
{
	head = head + 1;
	array[head] = n;
}


template <class T> T Stack<T>::pop()
{
	T arrayMember = array[head];
	head = head - 1;
	return arrayMember;
}

template <class T> bool Stack<T>::is_empty()
{
	if (head == -1)
		return 1;
	else
		return 0;
}

