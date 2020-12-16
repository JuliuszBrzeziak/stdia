#include <iostream>
#include <string>
#include "arraylist.hxx"
#include <chrono>

using namespace std;

int main()
{
     ArrayList<int> array;

     string sn;
     cin >> sn;
     int n = stoi(sn);
     cout << array.siz;

     for (int i = 0; i < n; i++)
     {
          cin >> sn;
          if (sn == "B")
          {
               cin >> sn;
               array.push_back(stoi(sn));
          }

          else if (sn == "b")
          {
               if (array.empty())
               {
                    cout << "EMPTY";
               }
               else
               {
                    cout << array.pop_back() << endl;
               }
          }
          if (sn == "F")
          {
               cin >> sn;
               array.push_front(stoi(sn));
          }

          else if (sn == "f")
          {
               if (array.empty())
               {
                    cout << "EMPTY";
               }
               else
               {
                    cout << array.pop_front() << endl;
               }
          }
          else if (sn == "S")
          {
               cout << array.size() << endl;
          }

          else if (sn == "R")
          {
               int x, y;
               cin >> sn;
               x = stoi(sn);
               cin >> sn;

               array.insert(array.erase(array.find(x)), stoi(sn));
          }
     }
}