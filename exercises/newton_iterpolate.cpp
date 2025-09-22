#include <iostream>
using namespace  std;

double func(double x)
{
    double y;
    y = 1.0 + 25.0*x*x;
    y = 1.0/y;
    return y;
}

void create_evenspace_grid(int npts, double *x, double b, double a) // Create an evenly spaced grid between a and b (a<b) having npts points
{   
    double h = (b-a) / (npts-1.0);
    for (int i=0; i<npts; i++)
    {   
        x[i] = a + i*h;
    }
}

double NewtonDiffFunction(int start_idx, int end_idx, double *func_vals, double *xpts)
{
    int diff = end_idx - start_idx;

    double val;
    if (diff == 0)
    {
        val = func_vals[start_idx];
    }
    else
    {
        val = ( NewtonDiffFunction(start_idx, end_idx-1, func_vals, xpts) - NewtonDiffFunction(start_idx+1, end_idx, func_vals, xpts) ) / (xpts[start_idx] - xpts[end_idx]);
    }
    return val;
}

void NewtonDiffTable(int polynpts, double *xpts, double *func_vals, double *newton_coeffs)
{
    for (int i=0; i<polynpts; i++)
    {
        newton_coeffs[i] = NewtonDiffFunction(0, i, func_vals, xpts);
    }

}

double NewtonInterpolant(double x, double *xpts, double *newton_coeffs , int npts)
{
    
    double sum = newton_coeffs[0];
    for (int i=1; i<npts; i++)
    {   
        double prod = 1;
        for (int j=0; j<=i-1; j++) 
        {
            prod *= x - xpts[j];
        }
        sum += newton_coeffs[i]*prod;
    }
    return sum;
}


int main()
{   
    int npts = 1000;
    int degree;

    cout << "Enter desired degree of interpolating polynomial: ";
    cin >> degree;

    int polypnts = degree + 1; // Nth degree polynomial has N+1 coefficients
    
    double *newton_coeffs; 
    newton_coeffs = new double[polypnts]; //Array containing coefficients of interpolating polyonomial

    double *func_vals; 
    func_vals = new double[polypnts]; //Array containing values of function to be approximated

    double *poly_xpts; 
    poly_xpts = new double[polypnts]; //Array containing values at which interpolation is to be performed

    create_evenspace_grid(polypnts, poly_xpts, 1.0, -1.0); //Populate #polynpts gridpoints including -1 and 1 (endpoints)

    for (int i=0; i<polypnts; i++)
    {   
        func_vals[i] = func(poly_xpts[i]); //Populate function values on gridpoints
    }

    NewtonDiffTable(polypnts, poly_xpts, func_vals, newton_coeffs);

    for (int i=0; i<npts; i++)
    {   
        double x_pt = -1.0 + i*(2.0/(npts-1));

        double true_val = func(x_pt);
        double approx_val = NewtonInterpolant(x_pt, poly_xpts, newton_coeffs, npts);
        
        if(i%(npts/10) == 0 || i==0)
            {cout << " True val = " << true_val << "  &   Approx val = " << approx_val << endl;}

    }
    delete[] poly_xpts;
    delete[] func_vals;
    delete[] newton_coeffs;

    return 0;
}