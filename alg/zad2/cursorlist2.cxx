#include "cursorlist.hxx"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    CursorList<int> li;

    // li.Prepend(11);
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_front(4);
    li.push_front(4);

    li.push_back(987);
    li.push_front(1234);
    li.push_back(567);
    // cout << li.pop_front() << "  " << li.pop_front() << "  " << li.pop_back() << "  " << li.pop_back() << "  " << endl;s
    li.push_front(111111);
    li.push_back(999999);

    for (const auto &aa : li)
        std::cout
            << "foreach" << aa << std::endl;

    li.erase(li.find(987));
    // li.insert(li.erase(li.find(3)), 69);
    for (const auto &bb : li)
        std::cout
            << "foreach2" << bb << std::endl;

    // li.push_back(555);
    // li.push_back(9877);

    cout << li.remove(4);

    CursorList<int> li2;

    // li2.Prepend(11);
    li2.push_front(1);
    li2.push_front(2);
    li2.push_front(3);
    li2.push_front(4);
    li2.push_front(4);

    // li2.Traverse();

    for (const auto &cc : li2)
        std::cout
            << "wrk" << cc << std::endl;

    cout << "tu " << endl;

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