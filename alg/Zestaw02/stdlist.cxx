#include <iostream>
#include <string>
#include "arraylist.hxx"
#include <unistd.h>
#include <list>
#include <algorithm>

#define N 1000000

using namespace std;

int main()
{
    std::list<int> list;

    string sn;
    string sn2;

    cin >> sn;
    int n = stoi(sn);

    for (int i = 0; i < n; i++)
    {
        cin >> sn;

        if (sn == "F")
        {
            cin >> sn;
            list.push_front(stoi(sn));
        }
        else if (sn == "B")
        {
            cin >> sn;
            list.push_back(stoi(sn));
        }

        else if (sn == "R")
        {
            cin >> sn;
            cin >> sn2;

            list.insert(list.erase(std::find(list.begin(), list.end(), stoi(sn))), stoi(sn2));
        }

        else if (sn == "S")
        {
            cout << list.size() << endl;
        }
        else if (sn == "f")
        {
            if (list.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << list.front() << endl;
                list.pop_front();
            }
        }
        else if (sn == "b")
        {
            if (list.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << list.back() << endl;
                list.pop_back();
            }
        }
    }
}