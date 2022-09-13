#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

using namespace std;



int gaussAlgr(int n, vector<vector<double>> A, vector<double> g, vector<double> &v) //v is the return value of the function
{
    int c, r;// col ， row
    int i;
    vector<vector<double>> a = A;

    for(i=0; i<n; i++)
        a[i].push_back(g[i]);  //define Augmented matrix of the equation


    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;// Find the row of the current column, which has the largest absolute value
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) == 0) continue;// If the current maximum number of this column is 0 than no constraints in this col, This is a dependent column

        for (int i = c; i < n + 1; i ++ ) swap(a[t][i], a[r][i]); //Change the current line to the top (not the first line, but the r th line)
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];// Change the first number of the current row to 1. in order to simplified calculation
        for (int i = r + 1; i < n; i ++ )// Elimunate all numbers below the current row in the current column
            if (fabs(a[i][c]) > 0)// if already 0, not operation needed
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;// next row
    }

    if (r < n)// This means that the number of equations is not equal to the number of variables, Infinite solutions or no solutions
    {
        for (int i = r; i < n; i ++ )// 
            if (fabs(a[i][n]) > 0) //left hand side not equal to right
                return 2;  //no solution
        return 1;// or infinite solution
    }
    // unique solution, do Back Substitution
    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[j][n] * a[i][j];

    for (int i = 0; i < n; i++) v[i] = a[i][n];

    return 0;  
}



int main()
{
    int n_step = 100;
    int n = n_step-1;
    vector<vector<double>> A(n, vector<double>(n, 0));
    double h = 1.0/n_step;
    vector<double> v(n), g(n), x(n_step+1);

    int i;

    for(i=0; i<n; i++)
    {
        g[i] = 100*exp(-10*(i+1)*h)*(h*h);
        A[i][i] = 2;
        if(i>0) A[i][i-1] = -1;
        if(i<n-1) A[i][i+1] = -1;
    }
        


    if(gaussAlgr(n, A, g, v) == 0)
    {
        v.insert(v.begin(), 0);
        v.insert(v.end(), 0);
    }
    else 
    {
        cout << "Invalid A matrix defination\n";
        return 0;
    }


    ofstream filex("problem7_x.txt", ios::app);
    ofstream fileu("problem7_v.txt", ios::app);
    for(i=0; i<n_step+1; i++)
    {
        x[i] = i*h;
        filex << x[i] <<" ";
        fileu << v[i] <<" ";
    }

    return 0;
}