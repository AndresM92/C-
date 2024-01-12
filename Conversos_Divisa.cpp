#include <cstdlib>
#include <iostream>

using namespace std;

float conversor(int e)
{
    float c,d;
    c=e*2619;
    d=c/1768;
    cout<<"Los pesos colombianos son "<<c<<endl;
    cout<<"Los dolares son "<<d<<endl;
}
int main(int argc, char *argv[])
{
    int e;
    cout<<"Ingrese los euros "<<endl;
    cin>>e;
    conversor(e);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
