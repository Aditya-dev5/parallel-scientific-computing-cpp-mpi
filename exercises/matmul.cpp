#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C_1[2][2] = {{0, 0}, {0, 0}};

    // Matrix Multiplication : C = A.B
    // c_ij = c_ij + A_ik . B_kj 

    // 1. Inner (dot) product version MatMat.ijk


    auto start1 = chrono::high_resolution_clock::now();

    int i, j, k;

    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            for (k = 0; k <= 1; k++)
            {
                C_1[i][j] += A[i][k] * B[k][j];
            }
        }
    }
 
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    cout << "ijk : " << endl;
    cout << "C = " << endl;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cout << C_1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "ijk method took "<< duration1.count() << " nano-second(s)."<< endl;

    cout << "----------------------------------------------------------------------" << endl;
    // ----------------------------------------------------------------------------
    // 2. Dual inner (dot) product version MatMat.jik

    int C_2[2][2] = {{0, 0}, {0, 0}};
    auto start2 = chrono::high_resolution_clock::now();

    for (j = 0; j <= 1; j++)
    {
        for (i = 0; i <= 1; i++)
        {
            for (k = 0; k <= 1; k++)
            {
                C_2[i][j] += A[i][k] * B[k][j];
            }
        }
    }
 
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);

    cout << "jik : " << endl;
    cout << "C = " << endl;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cout << C_2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "jik method took "<< duration2.count() << " nano-second(s)."<< endl;


    cout << "----------------------------------------------------------------------" << endl;
    // ----------------------------------------------------------------------------
    // 3. Middle product version MatMat.jki
    int C_3[2][2] = {{0, 0}, {0, 0}};

    auto start3 = chrono::high_resolution_clock::now();

    for (j = 0; j <= 1; j++)
    {
        for (k = 0; k <= 1; k++)
        {
            for (i = 0; i <= 1; i++)
            {
                C_3[i][j] += A[i][k] * B[k][j];
            }
        }
    }
 
    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);

    cout << "jki : " << endl;
    cout << "C = " << endl;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cout << C_3[i][j] << " ";
        }
        cout << endl;
    }

    cout << "jki method took "<< duration3.count() << " nano-second(s)."<< endl;


    // Although mathematically equivalent, the above 3 versions can have different levels of computer performance based on the way memory is accessed.


    return 0;
}