#include <iostream>
using namespace std;


int main()
{
    int N = 10, a = 0, b = 1;
    double h = ((double) b - (double) a)/N, step = (double) a;

    int i;
    for (i = 0; i <= N; i++)
    {
        cout << step << "  " ;
        step += h;
    }

    return 0;
}