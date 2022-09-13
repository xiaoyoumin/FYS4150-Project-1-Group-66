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
    
    for(i=0; i<=100; i++)
        x.push_back(i/100);


    ofstream file("problem2.txt", ios::app);
    for(i=0; i<101; i++)
    {
        u.push_back(Calc_ux(x[i]));

        file << x[i] <<"\t" << u[i] <<"\n";
    }
    
    return 0;
}

double Calc_ux(float x)
{
    double u;
    u = 1-(1-exp(-10))*x-exp(-10*x);
    return u;

}