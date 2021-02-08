#include <time.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <math.h>



using namespace std;

void charge_a(int n, int Np, int me, int& begin, int& end )
{
  int q=floor(n/Np);
  begin=end+1;
  end=begin+q-1;

}

void charge_b(int n, int Np, int me, int& begin, int& end)
{
  int q=floor(n/Np);
  begin=end+1;
  end=begin+q-1;
  if(me==12)
  {
    end=n-1;
  }
}

void charge_c(int n, int Np, int me, int& begin, int& end) //max - min=0
{
  int q=floor(n/Np)+1;
  begin=end+1;
  end=begin+q-1;
  if(me==12)
  {
    end=n-1;
  }

  
}


int main()
{
    int Np=5;
    int n=1000;
    int end,begin;
    end=-1;
    begin=-1;
    cout<<"distribution a"<<endl;
    for (int me=0; me<Np; me++)
    {
      charge_a(n,Np,me,begin,end);
      cout<<"charge du processeur "<<me<<" {"<<begin<<" , "<<end<<"}"<<" decompte "<<end-begin<<endl;
    }


    cout<<"distribution b"<<endl;
    Np=13;
    end=-1;
    begin=-1;
    for (int me=0; me<Np; me++)
    {
      charge_b(n,Np,me,begin,end);
      cout<<"charge du processeur "<<me<<" {"<<begin<<" , "<<end<<"}"<<" decompte "<<end-begin<<endl;
    }

    cout<<"distribution c"<<endl;
    Np=13;
    end=-1;
    begin=-1;
    for (int me=0; me<Np; me++)
    {
      charge_c(n,Np,me,begin,end);
      cout<<"charge du processeur "<<me<<" {"<<begin<<" , "<<end<<"}"<<" decompte "<<end-begin<<endl;
    }
    //cout<<"donner le nombre de processeurs!"<<endl;
    //cin>>Np;
    //cout<<"la distribution de charge pour "<<Np<<" processeurs"<<endl;
    return 0;
}
