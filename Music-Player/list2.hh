#ifndef __LINKED_LIST_HH__
#define __LINKED_LIST_HH__


#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template<typename T>
class List{//constructor  de la lista
private:
	class Node {
	private:
		T data;
		Node* next;
	public:
		Node(T d){
			data=d;
			next=nullptr;
		}
		Node* getNext(){return next;}//Retorna el siguiente de la lista
		void setNext(Node *n){next=n;}//Apunta al siguiente
		const T& getData(void) const { return data; }
		T& getData(void) { return data; }
	};
	Node *first;
	Node *last;
	int size;
public:
	List(){first=nullptr;size=0; last=nullptr;}//constructor de la lista


  	List(const List<T>& other) {//Copia una lista
    	first = nullptr;
    	last = nullptr;
    	size= 0;
    	Node* t = other.first;
    	while (t != nullptr) {
      		push_back(t->getData());
      		t = t->getNext();
    	}
  	}

	bool isEmpty() const {return first==nullptr;}//retorna si esta vacia o no la lista

	int getSize(){return size;}//retorna el tamaño de la lista

	void push_back(T elem){//Ingresa un elemento a la lista recibiendo el elmento
		Node* n=new Node(elem);
		if(isEmpty()){
			first=n;
		}else{

			last-> setNext (n);
			/*Node* x=first;
			while(x->getNext() !=nullptr){x=x->getNext();}
				x->setNext(n);*/
			}
		last=n;
		size++;
	}

	void push_front(T elem) {//lo ingresa de primero
    	Node* e = new Node(elem);
    	if (isEmpty())
      		last= e;
    	else
      		e->setNext(first);
    	first= e;
    	size++;
  	}

  	void pop_front(void) {// saca de la lista el primero
    	assert(!isEmpty());
    	Node* t = first;
    	first= first->getNext();
    	delete t;
    	if (first== nullptr)
      		last= nullptr;
    		size--;
 	}

 	const T& front() const {
    	assert(!isEmpty()) ;
    	return first->getData();
  	}

  	T& front() {
    	assert(!isEmpty());
    	return first->getData();
  	}

	void print()const{//imprime lo que hay en la lista
		if(isEmpty()){
			cout<<"<>";
		}
		Node* n=first;
		cout<<"<";
		while(n!=nullptr){
			cout<<" "<<n->getData();
			n=n->getNext();
		}
		cout<<endl;
	}

	void pop_back(void) {
    	assert(!isEmpty());
    	Node* prev = first;
    	Node* t = first->getNext();
    	while (t->getNext() != nullptr) {
      		t = t->getNext();
      		prev = prev->getNext();
    	}
    	prev->setNext(nullptr);
    	delete t;
    	last = prev;
    	size--;
  }

	//void failif(bool c){assert (!c);}//Funcion que retorna si falla

	T at(int pos) {//retorna el elmenento apartir de una posicion
		//failif(pos>=size);
		assert(!isEmpty());
		Node* x=first;
		for(int i=0;i<pos;i++){
			x=x->getNext();
		}
		return x->getData();
	}
};


#endif
