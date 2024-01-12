#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<dos.h>
using namespace std;


void pos(int x,int y)//funcion para ubicar
{

  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X=x;
  dwPos.Y=y;
  SetConsoleCursorPosition(hcon,dwPos);

}

void color (int c)//Funcion para darle color 
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),c);
}

//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------
void cuadro1()//funcion cuadro de fondo
{
   for(int x=3;x<=75;x++)
	{	
		for(int y=3;y<=48;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),248);
	  		cout<<(char)219<<endl;
		}
	}	
}

//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------

void cuadro2()//funcion cuadro del usuario
{
	for(int x=6;x<=72;x++)
	{	
		for(int y=5;y<=19;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),47);
	  		cout<<(char)219<<endl;
		}
	}
	
	int cont=4,c=223;
	while(cont<=19)//Linear la parte superioir e inferior
	{
		for(int x=6;x<=72;x++)
		{	
			for(int y=cont;y<=cont;y++)
			{
				HANDLE hcon;
	  			hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  			COORD dwPos;
	  			dwPos.X=x;
	  			dwPos.Y=y;
	  			SetConsoleCursorPosition(hcon,dwPos);
	  			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
	  			cout<<(char)c<<endl;
			}
		}
		cont=cont+15;
		c=c-3;
	}
	
	cont=5,c=223;
	while(cont<=72)//Linear la parte superioir e inferior
	{
		for(int y=4;y<=19;y++)
		{	
			for(int x=cont;x<=cont;x++)
			{
				HANDLE hcon;
	  			hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  			COORD dwPos;
	  			dwPos.X=x;
	  			dwPos.Y=y;
	  			SetConsoleCursorPosition(hcon,dwPos);
	  			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),241);
	  			cout<<(char)219<<endl;
			}
		}
		cont=cont+67;
		c=c-3;
	}
}

//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------

void cuadro3()//funcion cuadro del teclado numerico
{
    for(int x=6;x<=36;x++)
	{	
		for(int y=22;y<=46;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),247);
	  		cout<<(char)219<<endl;
		}
	}
	
	for(int x=7;x<=15;x++)
	{	
		for(int y=23;y<=27;y++)
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
	pos(11,25);color(47);cout<<"1";
	
	for(int x=17;x<=25;x++)
	{	
		for(int y=23;y<=27;y++)
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
	pos(21,25);color(47);cout<<"2";
	
	for(int x=27;x<=35;x++)
	{	
		for(int y=23;y<=27;y++)
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
	pos(31,25);color(47);cout<<"3";
	
	for(int x=7;x<=15;x++)
	{	
		for(int y=29;y<=33;y++)
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
	pos(11,31);color(47);cout<<"4";
	
	for(int x=17;x<=25;x++)
	{	
		for(int y=29;y<=33;y++)
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
	pos(21,31);color(47);cout<<"5";
	
	for(int x=27;x<=35;x++)
	{	
		for(int y=29;y<=33;y++)
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
	pos(31,31);color(47);cout<<"6";
	
	for(int x=7;x<=15;x++)
	{	
		for(int y=35;y<=39;y++)
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
	pos(11,37);color(47);cout<<"7";
	
	for(int x=17;x<=25;x++)
	{	
		for(int y=35;y<=39;y++)
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
	pos(21,37);color(47);cout<<"8";
	
	for(int x=27;x<=35;x++)
	{	
		for(int y=35;y<=39;y++)
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
	pos(31,37);color(47);cout<<"9";
	
	for(int x=7;x<=15;x++)
	{	
		for(int y=41;y<=45;y++)
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
	pos(11,43);color(47);cout<<"0";
	
		
	for(int x=17;x<=35;x++)
	{	
		for(int y=41;y<=45;y++)
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
	pos(24,43);color(47);cout<<"ENTER";
}

//------------------------------------------------------&&&&&&&&&-----------------------------------------------------------------------------

void cuadro4()//Funcion cuadros de depositos
{
	for(int x=40;x<=73;x++)//Ciclo para retirar efectivo
	{	
		for(int y=22;y<=30;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),247);
	  		cout<<(char)219<<endl;
		}
	}
	pos(47,24);color(113);cout<<"TOME AQUI EL EFECTIVO";
	
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
	
	for(int x=40;x<=73;x++)//Ciclo para insertar deposito
	{	
		for(int y=38;y<=46;y++)
		{
			HANDLE hcon;
	  		hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	  		COORD dwPos;
	  		dwPos.X=x;
	  		dwPos.Y=y;
	  		SetConsoleCursorPosition(hcon,dwPos);
	  		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),247);
	  		cout<<(char)219<<endl;
		}
	}
	pos(42,40);color(113);cout<<"INSERTE AQUI SOBRE EL DEPOSITO";
	
	for(int x=42;x<=71;x++)//linea 2 en rojo
	{	
		for(int y=43;y<45;y++)
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
}


/*int main()
{
  
  cuadro1();
  cuadro2();
  cuadro3();
  cuadro4();
 

  
  system("pause>nul");
  return 0;
}*/
