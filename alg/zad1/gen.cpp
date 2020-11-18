#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 10;
    cout << n << endl;

    for (int i = 0; i < 1000; i++)
    {
        cout << rand() % 1000000 << endl;
    }

    return 0;
}