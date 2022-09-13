
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <fstream>

using namespace std;



double f_func(double h, double x){
    return h*h*100*exp(-10*x);
}

vector<double> g_func(int n, double h, vector<double> x){ 
    vector<double> g1;
    for (int i=0; i<=n-1; i++){
        g1.push_back(f_func(h, x[i]));
    }
    return g1;
}

std::vector<double> special_algorithm(
    std::vector<double> x)
    {
        //Forward substitution
    int n=x.size();
    vector<double> g=g_func(n, 2.0, x);
    std::vector<double> v(n), gamma(n);
    
    gamma[0] = g[0];
    for (int i = 1; i < n; i++)
    {
        gamma[i] = gamma[i-1] + (i+1)*g[i];
    }
    v[n-1] = gamma[n-1]/(n+1);
    for (int i = n-2; i >= 0 ; i--)
    {
        v[i] = (gamma[i] + (i+1)*v[i+1])/(i+2);
    }
    return v;
    }

vector<double> linspace(double start, double end, int steps){
    vector<double> v;
    double delta=(end-start)/(steps-1);
    for (int i=0; i<=steps; i++){
        v.push_back(start+delta*i);
    }
    return v;
}
vector<double> v(int n){//initializes the x vector, writes it to file, and runs the substitution function to find v
  vector<double> x =linspace(0,1,n);
  ofstream filex("problem9_x"+to_string(n)+".txt", ios::app);
  for (int i=0; i<x.size()-1; i++){
  filex << to_string(x[i]) << " ";
  }  
  return special_algorithm(x);
}
void writeVX(int n){//starts the code by initializing the v vector and writing it to file
  vector<double> v1=v(n);
  
  ofstream filev("problem9_v"+to_string(n)+".txt", ios::app);
  for (int i=0; i<v1.size()-1; i++){
  filev << to_string(v1[i]) << " ";
  }
}
int main()
{

  //writeVX(10);

  //writeVX(100);

  //writeVX(1000);

  cout << "Code Finished!";

  return 0;
}