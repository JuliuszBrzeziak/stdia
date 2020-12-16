#include <iostream>
#include <vector>
#include <string>
#include "pointerlist.hxx"

using namespace std;

int main()
{
    PointerList<int> p;
    p.push_front(1);
    p.push_front(2);
    p.push_front(3);
    int i, j;

    i = p.pop_front();
    j = p.pop_back();

    for (const auto &aa : p)
        std::cout
            << "foreach" << aa << std::endl;

    cout
        << i << "   " << j << endl;
    return 0;
}