#include <iostream>
using namespace std;

// This code computes the Matrix-Vector product A*x and stores the result in vector y. 
// Currently A is predefined and of size 3x3. Vector x is 3x1 and its elements are accepted via user input.

int main()
{   
    int A[3][3] = {{2, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int x[3] = {};
    int y[3] = {};
    int x_ele;

    cout << "Enter elements of vector x of size 3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cin >> x_ele;
        x[i] = x_ele;
    }  

    for (int i = 0; i < 3; i++)
    {   
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += A[i][j] * x[j];
        }
        y[i] = sum;
    }  

    cout << " A*x = " << "{ " << y[0] << " " << y[1] << " " << y[2] << " }" << endl;

    return 0;
}