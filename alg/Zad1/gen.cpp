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
    n = 1000000;
    cout << n << endl;

    for (int i = 0; i < n; i++)

    {
        cout << "A" << endl;
        cout << rand() % 1000000 << endl;
        cout << "D" << endl;
    }
    // for (int j = 0; j < n; j++)
    // {
    //     cout << "D" << endl;
    // }
    return 0;
}
