#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

int main()
{
     string s = "6 6";
     Stack<int, 100> stack;
     // cin >> s; //tu wchodzi ROZM
     int n = stoi(s);
#define ROZM 1
     for (int i = 0; i < ROZM; i++)
     {

          // cin >> s; // tu wchodzi funkcja
          // if (s != "D")
          // {
          // cin >> s; // tu argument
          int a = stoi(s);
          cout << "dostałem a=" << a << endl;
          stack.Push(a);
          cout << endl
               << "Top=" << stack.Top();

          stack.Push(--a);
          cout << endl
               << "Top=" << stack.Top();

          stack.Push(--a);
          cout << endl
               << "Top=" << stack.Top();

          stack.Push(--a);

          cout << endl
               << "Top=" << stack.Top() << stack.Pop() << stack.Pop() << "tuututuu" << endl;
          stack.Push(--a);
          cout << endl
               << "Top=" << stack.Top() << stack.Pop() << stack.Pop();

          // }
          // else if (s == "D")
          // {
          //     cout << stack.Top();
          // }
     }
     cout << "koncze" << endl;
     return 0;
}