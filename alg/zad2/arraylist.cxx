#include <iostream>
#include <vector>
#include <string>
#include "arraylist.hxx"

using namespace std;

int main()
{

    ArrayList<int> a;
    a.push_front(500);
    a.push_front(400);
    a.push_front(300);
    a.push_front(200);
    a.push_front(100);

    cout << "pop" << a.pop_front() << "size" << a.size();

    for (const auto &aa : a)
        std::cout
            << "foreach" << aa << std::endl;
    cout << "test2" << a.test(a.erase(a.prev(a.prev(a.end())))) << a.test(a.begin()) << endl;
    a.push_back(9999);

    for (const auto &aa : a)
        std::cout
            << "foreach" << aa << std::endl;

    cout << "back" << a.pop_back() << endl;

    a.insert(a.prev(a.end()), 77777);
    for (const auto &aa : a)
        std::cout
            << "foreach" << aa << std::endl;

    return 0;
}