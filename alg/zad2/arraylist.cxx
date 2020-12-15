#include <iostream>
#include <vector>
#include <string>
#include "arraylist.hxx"

using namespace std;

int main()
{

    ArrayList<int> a;
    a.push_back(100);
    a.push_back(200);
    a.push_back(300);
    a.push_back(400);
    a.push_back(500);

    for (const auto &aa : a)
        std::cout << "foreach" << aa << std::endl;

    cout << a.test(a.begin());
    cout << a.test(a.next(a.begin())) << endl;

    a.insert(a.next(a.begin()), 4);
    a.push_back(600);
    cout << a.test(a.end()) << "działasz??";

    for (const auto &aas : a)
        std::cout << "foreach" << aas << std::endl;
    return 0;
}