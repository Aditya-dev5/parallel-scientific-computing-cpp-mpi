#include <iostream>
using namespace std;

float get_float_macheps()
{
    float mach_eps = 1.0;
    float ftest = 1.0 + mach_eps;

    while (ftest != 1)
    {
        mach_eps /= 2;
        ftest = 1.0 + mach_eps;
    }
    return mach_eps;
}

double get_double_macheps()
{
    double mach_eps = 1.0;
    double ftest = 1.0 + mach_eps;

    while (ftest != 1)
    {
        mach_eps /= 2;
        ftest = 1.0 + mach_eps;
    }
    return mach_eps;
}


int main()
{

    float float_macheps = get_float_macheps();
    double double_macheps = get_double_macheps();

    cout << "Float machine-epsilon is = " << float_macheps << endl;
    cout << "Double machine-epsilon is = " << double_macheps << endl;

    return 0;
}