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

    friend SCVector operator*(SCVector& v, float alpha) //Scale a vector using the (overloaded) operator '*'
    {   
        int dim = v.get_dimension();
        SCVector res(dim);

        for (int i=0; i<dim; i++)
        {
            res.data[i] = v.data[i] * alpha;
        }
        return res;        
            
    } 

    friend float dot(SCVector& v1, SCVector& v2) //Compute dot product of 2 vectors
    {
        float dot_prod = 0;
        int dim = v1.get_dimension();

        for (int i=0; i<dim; i++)
        {
            dot_prod += v1.data[i] * v2.data[i];
        }
        return dot_prod;

    }

};



int main()
{      
    int dim = 4;
    int *ptr = &dim;
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

    float k = 2;
    SCVector v1_scaled = v1 * k;
    cout << k << " * ";
    v1.display();
    cout  << " = "; 
    v1_scaled.display();

    float dot_v1v2 = dot(v1, v2);
    cout << endl;
    v1.display();
    cout << " . ";
    v2.display();
    cout  << " = " << dot_v1v2 << endl;

    //----------------------- Gram Schimdt Orthogonalization --------------------------------//

    *ptr = 3;
    SCVector a1(dim), a2(dim), a3(dim);

    a1.set_data(0,1);
    a1.set_data(1,0);
    a1.set_data(2,0);

    a2.set_data(0,2);
    a2.set_data(1,0);
    a2.set_data(2,3);

    a3.set_data(0,4);
    a3.set_data(1,5);
    a3.set_data(2,6);

    float ip_matrix[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++) 
        {
            //TODO
        }  
    }




    return 0;
}