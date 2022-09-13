#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

using namespace std;


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
int write(int n_step){
    int n = n_step-1;
    int i;
    double h = 1.0/n_step;
    vector<double> a(n-1, -1), b(n, 2), c(n-1, -1), v(n), g(n), x(n_step+1);

    for(i=0; i<n; i++)
        g[i] = 100*exp(-10*(i+1)*h)*(h*h);
        
    if(Thom_algr(n, a, b, c, g, v) == 0)
    {
        v.insert(v.begin(), 0);
        v.insert(v.end(), 0);
    }
    else 
    {
        cout << "Invalid array length\n";
        return 0;
    }

    ofstream filex("problem9_x"+to_string(n_step)+".txt", ios::app);
    ofstream fileu("problem9_v"+to_string(n_step)+".txt", ios::app);
    for(i=0; i<n_step+1; i++)
    {
        x[i] = i*h;
        filex << x[i] <<" ";
        fileu << v[i] <<" ";
    }
    return 0;
}
int main()
{
    write(10);
    write(100);
    write(1000);

    return 0;
}