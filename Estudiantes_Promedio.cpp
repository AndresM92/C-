#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct estudiante // Se declara la estrucura que se va a utilizar en el programa
{
	char codigo[4];
	char nombre[10];
	float n1,n2,n3;
};

estudiante e[3];
char c[5];

//-------------------------------------------------------------------------------------------------

void captura()//Funcion que permite capturar el codigo y las notas de los estudiantes
{
	float prome=0,sum=0;
	for(int i=0;i<3;i++)
	{
	  cout<<"Datos del estudiante # "<<i+1<<endl<<endl;
	  cout<<"Codigo: ";
	  cin>>e[i].codigo;
	  cout<<"Nombre: ";
	  cin>>e[i].nombre;
	  cout<<"Ingrese la nota 1 --> ";
	  cin>>e[i].n1;
	  cout<<"Ingrese la nota 2 --> ";
	  cin>>e[i].n2;	
	  cout<<"Ingrese la nota 3 --> ";
	  cin>>e[i].n3;
	  prome=(e[i].n1+e[i].n2+e[i].n3)/3;
	  sum=sum+prome;
	  cout<<"Su promedio es --> "<<prome<<endl;
	  cout<<endl;
	  system("pause");
	  system("cls");
	}
	sum=sum/3;
	cout<<"El promedio del grupo es "<<sum<<endl;
	system("pause");
	system("cls");
}
//-------------------------------------------------------------------------------------------------

void consulta(char cod[5])//Permite consultar todos los datos de los estudiantes 
{
   float prome=0;
   for(int i=0;i<3;i++)	
   {
	if(strcmp(cod,e[i].codigo)==0)
	{
	   cout<<"Nombre : "<<e[i].nombre<<endl;
	   cout<<"Nota 1 : "<<e[i].n1<<endl;
	   cout<<"Nota 2 : "<<e[i].n2<<endl;
	   cout<<"Nota 3 : "<<e[i].n3<<endl;
	   prome=(e[i].n1+e[i].n2+e[i].n3)/3;
	   cout<<"Su promedio es "<<prome<<endl;
	}
   }
   cout<<endl;
   system("pause");
   system("cls");
}
//-------------------------------------------------------------------------------------------------

void modificar(char cod[5])//Funcion para editar datos de los estudiante
{
	float prome=0;
	for(int i=0;i<3;i++)
	{
	  if(strcmp(cod,e[i].codigo)==0)
	  {
		cout<<"Nombre : "<<e[i].nombre<<endl;
		cout<<"Nota 1 : "<<e[i].n1<<endl;
		cout<<"Nota 2 : "<<e[i].n2<<endl;
		cout<<"Nota 3 : "<<e[i].n3<<endl;
		prome=(e[i].n1+e[i].n2+e[i].n3)/3;
		cout<<"Su promedio es "<<prome<<endl;	
	   }	
	}
    cout<<endl;
    system("pause");
    system("cls");
}
//-------------------------------------------------------------------------------------------------

void listar()//Funcion que permite listar los estudiantes
{
	float prome=0,sum=0;
	for(int i=0;i<3;i++)
	{
	  cout<<"Datos del estudiante # "<<i+1<<endl<<endl;
	  cout<<"Nombre: "<<e[i].nombre<<endl;
	  cout<<"Nota 1 --> "<<e[i].n1<<endl;
	  cout<<"Nota 2 --> "<<e[i].n2<<endl;
	  cout<<"Nota 3 --> "<<e[i].n3<<endl;
	  prome=(e[i].n1+e[i].n2+e[i].n3)/3;
	  sum=sum+prome;
	  cout<<"Su promedio es --> "<<prome<<endl;
	  cout<<endl;
	  sum=sum+prome;
	}
	sum=sum/3;
	cout<<"El promedio del grupo es "<<sum<<endl;
	system("pause");
	system("cls");
}
//-------------------------------------------------------------------------------------------------

void menu()//Menu principal del programa
{
	int op=0;
	while(op!=4)
	{
	  cout<<"Que opcion desea realizar "<<endl;	
	  cout<<"1.Consultar"<<endl;
	  cout<<"2.Modificar"<<endl;
	  cout<<"3.Listar"<<endl;
	  cout<<"4.Salir"<<endl;
	  cin>>op;
	  system("cls");
	  switch(op)
	  {
		case 1:
			  cout<<"Ingrese el codigo del estudiante al que desea consultar : ";
			  cin>>c;
			  consulta(c);
			  break;
		case 2:
			  cout<<"Ingrese el codigo del estudiante al que desea modificar : ";
			  cin>>c;
			  modificar(c);	
			  break;
		case 3:
			  listar();	  	    	
	  }	
	}
}
//-------------------------------------------------------------------------------------------------

int main() 
{
	captura();
	menu();
	
    system("pause>nul");
	return 0;
}
