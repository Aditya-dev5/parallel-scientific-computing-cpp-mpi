#include <iostream>
#include <cmath>
using namespace std;

class SCVector
{   
    private:
    int dimension; //dimension of vector
    double *data; // Pointer to array containing elements of vector

    public:
    SCVector(int dim) // Default constructor: initializes a zero-vector of dimension dim
    {
        dimension = dim;
        data = new double[dimension];

        for (int i=0; i<dimension; i++)
        {
            data[i] = 0.0;
        }
    }

    SCVector(const SCVector &v) // Creates a copy of vector 
    {
        dimension = v.dimension;
        data = new double[dimension];

        for(int i=0; i<dimension; i++)
        {
            data[i] = v.data[i];
        }
    
    }

    int get_dimension() // Get dimension of vector
    {
        return dimension;
    }

    void set_data(int idx, double val)
    {
        data[idx] = val;
    }

    double norm_L2() // Get L2 norm of vector 
    {   
        int sum = 0;
        for (int i=0; i<dimension; i++)
        {
            sum += data[i]*data[i];
        }
        return sqrt(sum);
    }

    void normalize() // Normalize vector
    {
        double temp = 1.0/norm_L2();
        for (int i=0; i<dimension; i++)
        {
            data[i] = data[i]*temp;
        }
    }

    void display()
    {   
        cout << "[ ";
        for (int i=0; i<dimension; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]";
    }
    
    
    friend SCVector operator+(SCVector& v1, SCVector& v2) //Add 2 vectors using the (overloaded) operator '+'
    {   
        int dim = v1.get_dimension();
        SCVector res(dim);

        for (int i=0; i<dim; i++)
        {
            res.data[i] = v1.data[i] + v2.data[i];
        }
        return res;        
            

    }

};

int main()
{      
    int dim = 4;
    SCVector v1(dim), v2(dim);

    for (int i=0; i<dim; i++)
    {
        v1.set_data(i , i);
        v2.set_data(i , i*i);
    }

    cout << "v1 = "; 
    v1.display();
    cout << endl;
    cout << "v2 = "; 
    v2.display();
    cout << endl;

    SCVector v3 = v1 + v2;
    cout << "v3 = v1 + v2 = "; 
    v3.display();
    cout << endl;

    SCVector v4(v1);
    v4.display();

    return 0;
}