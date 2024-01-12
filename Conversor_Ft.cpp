#include <cstdlib>
#include <iostream>

using namespace std;

float conver(int m)
{
    float p;
    p=39.27*m;
    return(p);
}

int main(int argc, char *argv[])
{
    int m;
    double pul;
    cout<<"ingrese los metros"<<endl;
    cin>>m;
    pul=conver(m);
    cout<<"las pulgadas son --> "<<pul<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
