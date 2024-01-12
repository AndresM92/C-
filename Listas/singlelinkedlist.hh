#ifndef __SINGLE_LINKED_LIST_HH__
#define __SINGLE_LINKED_LIST_HH__


#include <iostream>
#include <cassert>

using namespace std;

//////////////////////////////////LISTAS////////////////////////////////////////////////////////////////////

template<typename T>
class SingleLinkedList{//constructor  de la lista 
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
		T getData() {return data ;}//retorna lo que hay en la lista
};
Node *first;
Node *last;
int size;
public:
	SingleLinkedList(){first=nullptr;size=0; last=nullptr;}//constructor de la lista
	
	bool empty(){return first==nullptr;}//retorna si esta vacia o no la lista
	
	void failif(bool c){assert (!c);}//Funcion que retorna si falla
	
	int getSize(){return size;}//retorna el tamaño de la lista
	
	void pop_back(){//elimina el ultimo elemnto de la lista
		failif(empty());
		if(size==1){
			delete first;
			first=nullptr;
			last=nullptr;
		}
		else{
			Node* e=first;
			while(e->getNext()!=last){
				e=e->getNext();
			}
			last=e;
			delete e->getNext();
			last->setNext(nullptr);
		}
		size--;
}
	
	void push_back(T elem){//Ingresa un elemento a la lista recibiendo el elmento
		Node* n=new Node(elem);
		if(empty()){
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
	
	void print(){//imprime lo que hay en la lista
		if(empty()) return;
		Node* n=first;
		while(n!=nullptr){
			cout<<" "<<n->getData();
			n=n->getNext();
		}
		cout<<endl;
	}

	void pop_front(){//elimina el  primer elemento de la lista
		failif(empty());
		if(size==1){first=nullptr;delete last;last=nullptr;size=0;}
		else{
			Node* x=first;
			first=first->getNext();
			delete x;
		}
		size--;
}

	bool find (T elem){//retorna si un elemento esta en la lista
		if(empty())return false;
		Node* x=first;
		while(x !=nullptr){
			if(x->getData()==elem){return true;}
			x=x->getNext();
		}
		return false;
}
		
		

	T at(int pos) {//retorna el elmenento apartir de una posicion
		//failif(pos>=size);
		failif(empty());
		Node* x=first;
		for(int i=0;i<pos;i++){
			x=x->getNext();
		}
		return x->getData();
	}
	
	
};


#endif
