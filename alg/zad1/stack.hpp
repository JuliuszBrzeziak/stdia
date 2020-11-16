#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T, int N>
class Stack
{

	T *tab;			// Tablica wskaźników do elementów stosu
	int Size;		// Rozmiar tablicy *tab
	int height = 0; // Indeks pierwszego wolnego miejsca na stosie

public:
	Stack();
	~Stack();

	void push(T &&);
	T pop();
	int empty();
	int size();
	T &top();
};

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
Stack<T, N>::Stack()
{
	Size = N;
	tab = (T *)malloc(N);
}

template <class T, int N>
Stack<T, N>::~Stack()
{
	free(tab);
}

template <class T, int N>
void Stack<T, N>::push(T &&elt)
{
	if (height < N)
	{
		tab[height] = elt;
		cout << tab[height];
		height++;
	}
	else
		exit(11);
}

template <class T, int N>
T Stack<T, N>::pop()
{
	if (!height)
		exit(2);

	T res(tab[--height]); // Ze względu na konieczność usuwania są
	return res;
}

template <class T, int N>
int Stack<T, N>::empty()
{
	return height == 0;
}
