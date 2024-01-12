#ifndef __VECTOR_HH__
#define __VECTOR_HH__

#include <iostream>

using namespace std;

template <typename T>
class Vector{
private:
	T* storage;
	int size;
	int capacity;
	int cont;
public:
	Vector(){ // Construye un vector sin recibir el tamaño
		//cout<<"constructor\n";
		capacity = 7;
		size = 0;
		storage = new T[capacity];
		cont=0;
	}
	
	Vector(int cap) { //Construye un vector de tamaño cap ingresado por el usuario
		//cout << "Constructor - capacity!\n";
		capacity = cap;
		size = 0;
		storage = new T[capacity];
	}

	void resize(){// pide mas memoria en caso de que necesite
		
		if(size<capacity)return;
		//cout<<"resize..!\n";
		cont=cont+1;
		int newsize=size+(size/2);
		T* newStorage = new T[ newsize];
		for(int i=0; i<size; i++){
			newStorage[i]=storage[i];
		}
		delete [] storage;
		storage = newStorage;
		capacity = newsize;
		
	}
	
	void fitTosize(){
		T* newStorage = new T[size];
		for(int i=0; i<size; i++){
			newStorage[i]=storage[i];
		}
		delete [] storage;
		storage = newStorage;
		capacity = size;
	}
		
	int cont_resize(){return cont;}//contar cuantos llamados ha resize hace
	
	int sizeOf(){return size;}// retorna el tamaño del vector
	
	int desperdicio(){return capacity-size;}// retorna el despedicio de espacio en un vector
	
	T at (int pos){return storage[pos];}// retorna el elemento en una posicion
	
	
	void push_back(T elem){// ingresa un elemento al vector
		resize();
		storage[size] = elem;
		size++;
	}

};
#endif
