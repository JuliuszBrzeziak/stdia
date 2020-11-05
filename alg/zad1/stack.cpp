#include <iostream>

using namespace std;


template<class T, int N>
class Stack {
    public:

	template<class U>
	class Node{
		Node *prev;
	public:
		U i;

		void xd(){
			cout << "X";
		}
	Node(){

	}
	Node(U n){
		i = n;
		prev = nullptr;
	}

	Node(U n,Node *node){
		i = n;
		prev = node;
	}
	};

template<class Y>
void foo (Y&& a);
void push(T x);// Wstawia element x na stos
T pop(); // Usuwa element ze stosu i zwraca jego wartość
T& top(); // Zwraca referencję do najmłodszego elementu
int size(); // Zwraca liczbę elementów na stosie

bool empty();// Sprawdza czy stos jest pusty
private:
	Node<T> *Data =new Node<T>(1,nullptr);
	int Size = N;
	int topp;
};

// Method to push data
template<class T, int N>
void Stack<T,N>::push(T x)
{
	Node<T> a = Node<T>(7,nullptr);
	a.xd();
	if (topp < N)
	{

		*Data = a;
		cout << Data->i <<"<-----------";

		topp = topp + 1;

	}
	else
	{
		cout << Size  <<endl;
	}
}
template<class Y>
void foo(Y&& a){

	cout << "foo";

}

template<class T, int N>
T& Stack<T,N>::top(){

	if(empty()){
		throw ("top:empty");
		
	} else{
		return Data->i;
	}

}


template<class T, int N>
int Stack<T,N>::size(){

	return topp;

}



template<class T, int N>
bool Stack<T,N>::empty(){

	if(topp == 0){

		return true;
	}else{

		return false;
	}

}

int main(){


    Stack<int,5> stack;
	//stack.foo(2);
	cout << "TEST" << "#  : empty=" << stack.empty();

	cout<< boolalpha <<stack.empty() << endl;
    stack.push(10);
	cout << "TEST" << "#  : empty=" << stack.empty() << "#   topp=" << stack.top() << "#   size=" << stack.size() << "#" << endl;

	stack.push(2);
	cout << "TEST" << "#  : empty=" << stack.empty() << "#   topp=" << stack.top() << "#   size=" << stack.size() << "#" << endl;

	stack.push(4);

	stack.push(3);
	cout << "TEST" << "#  : empty=" << stack.empty() << "#   topp=" << stack.top() << "#   size=" << stack.size() << "#" << endl;


}