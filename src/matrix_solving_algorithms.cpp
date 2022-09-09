//
// Functions for calculating the solutions of matrixequations with tridiagonal matrices
//

#include "matrix_solving_algorithms.hpp"


// Solve a general matrix equation
std::vector<double> general_algorithm(
    std::vector<double> a,
    std::vector<double> b,
    std::vector<double> c,
    std::vector<double> g)
    {
        int lambda;
        std::vector<double> v(b.size);
        
        for (int i = 0; i < a.size; i++)
        {
            lambda = a[i]/b[i];
            b[i+1] = b[i+1] - lambda*c[i];
            g[i+1] = g[i+1] - lambda*g[i];
        }
        v[v.size-1] = g[v.size-1]/b[v.size-1]
        for (int i = v.size-2; i >= 0 ; i--)
        {
            v[i] = g[i]/b[i] - c[i]*v[i+1]
        }
        return v
    }