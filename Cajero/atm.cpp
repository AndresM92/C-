#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string.h> 
#include <fstream>
#include <conio.h>
#include "cajero.h"
using namespace std;

struct clientess
{
	char num[6];
	char npi [6]; //1.000.000
	int dolares;
	int cajero;
};

char cadena[10];
clientess c[5];

void archivo1()//crea el archivo1 para para los clientes
{
	ofstream cli("clientes.txt");
	char nombre[20],nip[10],numero[20];
	if(cli.is_open())
	{
		
	/*	cli<<"\t NPI \t";
		cli<<"\t numero de cuenta \t\n";*/
		cli<<"\t 12345 \t";
		cli<<"\t 78900 \t";
		cli<<"\t 135000 \t\n";
		cli<<"\t 67890 \t";
		cli<<"\t 12345 \t";
		cli<<"\t 10000 \t\n";
		
		cli.close();
		cli.clear();
	}
}

void archivo2()//crea el archivo2 el cuanto tiene el banco
{
	ofstream ban("banco.txt");
	if(ban.is_open())
	{
		ban<<"\t 1000000 \t";
		
		ban.close();
		ban.clear();
	}
}

void leerarchivo2()//lee el archivo2 del banco
{
	
	ifstream ban;
	ban.open ("banco.txt");
	if (ban.good())
	{
		//cout<<"El archivo fue abierto correctamente..."<<endl;
	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;
		
	}
	int i=0;
	while(!ban.eof())
	{
	  ban>>cadena;
	  c[i].cajero=atoi(cadena);
	  i=i+1;
    }
    //close permite cerrar el archivo
	ban.close();	
}

void leerarchivo1()//lee el archivo1 de clientes
{
	
	ifstream cli;
	cli.open ("clientes.txt");
	//good indica si la operacion de abrir el archivo fue exitosa
	//bad indica produjo una operacion invalida
	//fail indica si se produjo un error
	if (cli.good())
	{
		//cout<<"El archivo fue abierto correctamente..."<<endl;
	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;
		
	}
	//eof () Produce un 1 si se encuentra en el final del archivo
	// !cli.eof() indica que no esta en el final del archivo
	int i=0;
	while(!cli.eof())
	{
	  cli>>cadena;
	  strcpy(c[i].num,cadena);
      cli>>cadena;
	  strcpy(c[i].npi,cadena);	  
      cli>>cadena;
	  c[i].dolares=atoi(cadena);
	  i=i+1;
    }
    //close permite cerrar el archivo
	cli.close();	
}
//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------

void retiro(int m)
{
	int opcion=0,canti=0,cajero;
	pos(7,6);color(242);printf("Opciones de retiro: ");
	pos(10,8);color(242);printf("[1]-$20");
	pos(10,10);color(242);printf("[2]-$40");
	pos(10,12);color(242);printf("[3]-$60");
	pos(22,8);color(242);printf("[4]-$100");
	pos(22,10);color(242);printf("[5]-$200");
	pos(22,12);color(242);printf("[6]-Cancelar transaccion");
	pos(7,15);color(242);printf("Elija una opcion de (1-6): ");
	pos(33,15);color(242);scanf("%d",&opcion);
	cuadro2();
	if(opcion==1)
	{
		pos(10,8);color(242);printf("ingrese la cantidad:");
		pos(31,8);color(242);scanf("%d",&canti);
		canti=canti*20000;
		if(canti<=c[m].dolares)
		{
			c[0].cajero=c[0].cajero-canti;
			c[m].dolares=c[m].dolares-canti;
			pos(10,8);color(242);printf("La operacion se realizo con exito");	
			system("pause>nul");
		}
		else
		{
		  pos(10,8);color(242);printf("no tiene lo sufieciente para retirar");
		  system("pause>nul");
		}
	}
	if(opcion==2)
	{
		pos(10,8);color(242);printf("ingrese la cantidad:");
		pos(31,8);color(242);scanf("%d",&canti);
		canti=canti*40000;
		if(canti<=c[m].dolares)
		{
			c[0].cajero=c[0].cajero-canti;
			c[m].dolares=c[m].dolares-canti;
			pos(10,8);color(242);printf("La operacion se realizo con exito");	
			system("pause>nul");
		}
		else
		{
		  pos(10,8);color(242);printf("no tiene lo sufieciente para retirar");
		  system("pause>nul");
		}
	}
	if(opcion==3)
	{
		pos(10,8);color(242);printf("ingrese la cantidad:");
		pos(31,8);color(242);scanf("%d",&canti);
		canti=canti*100000;
		if(canti<=c[m].dolares)
		{
			c[0].cajero=c[0].cajero-canti;
			c[m].dolares=c[m].dolares-canti;
			pos(10,8);color(242);printf("La operacion se realizo con exito");	
			system("pause>nul");
		}
		else
		{
		  pos(10,8);color(242);printf("no tiene lo sufieciente para retirar");
		  system("pause>nul");
		}
	}
	if(opcion==4)
	{
		pos(10,8);color(242);printf("ingrese la cantidad:");
		pos(31,8);color(242);scanf("%d",&canti);
		canti=canti*200000;
		if(canti<=c[m].dolares)
		{
			c[0].cajero=c[0].cajero-canti;
			c[m].dolares=c[m].dolares-canti;
			pos(10,8);color(242);printf("La operacion se realizo con exito");
				
			system("pause>nul");
		}
		else
		{
		  pos(10,8);color(242);printf("no tiene lo sufieciente para retirar");
		  system("pause>nul");
		}
	}
	pos(10,10);color(242);printf("retire su dinero por favor:");
	for(int x=43;x<=71;x++)//linea 1 en rojo
	{	
		for(int y=27;y<29;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),242);
	  		cout<<(char)219<<endl;
		}
	}
	system("pause>nul");
	for(int x=43;x<=71;x++)//linea 1 en rojo
	{	
		for(int y=27;y<29;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),124);
	  		cout<<(char)219<<endl;
		}
	}
/*	ofstream cli;
	cli.open ("clientes.txt");
    if(cli.good())
    {
    	//cout<<"El archivo fue abierto correctamente..."<<endl;
    }
    else
    {
    	cout<<"El archivo no se pudo abrir..."<<endl;
    }
     
//    cin>>cadena;
//    escribir<<cadena;
	for (int i=0;i<2;i++)
	{
        //32 Espacio en blanco
        //10 Salto de Linea
        //9 Tabulador Horizontal
		cli<<c[i].num;
        cli<<(char)9; //Espacio en Blanco
    }
	cli.close();
}*/
}


//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------

/*void contra(char nip[6])
{
		int i=0;
	//	cout.flush();
		while(nip[i]!=5) 
    	{ 
			//Capturamos carácter 
        	nip[i]=getch();
			 
    		//Si es un carácter válido y no se ha sobrepasado el límite de 20 caracteres se imprime un asterisco 
        	if(nip[i]>32 && i<6) 
            { 
                putchar('*'); 
                i++; 
            } 
        	//Si se pulsa la tecla RETROCESO, se retrocede un carácter, se imprime un espacio para eliminar el asterisco y se vuelve a retroceder para que el siguiente asterisco se coloque a continuación del anterior. 
        	else 
			if(nip[i]==8 && i>0) 
            { 
                putchar(8); 
                putchar(' '); 
                putchar(8); 
                i--;  
            } 
		} 
		
    	cadena[i]='\0';
    	cout.flush();
		 
}*/



int main()
{
  	char num[6],nip[20],r[7];
  	int op=0,m,canti,opcion=0,cajero=0;
  	archivo1();
  	archivo2();
  	leerarchivo1();
  	cuadro1();
  	cuadro2();
  	cuadro3();
  	cuadro4();
  	while(op==0)
  	{
		pos(7,6);color(242);printf("BIENVENIDO..!");
  		pos(7,10);color(242);printf("INGRESE SU NUMERO DE CUENTA:");
  		pos(36,10);color(242);gets(num);
  		pos(7,14);color(242);printf("INGRESE SU NIP:");
		pos(22,14);color(242);gets(nip);

		for(int i=0;i<2;i++)
		{
			if(strcmp(nip,c[i].npi)==0&&strcmp(num,c[i].num)==0)
			{
			    m=i;//la variable m me permite mas aledante identificar el usuario
				op=op+1;
			}
		}
		if(op==0)
		{
			pos(7,17);color(242);printf("Datos incorrectos");
			pos(36,10);color(242);printf("           ");
			pos(22,14);color(242);printf("           ");
			system("pause>nul");
			pos(7,17);color(242);printf("                     ");
		}		
	}
	while(op!=4)
	{
		cuadro2();
  		pos(7,6);color(242);printf("MENU PRINCIPAL:");
  		pos(10,8);color(242);printf("[1].Ver mi saldo");
  		pos(10,10);color(242);printf("[2].Retirar afectivo");
  		pos(10,12);color(242);printf("[3].Depositar fondos");
  		pos(10,14);color(242);printf("[4].Salir");
  		pos(7,14);color(242);printf("Escriba una opcion: ");
  		pos(27,14);color(242);scanf("%d",&op);
  		cuadro2();
  		switch(op)
  		{
			case 1:
			  	 pos(10,8);color(242);printf("Su saldo es: %d dolares",c[m].dolares);
			  	 pos(10,10);color(242);printf("Volver al menu inicial marque 1: ");
			  	 pos(43,10);color(242);scanf("%d",&op);
			  	 break;
			case 2:
			  	 retiro(m);
				 break;
		 /*  case 3:
			  	 depositar(m);
				 break;*/
				 
			default:
				printf("Salio satisfactariamente gracias");
			
		}
	}

  system("pause>nul");
  return 0;
}
