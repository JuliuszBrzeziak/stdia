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
		cout << "Ocoppy";
		tab = S.tab;
		Size = S.Size;
		height = S.height;
		return *this;
	};
	Stack &operator=(Stack &&S)
	{
		cout << "Omove";
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
	cout << "ccoppy";

	tab = (T *)malloc(N);
	tab = s1.tab;
	Size = s1.Size;
	height = s1.height;
}

template <class T, int N>
Stack<T, N>::Stack(Stack<T, N> &&s1)
{
	cout << "cmove";

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
