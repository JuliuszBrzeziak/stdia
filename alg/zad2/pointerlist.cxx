#include <iostream>
#include <vector>
#include <string>
#include "pointerlist.hxx"

using namespace std;

int main()
{
    PointerList<int> p;
    p.push_front(1234);

    int i = p.pop_front();
    cout << i << endl;
    // cout << p.test(p.begin());

    i = p.pop_front();
    cout << i << endl;
    p.push_front(312);

    i = p.pop_front();
    cout << i << endl;
    return 0;
}