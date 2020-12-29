#include "cursorlist.hxx"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    CursorList<int> li;

    // li.Prepend(11);
    li.push_front(69);
    li.push_front(3);
    li.push_front(2);
    li.push_front(88);
    li.push_front(33);
    cout << "tu " << endl;


    li.push_front(22);

    li.Traverse();

    cout << "tu " << endl;

    // li.push_back(4);
    // li.push_back(5);
    // cout << "pop:" << li.pop_front() << li.pop_front() << "foreach:";
    // for (const auto &a : li)
    // li.push_front(7);

    int b = li.pop_front();
    int p = li.pop_front();
    int r = li.pop_front();
    int t = li.pop_front();

    cout << b << "=" << p << "=" << r << "=" << t << "=";

    // li.push_back(333);
    // b = li.pop_back();
    // li.push_back(9);
    // p = li.pop_back();

    // li.Traverse();

    return 0;
}