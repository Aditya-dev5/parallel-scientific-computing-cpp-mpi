#include <iostream>
#include <cmath>
using namespace std;


void collatzA(int initial_guess)
{   
    int i = 1;
    while (initial_guess != 1)
    {   
        cout << "Iteration " << i << " : Value = " << initial_guess << endl;
        if (initial_guess % 2 == 0)
        {
            initial_guess = initial_guess / 2;
        }
        else
        {
            initial_guess = 3*initial_guess + 1;
        }
    i++;
    }
}

void collatzB(int initial_guess, int max_iterations)
{

    int i;

    for (i = 1; i <= max_iterations; i++)
    {   

        cout <<  "Iteration " << i << " : Value = " << initial_guess << endl;
        if (initial_guess % 2 == 0)
        {
            initial_guess = initial_guess / 2;
        }
        else
        {
            initial_guess = 3*initial_guess + 1;
        }

        if (initial_guess == 1 )
        {
            break;
        }
    }

}

int main()
{
    int initial_guess = 10;
    int max_iterations = 10;

    cout << "CollatzA :" << endl; 
    collatzA(initial_guess);
    cout << "------------------" << endl;
    cout << "CollatzB : " << endl;
    collatzB(initial_guess, max_iterations);

    return 0;
}
