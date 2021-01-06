#include <iostream>
#include <math.h>

using namespace std;

double Fp(double x)
{
    return -sin(x);
}

template <class T>
T Da(T x, T h)
{

    return (cos(x + h) - cos(x)) / h;
}

template <class T>
T Db(T x, T h)
{

    return (cos(x + h) - cos(x - h)) / (2 * h);
}

int main()
{

    float h = 1;
    float x = 0.3;
    float d, f, b;
    for (int i = 1; i <= 50; i++)
    {

        h = h / 2;
        d = Da(x, h);
        d = Da(x, h);
        b = Db(x, h);

        f = Fp(x);

        cout << h << " " << fabs(d - f) << endl;

        // cout << "Da=" << d << "    Db=" << b << "      Fp=" << f << "    h=" << h << "    Da-Fp=" << d - f << "    Db-Fp=" << b - f << endl;
    }

    return 0;
}