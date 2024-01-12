#ifndef __VECTOR_HH__
#define __VECTOR_HH__

#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	T* storage;
	int size;
	int capacity;
public:
	Vector() {
		cout << "Constructor!\n";
		capacity = 10;
		size = 0;
		storage = new T[capacity];
	}
	Vector(int cap) {
		cout << "Constructor - capacity!\n";
		capacity = cap;
		size = 0;
		storage = new T[capacity];
	}
	void resize() {
	  if(size < capacity) return;
	  cout << "Resize!\n";
	  int newSize = size * 1.5;
	  T* newStorage = new T[newSize];
	  for(int i = 0; i < size; i++) {
		newStorage[i] = storage[i];
	  }
	  delete [] storage;
	  storage = newStorage;
	  capacity = newSize;
	}
	void fitToSize() {
	  T* newStorage = new T[size];
	  for(int i = 0; i < size; i++) {
		newStorage[i] = storage[i];
	  }
	  delete [] storage;
	  storage = newStorage;
	  capacity = size;
	}
	
	void push_back(T elem) {
		resize();
		storage[size] = elem;
		size++;
	}
	
	int sizeOf(){ return size;}
	
	int waste(){
		return capacity - size;
	}
	
	T at (int pos) {return storage[pos];}
	
	
};
#endif
