#include <iostream>
#include "arraylist.hxx"

using namespace std;

int main()
{

    ArrayList<int> a;
    a.push_back(100);
    cout << a.pop_back() << endl;

    return 0;
}