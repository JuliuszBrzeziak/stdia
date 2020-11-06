#include <iostream>

using namespace std;

template <class T, int N>
class Stack
{
public:
	template <typename U>
	class Node
	{
	public:
		U i;
		Node *prev;

		void xd()
		{
			cout << "X";
		}
		Node()
		{
		}
		Node(U n)
		{
			i = n;
			prev = nullptr;
		}

		Node(Node *node)
		{
			prev = node;
		}

		Node(U n, Node *node)
		{
			i = n;
			prev = node;
		}
	};

	template <class Y>
	void foo(Y &&a);
	void push(T x); // Wstawia element x na stos
	T pop();		// Usuwa element ze stosu i zwraca jego wartość
	T &top();		// Zwraca referencję do najmłodszego elementu
	int size();		// Zwraca liczbę elementów na stosie

	bool empty(); // Sprawdza czy stos jest pusty
	Stack();
	Node<T> *Top;

private:
	int Size = N;
	int height = 0;
};
template <class T, int N>
T Stack<T, N>::pop()
{
	T help = Top->i;
	cout << "I=" << Top->i << "   II=";
	Top->prev;
	cout << Top->i << endl;
	return Top->i;
}

// Method to push data
template <class T, int N>
void Stack<T, N>::push(T x)
{

	if (height < Size)
	{
		Node<T> node = new Node<T>(x, Top);

		node.i = x;
		Top = Top->prev;
		height = height + 1;
	}
	else
	{
		cout << "oversize" << endl;
	}
}

template <class Y>
void foo(Y &&a)
{

	cout << "foo";
}

template <class T, int N>
T &Stack<T, N>::top()
{
	return Top->i;

	if (empty())
	{
		throw("Top->:empty");
	}
	else
	{
	}
}

template <class T, int N>
int Stack<T, N>::size()
{

	return height;
}

template <class T, int N>
Stack<T, N>::Stack()
{
	printf("konstruktor");
	Node<T> *node(nullptr);
	Top = node;
}

template <class T, int N>
bool Stack<T, N>::empty()
{

	if (height == 0)
	{

		return true;
	}
	else
	{

		return false;
	}
}

// int main(){

//     Stack<int,5> stack;
// 	//stack.foo(2);
// 	cout << "TEST" << "#  : empty=" << stack.empty();

// 	cout<< boolalpha <<stack.empty() << endl;
//     stack.push(10);
// 	cout << "TEST" << "#  : empty=" << stack.empty() << "#   height=" << stack.Top->() << "#   size=" << stack.size() << "#" << endl;

// 	stack.push(2);
// 	cout << "TEST" << "#  : empty=" << stack.empty() << "#   height=" << stack.Top->() << "#   size=" << stack.size() << "#" << endl;

// 	stack.push(4);

// 	stack.push(3);
// 	cout << "TEST" << "#  : empty=" << stack.empty() << "#   height=" << stack.Top->() << "#   size=" << stack.size() << "#" << endl;

// }