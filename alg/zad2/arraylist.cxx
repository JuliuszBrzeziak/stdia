#include <iostream>
#include "arraylist.hxx"

using namespace std;

int main()
{

    ArrayList<int> a;
    a.push_back(100);
    a.push_back(200);
    a.push_back(300);

    cout << a.test(a.begin());
    cout << a.test(a.prev(a.next(a.begin())));
    a.test2(a.begin(), a.begin());
    return 0;
}