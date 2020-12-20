#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T, int N>
class Stack
{

	T *tab;			// Tablica
	int Size;		// Rozmiar tablicy *tab
	int height = 0; // Indeks pierwszego wolnego miejsca na stosie

public:
	Stack();
	Stack<T, N>(const Stack<T, N> &s1);
	Stack<T, N>(Stack<T, N> &&s1);

	~Stack();

	void push(T &&);
	T pop();
	int empty();
	int size();
	T &top();
	Stack &operator=(const Stack &S)
	{
		tab = S.tab;
		Size = S.Size;
		height = S.height;
		return *this;
	};
	Stack &operator=(Stack &&S)
	{
		tab = S.tab;
		Size = S.Size;
		height = S.height;
		return *this;
	};
};

template <class T, int N>
Stack<T, N>::Stack()
{
	Size = N;
	tab = (T *)malloc(N);
}

template <class T, int N>
Stack<T, N>::Stack(const Stack<T, N> &s1)
{

	tab = (T *)malloc(N);
	tab = s1.tab;
	Size = s1.Size;
	height = s1.height;
}

template <class T, int N>
Stack<T, N>::Stack(Stack<T, N> &&s1)
{

	tab = (T *)malloc(N);
	tab = s1.tab;
	Size = s1.Size;
	height = s1.height;
}

template <class T, int N>
T &Stack<T, N>::top()
{
	return tab[height - 1];
}

template <class T, int N>
int Stack<T, N>::size()
{

	return height;
}

template <class T, int N>
Stack<T, N>::~Stack()
{
}

template <class T, int N>
void Stack<T, N>::push(T &&elt)
{

	if (height < N)
	{
		tab[height] = elt;
		height++;
	}
	else
		throw std::out_of_range("push out of range");
}

template <class T, int N>
T Stack<T, N>::pop()
{
	if (!height)
		throw std::out_of_range("pop out of range");

	T res(tab[--height]);
	return res;
}

template <class T, int N>
int Stack<T, N>::empty()
{
	return height == 0;
}
