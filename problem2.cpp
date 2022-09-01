#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

using namespace std;

double Calc_ux(float x);

int main()
{
    vector<float> x;
    vector<double> u;
    float i;
    
    for(i=0; i<=1; i+=0.01)
        x.push_back(i);

    ofstream filex("problem2_x.txt", ios::app);
    ofstream fileu("problem2_u.txt", ios::app);

    for(i=0; i < x.size(); i++)
    {
        u.push_back(Calc_ux(x[i]));

        filex << x[i] <<" ";
        fileu << u[i] <<" ";
        
    }
    
    return 0;
}

double Calc_ux(float x)
{
    double u;
    u = 1-(1-exp(-10))*x-exp(-10*x);
    return u;

}