#include <time.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <iostream>


using namespace std;

int main()
{
    int N=10000;
    vector<double> b(N);
    vector<double> a(N*N);
    vector<double> c(N);
    //remplissage
    for (int i = 0; i < N; i++)
    {
      b[i]=rand();
      for (int j=0; j<  N; j++)
      {
        a[i+N*j]=rand();
      }
    }




    //version 1
    std::clock_t c_start = std::clock();

    for (int i = 0; i < N; i++)
    {
      c[i]=0.;
      for (int j=0; j<N; j++)
      {
        c[i]=c[i]+a[i*N+j]*b[j];
      }
    }

    std::clock_t c_end = std::clock();

    double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;

    std::cout <<"1 " <<time_elapsed_ms << " ms\n";




    //version 2
    std::clock_t c_start1 = std::clock();

    for (int i=0; i<N; N++)
    {
      c[i]=0.;
    }
    for (int i=0; i<N; i++)
    {
      for (int j=0; j<N; j++)
      {
        c[i]=c[i]+a[j+N*i]*b[i];
      }
    }

    std::clock_t c_end1 = std::clock();

    double time_elapsed_ms1 = 1000.0 * (c_end1-c_start1) / CLOCKS_PER_SEC;

    std::cout <<"2  "<< time_elapsed_ms1 << " ms\n";
}
