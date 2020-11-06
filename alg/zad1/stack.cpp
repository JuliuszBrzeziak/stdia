#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

int main()
{
    string s = "6 6";
    Stack<int, 100> stack;
    // cin >> s; //tu wchodzi ROZM
    int n = stoi(s);
#define ROZM 1
    for (int i = 0; i < ROZM; i++)
    {

        // cin >> s; // tu wchodzi funkcja
        // if (s != "D")
        // {
        // cin >> s; // tu argument
        int a = stoi(s);
        cout << "dostałem a=" << a << endl;
        stack.push(a);
        cout << endl
             << "top=" << stack.top();

        stack.push(--a);
        cout << endl
             << "top=" << stack.top();

        stack.push(--a);
        cout << endl
             << "top=" << stack.top();

        stack.push(--a);

        cout << endl
             << "top=" << stack.pop();

        // }
        // else if (s == "D")
        // {
        //     cout << stack.top();
        // }
    }
    cout << "koncze" << endl;
    return 0;
}