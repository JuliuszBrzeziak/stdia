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

     for (int i = 0; i < n; i++)
     {
          cin >> sn;
          if (sn == "A")
          {
               cin >> sn;
               array.push_back(stoi(sn));
          }

          else if (sn == "D")
          {
               if (array.empty())
               {
                    cout << "EMPTY" << endl;
               }
               else
               {
                    cout << array.pop_back() << endl;
               }
          }
          else if (sn == "S")
          {
               cout << array.size() << endl;
          }
     }
}