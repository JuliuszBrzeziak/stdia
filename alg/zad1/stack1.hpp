#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T, int N>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(T data);
	T Pop();
	T Top();

private:
	T *Data;
	int count = 0;
};

// Constructor
template <typename T, int N>
Stack<T, N>::Stack()
{
	Data = (T *)malloc(N + 1);
	count = 0;
}

// Destructor
template <typename T, int N>
Stack<T, N>::~Stack()
{
	free(Data);
}

// Method to push data
template <typename T, int N>
void Stack<T, N>::Push(T data)
{
	if (count < N)
	{
		Data[count] = data;
		count = count + 1;

		cout << "count" << count << "data" << Data[count] << endl;
	}
	else
	{
		cout << "\n stack Overflow!!!" << endl;
	}
}

// Methos to pop data
template <typename T, int N>
T Stack<T, N>::Pop()
{
	if (count > 0)
	{
		count -= 1;
		return Data[count];
	}
	else
	{
		cout << "\n stack is Empty" << endl;
	}
}

// Methos to pop data
template <typename T, int N>
T Stack<T, N>::Top()
{
	if (count > 0)
	{

		return Data[--count];
	}
	else
	{
		cout << "\n stack is Empty" << endl;
	}
}