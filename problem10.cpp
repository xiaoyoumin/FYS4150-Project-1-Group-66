#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include <time.h>

using namespace std;

//general algorithm
int Thom_algr(int n, vector<double> a, vector<double> b, vector<double> c, vector<double> g, vector<double> &v)
{
    vector<double> b_tilde(n), g_tilde(n);
    int i;

    //check illegal input
    if(a.size()!=n-1 || c.size()!=n-1 || b.size()!=n || g.size()!=n || v.size()!=n) return -1;

    b_tilde[0] = b[0];
    for(i = 1; i<n; i++)
        b_tilde[i] = b[i]-(a[i-1]*c[i-1])/b_tilde[i-1];

    g_tilde[0] = g[0];
    for(i=1; i<n; i++)
        g_tilde[i] = g[i]-(a[i-1]*g_tilde[i-1])/b_tilde[i-1];

    v[n-1] = g_tilde[n-1]/b_tilde[n-1];
    for(i=n-2; i>=0; i--)
        v[i] = (g_tilde[i]-c[i]*v[i+1])/b_tilde[i];

    return 0;
}


int simp_Thom_algr(int n, vector<double> g, vector<double> &v)
{
    vector<double> b_tilde(n), g_tilde(n);
    int i;

    b_tilde[0] = 2;
    for(i = 1; i<n; i++)
        b_tilde[i] = 2-((-1)*(-1))/b_tilde[i-1];

    g_tilde[0] = g[0];
    for(i=1; i<n; i++)
        g_tilde[i] = g[i]-((-1)*g_tilde[i-1])/b_tilde[i-1];

    v[n-1] = g_tilde[n-1]/b_tilde[n-1];
    for(i=n-2; i>=0; i--)
        v[i] = (g_tilde[i]-(-1)*v[i+1])/b_tilde[i];

    return 0;
}




int main ()   //code obtained from the code samples of the in4150 coursepage
{


    int n_step=10;
    int n = n_step-1;
    int i;
    double h = 1.0/n_step;
    
    double total=0, average;

    
  for(n_step = 10; n_step<=1000000; n_step=n_step*10)
  {
    n = n_step-1;
    h = 1.0/n_step;
    vector<double> v(n), g(n);

    for(i=0; i<n; i++)
        g[i] = 100*exp(-10*(i+1)*h)*(h*h);


    total=0;
  // Start measuring runtime for special algorithm 10 times
    cout <<"Special algorithm, n_step = "<< n_step <<"\n";
    for(i=0; i<10; i++)
    {
     clock_t t1 = clock();
  
      // The code you want to perform timing on
      simp_Thom_algr(n, g, v);

      // Stop measuring time
      clock_t t2 = clock();
      // Calculate the elapsed time.
      double duration_seconds = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
      total += duration_seconds;
    }
    average = total/10.0;
    cout << "total time of 10 runs: " << total << "\n" << "average time: " << average <<"\n";
  }
    

  cout <<"\n";


  for(n_step = 10; n_step<=1000000; n_step=n_step*10)
  {
    n = n_step-1;
    h = 1.0/n_step;
    vector<double> a(n-1, -1), b(n, 2), c(n-1, -1), v(n), g(n);

    for(i=0; i<n; i++)
        g[i] = 100*exp(-10*(i+1)*h)*(h*h);

        
    total=0;
  // Start measuring runtime for general algorithm 10 times
    cout <<"General algorithm, n_step = "<< n_step <<"\n";
    for(i=0; i<10; i++)
    {
     clock_t t1 = clock();
  
      // The code you want to perform timing on
      Thom_algr(n, a, b, c, g, v);

      // Stop measuring time
      clock_t t2 = clock();
      // Calculate the elapsed time.
      double duration_seconds = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
      total += duration_seconds;
    }
    average = total/10.0;
    cout << "total time of 10 runs: " << total << "\n" << "average time: " << average <<"\n";
  }

  

  return 0;
}
