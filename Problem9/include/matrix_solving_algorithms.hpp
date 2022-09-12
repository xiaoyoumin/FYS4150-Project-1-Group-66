//
// A collection of algorithms for solving tridiagonal matrices
//

// First we add an "include guard". It ensures that this header file can 
// only end up being included *once* for the compilation of any given .cpp file
#ifndef __matrix_solving_algorithms__  
#define __matrix_solving_algorithms__

#include <vector>

// The general algorithm solves a vector equation Av=g for v where A is a tridiagonal
// matrix with a the super diagonal vector, b the diagonal vector and c the supra
// diagonal vector.
std::vector<double> general_algorithm(
    std::vector<double> a,
    std::vector<double> b,
    std::vector<double> c,
    std::vector<double> g);

// Algorithm two: adds 1000 to the input number in a twice as silly way
// void algorithm_two(double& result);

#endif  // end of include guard __utils_hpp__