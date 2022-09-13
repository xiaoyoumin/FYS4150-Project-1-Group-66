
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include<fstream>

using namespace std;



double f_func(double h, double x){
    return h*h*100*exp(-10*x);
}

vector<double> g_func(int n, double h, vector<double> x){ 
    vector<double> g1;
    for (int i=0; i<=n; i++){
        g1.push_back(f_func(h, x[i]));
    }
    return g1;
}


void print(string a){//print function used for debugging
    cout<<a<<endl;
}
void print(double a){//print function used for debugging
    cout<<to_string(a)<<endl;
}

void print(int a){//print function used for debugging
    cout<<to_string(a)<<endl;
}

void print(vector<double> a){//print function used for debugging
    for (int i=0;i<=a.size()-2;i++){

        cout << to_string(a.at(i)) << ' ';
    }
    cout << to_string(a[a.size()-1]) <<endl;
}

vector<double> Sub(vector<double> a, vector<double> b, vector<double> c, vector<double> x){//Substitution function

    //Forward substitution
    int n=x.size();
    vector<double> g=g_func(n, 2.0, x);
    vector<double> gt;//g tilde
    vector<double> v;
    vector<double> bt;//b tilde
    for (int i=0; i<=n-1;i++){
        v.push_back(0);
    }

    bt.push_back(b[0]);
    for (int i=1; i<=b.size()-1;i++){
        bt.push_back(b[i]-a[i]*c[i-1]/b[i-1]);
    }

    gt.push_back(g.at(0));
    for (int i=1; i<=n-1;i++){
        gt.push_back(g.at(i)-a[i]*g.at(i-1)/b[i-1]);
    }
    for (int i=0; i<=n-1;i++){
        a[i]=0;
    }

    //Back substitution
    v[n-1]=(gt[n-1]/bt[n-1]);
    for (int i=v.size()-2; i>=0; i--){
        v[i]=(gt[i]-c[i]*v[i+1])/bt[i];
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
  ofstream filex("problem7_x"+to_string(n)+".txt", ios::app);
  for (int i=0; i<x.size()-1; i++){
  filex << to_string(x[i]) << " ";
  }  

  //set diagonals for matrix A
  vector<double> a;
  for (int i=0; i<x.size()-1; i++) a.push_back(-1);

  vector<double> b;
  for (int i=0; i<x.size(); i++) b.push_back(2);

  vector<double> c;
  for (int i=0; i<x.size()-1; i++) c.push_back(-1);

  return Sub(a, b, c, x);
}
void writeVX(int n){//starts the code by initializing the v vector and writing it to file
  vector<double> v1=v(n);
  
  ofstream filev("problem7_v"+to_string(n)+".txt", ios::app);
  for (int i=0; i<v1.size()-1; i++){
  filev << to_string(v1[i]) << " ";
  }
}
int main()
{

  writeVX(10);

  writeVX(100);

  writeVX(1000);

  cout << "Code Finished!";

  return 0;
}