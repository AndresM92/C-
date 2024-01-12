#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void unir(int a[5],int b[5])//funcion que llena los vectores y los une 
{
  int n,i,j=0;
  int c[5];
//--------------------------------------------------------------------------- 
  for(i=0;i<=5;i++)//llena el vector a
  {
   system("cls");
   system("color 1A");
   cout<<"ingrese el numero del vector 1"<<endl;
   cin>>n;
   a[i]=n;              
  }   
//--------------------------------------------------------------------------- 
  for(i=0;i<=5;i++)//llena el vector b
  {
   system("cls");
   system("color 1A");
   cout<<"ingrese el numero del vector 2"<<endl;
   cin>>n;
   b[i]=n;              
  }
//---------------------------------------------------------------------------

  for(i=0;i<=5;i++)//llena el vector c
  {
    if(i<=2)
    {
      c[i]=a[i];
    }
    if(i>2)
    {
     c[i]=b[j];
     j=j+1;
    }
   } 
//---------------------------------------------------------------------------   
   for(i=0;i<=5;i++)//muestra el vector c
   {
    cout<<c[i]<<" ";
   }
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void llenar(int a[9])//funcion que llena el vector
{
  int n,i,j=0,max=10000,min=-10000000,suma=0;
  float prome=0;
//--------------------------------------------------------------------------- 
  for(i=0;i<=9;i++)//llena el vector a
  {
   system("cls");
   system("color 1A");
   cout<<"ingrese el numero  "<<endl;
   cin>>n;
   a[i]=n;              
  } 
   system("cls");  
//---------------------------------------------------------------------------   
  for(i=0;i<=9;i++)//muestra el vector a
  {
   suma=suma+a[i];
   cout<<a[i]<<" ";
   }
//---------------------------------------------------------------------------   
  for(i=0;i<=9;i++)//halla el minimo
  { 
    if(a[i]<max)
    {
      max=a[i];
     }
   }
//---------------------------------------------------------------------------   
  for(i=0;i<=9;i++)//halla el maximo
  { 
    if(a[i]>min)
    {
      min=a[i];
     }
   } 
  cout<<endl;  
  cout<<endl;
  prome=suma/10;
  cout<<"el minimo es --> "<<max<<endl;
  cout<<"el maximo es --> "<<min<<endl;
  cout<<"la suma es --> "<<suma<<endl;
  cout<<"el promedio es --> "<<prome<<endl<<endl;
}
//---------------------------------------------------------------------------
int main() 
{
   int op;
   int a[5];
   int b[5];
   int a1[9];
	while(op!=0)
    {
	  system("cls");
	  system("color 09"); 	
      cout<<"같같같같같같같 MENU INICIAL 같같같같같같같같"<<endl<<endl;
      cout<<"1.Une 2 vectores en 1"<<endl;
      cout<<"2.Llena un vector y halla valor minimo, mayor, suma,promedio"<<endl;
	  cin>>op;
	  system("cls");
	  switch(op)
	  {
		case 1:
			   unir(a,b);
			   cout<<"Si no desea continuar marque 0 de lo contrario presione 1"<<endl;
	  		   cin>>op;
			   break;
	    case 2:
               llenar(a1);
			   cout<<"Si no desea continuar marque 0 de lo contrario presione 1"<<endl;
	  		   cin>>op;
			   break;
	    default:
			    cout<<"Ha salido satisfactoriamente"<<endl;
       }		   
}
	system("PAUSE>nul");
	return 0;
}
