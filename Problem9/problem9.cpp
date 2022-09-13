#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

using namespace std;


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

int main()
{
    for(n_step = 10; n_step <1001;n_step = n_step*10)
    {
        int n_step = 100;
        int n = n_step-1;
        int i;
        double h = 1.0/n_step;
        vector<double> v(n), g(n), x(n_step+1);

        for(i=0; i<n; i++)
            g[i] = 100*exp(-10*(i+1)*h)*(h*h);
            
        simp_Thom_algr(n, g, v);
            
        v.insert(v.begin(), 0);
        v.insert(v.end(), 0);
        
        ofstream file("problem9_"+to_string(n_step)+".txt", ios::app);
        for(i=0; i<n_step+1; i++)
        {
            x[i] = i*h;
            file << x[i] <<"\t" << v[i] <<"\n";
        }
    }
    return 0;
}