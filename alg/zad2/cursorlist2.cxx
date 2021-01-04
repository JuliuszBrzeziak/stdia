#include "cursorlist.hxx"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    CursorList<int> li;

    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    cout << "head=" << li.head << "   tail=" << li.tail << "   spare=" << li.spare << endl;

    li.Traverse();

    // li.pop_back();
    int b = li.pop_back();
    int a = li.pop_front();
    li.push_back(6);
    li.push_front(7);

    b = li.pop_back();
    a = li.pop_front();
    li.push_back(6);
    li.push_front(7);

    cout << "head=" << li.head << "   tail=" << li.tail << "   spare=" << li.spare << endl;

    cout << "pop_back" << b << endl;

    li.Traverse();

    for (const auto &aa : li)
        std::cout
            << "foreach" << aa << std::endl;

    return 0;
}
