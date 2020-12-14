#include <iostream>
#include <string>
#include <unistd.h>
#include <queue>

using namespace std;

int main()
{
    queue<int> queue;

    string sn;
    cin >> sn;
    int n = stoi(sn);

    for (int i = 0; i < n; i++)
    {
        cin >> sn;

        if (sn == "A")
        {
            cin >> sn;
            queue.push(stoi(sn));
        }

        else if (sn == "D")
        {
            if (queue.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << queue.front() << endl;
                queue.pop();
            }
        }

        else if (sn == "S")
        {
            cout << queue.size() << endl;
        }
    }
}