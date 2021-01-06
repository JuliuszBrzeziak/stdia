#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = rand() % 1000000;
    n = 1000;
    cout << n << endl;

    for (int i = 0; i < n; i++)

    {
        cout << "B" << endl;
        cout << i << endl;
        cout << "b" << endl;
    }

    return 0;
}