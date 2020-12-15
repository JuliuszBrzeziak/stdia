#include <iostream>
#include <string>
#include "stack.hpp"
#include <unistd.h>

#define N 1000000

using namespace std;

int main()
{
    Stack<int, 1000000> stack;

    string sn;
    cin >> sn;
    int n = stoi(sn);

    for (int i = 0; i < n; i++)
    {
        cin >> sn;

        if (sn == "A")
        {
            cin >> sn;
            stack.push(stoi(sn));
        }
        else if (sn == "S")
        {
            cout << stack.size() << endl;
        }
        else if (sn == "D")
        {
            if (stack.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << stack.pop() << endl;
            }
        }
    }
}