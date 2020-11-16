#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int *b;
    cout << "a=" << a << endl;
    b = &a;
    cout << "b=" << *b << endl;
}