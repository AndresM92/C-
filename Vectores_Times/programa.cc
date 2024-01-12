#include <iostream>
#include <time.h>
#include <math.h>
#include "vector.hh"
#include <cstdlib> 

using namespace std;

int main(){

	double ini=0,cont1=0,final=0,time_=0,sum=0,prom=0,desvi=0;
	int cont2=0,alea;
	
	cout<<"hola vectores\n\n";
	Vector<char> nombre;
	Vector<int> numero;
	Vector<double> timesize(400);
	
	for(int k=0;k<400;k++){


		alea=rand () % 100+100000;
		
		ini=clock();// Comienza a contar el tiempo 00000
		for(int i=0; i<alea; i++){
			numero.push_back(i);
		}
		final=clock();// Finaliza de contar el tiempo

		time_=final-ini;
		timesize.push_back(time_);// almacena los tiempos en un vector
		cont2=cont2+numero.cont_resize();// almacena los llamados a resize
		
	}

	for(int l=0;l<400;l++){ // hace la suma de los tiempos 

		sum=sum+timesize.at(l);
		cont1=cont1+1;
	}
	
	prom=sum/cont1;// calcula el promedio de tiempo 

	for(int l=0;l<400;l++){ // Calcula la desviacion estandar 

		desvi=pow(timesize.at(l)-prom,2)+desvi;
	}

	desvi=sqrt(desvi);

	cout<<"El promedio del tiempo fue -> "<<prom<<endl;

	cout<<"La desviacion estandar fue -> "<<desvi<<endl;
	
	cout<<"El numero de llamados fue -> "<<cont2<<endl<<endl;
	

	//cout<< numero.sizeOf()<<endl;
	cout<< "El desperdicio fue ->"<<numero.desperdicio()<<endl;
	//cout<<numero.at(6)<<endl;
	//numero.fitTosize();
	//cout<< numero.desperdicio()<<endl;
	return 0;
}
