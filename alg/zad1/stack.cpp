#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

int main()
{
    Stack<int, 100> stack;

    int a = 9;
    int b = 8;
    stack.push(9);
    cout << "top=" << stack.top() << endl;
    stack.push(8);
    cout << "top=%" << stack.top() << "#size=" << stack.size() << "pop="
         << " size=" << stack.size() << endl;
    Stack<int, 100> stack2 = stack;
    cout << "top=%" << stack.top() << "#size=" << stack.size() << "pop=" << stack.pop() << stack.pop() << " size=" << stack.size() << endl;
}