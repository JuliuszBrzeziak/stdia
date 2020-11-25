#include <iostream>
#include <string>
#include "queue.hpp"
#include <chrono>

using namespace std;

int main()
{
     Queue<int, 1000000> queue;

     string sn;
     cin >> sn;
     int n = stoi(sn);
     chrono::time_point<chrono::system_clock> start, end;
     start = chrono::system_clock::now();

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
     end = chrono::system_clock::now();
     chrono::duration<double> elapsed_seconds = end - start;
     cout << "operacja trwała: " << elapsed_seconds.count() << "s\n";
}