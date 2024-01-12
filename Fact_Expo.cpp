#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int valor(int x,int n)//funcion elevar
{
   int i; 
   for(i=1;i<=n;i++){
                     x=x*x;
                     }                   
   return (x);
    
}

int factorial(int n)//funcion factorial
{
    int fac=1,i;
    for(i=1;n>=i;i++){
                      fac=fac*i;
                      }
    return (fac);
}

int main(int argc, char *argv[])
{
    int x,n,re;
  
    cout<<"Ingrese x"<<endl;
    cin>>x;
    cout<<"Ingrese n"<<endl;
    cin>>n;
    x=valor(x,n);
    n=factorial(n);
    re=x/n;
    cout<<"el resultado final es "<<re;
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
