#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

int main()
{
    string s;
    Stack<int, 100> stack;
    cin >> s;
    int n = stoi(s);
    for (int i = 0; i < 10; i++)
    {

        cin >> s;
        // if (s != "D")
        // {
        // cin >> s;
        int a = stoi(s);
        cout << "dostałem a=" << a << endl;
        stack.push(a);
        stack.push(--a);
        stack.push(--a);
        stack.push(--a);

        cout << stack.top();

        cout << stack.top();
        cout << stack.top();

        cout << stack.top();
        // }
        // else if (s == "D")
        // {
        //     cout << stack.top();
        // }
    }
    cout << "koncze" << endl;
    return 0;
}