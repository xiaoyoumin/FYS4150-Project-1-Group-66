#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include <time.h>

using namespace std;



int main ()   //code obtained from the code samples of the in4150 coursepage
{
  // Start measuring time
  clock_t t1 = clock();

  
  // The code you want to perform timing on
  

  // Stop measuring time
  clock_t t2 = clock();
  // Calculate the elapsed time.
  double duration_seconds = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
}
