#include <iostream>
#include <string>
// #include "stack.hpp"
#include <unistd.h>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack;

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

        else if (sn == "D")
        {
            if (stack.empty())
            {
                cout << "EMPTYY" << endl;
            }
            else
            {
                cout << stack.top() << endl;
                stack.pop();
            }
        }

        else if (sn == "S")
        {
            cout << stack.size() << endl;
        }
    }
}