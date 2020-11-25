#include <iostream>
#include <string>
#include "stack.hpp"
#include <unistd.h>

using namespace std;

int main()
{
    Stack<int, 1000000> stack;

    string sn;
    cin >> sn;
    int n = stoi(sn);

    for (int i = 0; i < n; i++)
    {
        usleep(100);

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
                cout << "EMPTYY" << endl;
            }
            else
            {
                cout << "pop" << stack.pop() << endl;
            }
        }
        cout << "stack:end";
    }
}