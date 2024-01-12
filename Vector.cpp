#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class MyVector {
private:
  T *storage;//puntero de almacenamiento
  int size;//numero de elementos en el vector
  int capacity;//capacidad  del vector

public:
  // Constructs an empty vector
  MyVector() {
    storage = new T[5];
    size = 0;
    capacity = 5;
  }

  ~MyVector() { delete[] storage; }//destructor de la clase

  int getSize() const { return size; }//retorna el tamaño del vector

  void push_back(T elem) {//ingresa un elemento al vector al final
    if (size == capacity) {
      resize();
    }
    storage[size] = elem;
    size++;
  }

  void push_position(T elem,int n) {//ingresa un elemento al vector desde una posicion
    storage[n] = elem;
  }

private:
  void resize() {//aumenta el tamaño del vector sin parametros
    int newCapacity = capacity * 1.5;
    T *newStorage = new T[newCapacity];
    for (int i = 0; i < size; i++) {
      newStorage[i] = storage[i];
    }
    delete[] storage;
    storage = newStorage;
    capacity = newCapacity;
  }

  void new_resize(int n) {//aumentar el tamaño del vector con parametros
    int newCapacity = n;
    T *newStorage = new T[n];
    for (int i = 0; i < size; i++) {
      newStorage[i] = storage[i];
    }
    delete[] storage;
    storage = newStorage;
    capacity = newCapacity;
  }

public:

  int waste() const { return capacity - size; }//espacio sobrante en el vector

  T &operator [](int pos) {// devuelve el valor por referencia
    assert(pos>=0 && pos<size);
    return storage[pos];
  }

  const T &operator[](int pos) const {// modifica por referencia
    assert(pos>=0 && pos<size);
    return storage[pos];
  }

  void pop_back(){//saca el ultimo elemento del vector
    assert(size>0);
    size--;
  }

  void push_front (T elem){//ingresa un elemento en la primera posicion
    if(size==capacity){
      resize();
    }
    for(int i=size;i>0;i--){
      storage[i]=storage[i-1];
    }
    storage[0]=elem;
    size++;
  }

  void insert (T elem,int n){//insertar apartir de una posicion
    assert(size>0);
    if(capacity==size){resize();}

    for(int i=size;i>n;i--){
      storage[i]=storage[i-1];
    }
    push_position(elem,n);
    size++;
  }

  void pop_front(){//saca el primer elemento del vector
  for(int i=0;i<size;i++){
    storage[i]=storage[i+1];
  }
  size--;
  }

  void pop_posicion(int n){//saca un elemento desde una posicion
  //cout<<"hola"<<endl;
  for(int i=n;i<size;i++){
    storage[i]=storage[i+1];
    }
    size--;
  }

  void push_back(const MyVector<T> &other){///insertar los elementos de un vector en otro vector(al final)

    if(other.getSize()>(capacity-size)){new_resize(size+other.getSize());}

    for(int i=0;i<other.getSize();i++){
     // if(capacity==size){new_resize(size+other.getSize());}
      push_back(other[i]);
    }

  }

  void push_front(const MyVector<T> &other){///insertar los elementos de un vector en otro vector(al principio)

    if(other.getSize()>(capacity-size)){new_resize(size+other.getSize());}
    int n=0;
    for(int i=size;i>=0;i--){
      push_front(other[n]);
      n++;
    }
  }

  void erase(int r1,int r2){//borra los elementos del vector por rango
    for(int i=r2;i>=r1;i--){
      pop_posicion(i);
    }
  }

  void erase(int n){//borra un elemento desde una posicion
    pop_posicion(n);
  }

};

int main() {

  cout << "Vectors!!" << endl;
  MyVector<int> x;
  MyVector<int> y;

  for (int i = 0; i < 10; i++) {
    x.push_back((i*2));
    y.push_back(i);
  }

  //x[1] = 25;
  //y[1]=6;
  //cout << x[3] << endl;

  //x.pop_front();
  //y.pop_front();
  //x.insert(999,4);



  x.push_back(y);
  //y.push_front(x);

  y.erase(2);
  y.erase(4,8);
/*
  for (int i = 0; i < x.getSize(); i++) {
    cout<<x[i]<<endl;
  }
  cout<<endl<<""<<endl<<"";*/

  for (int i = 0; i < x.getSize(); i++) {
    cout<<x[i]<<endl;
  }
  cout<<endl;
  cout<<x.getSize()<<endl;

  return 0;
}
