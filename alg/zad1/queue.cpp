#include <iostream>
#include <string>
#include "queue.hpp"

using namespace std;

int main()
{
     Queue<int, 1000000> queue;

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
          else if (sn == "S")
          {
               cout << queue.size() << endl;
          }
          else if (sn == "D")
          {
               if (queue.empty())
               {
                    cout << "EMPTY" << endl;
               }
               else
               {
                    cout << queue.pop() << endl;
               }
          }
     }
}