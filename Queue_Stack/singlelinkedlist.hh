#ifndef __SINGLE_LINKED_LIST_HH__
#define __SINGLE_LINKED_LIST_HH__

#include <iostream>
#include <cassert>

void failIf(bool c) {
	if(c) {
	  std::cerr << "Condition failed!!!\n";
	  assert(!c);
    }
}

using namespace std;

template<typename T>
class SingleLinkedList {
private:
	class Node {
	private:
		T data;
		Node* next;
	public:
		Node(T d) {	data = d; next = nullptr; }
		Node* getNext() { return next; }
		void setNext(Node *n) { next = n; }
		T getData() const { return data; }
		T& getData() { return data; }
	};

	Node *first;
	Node *last;
	int size;
public:
	SingleLinkedList() { 
		first = nullptr; 
		last = nullptr; 
		size = 0;
	}
	bool empty() { return first == nullptr; }
	int getSize() { return size; }
    void push_back(T elem) {
		Node* n = new Node(elem);
		if(empty()) {
			first = n;
		} else {
			last->setNext(n);
		}
		last = n;
		size++;
	}
	
	void pop_back() {
		failIf(empty());
		if(size==1){
			delete first;
			first=nullptr;
			last=nullptr;
		} else{
			Node* e=first;
			while(e->getNext()!= last){
				e=e->getNext();
			}
			last=e;
			delete e->getNext();
			last->setNext(nullptr);
	    }
	  
			   
	 size--;
	}
	
	void pop_front(){
		   failIf(empty());
		   if(size==1)
		   {
			   first=nullptr;
			   delete last;
			   last=nullptr;
			   size=0;
		   }
		   else{
			   Node* x=first;
			   first=first->getNext();
			   delete x;
		   }
		   size--;
	   }
	
	bool find(T elem) {
		if(empty()) return false;
		Node *x = first;
		while(x != nullptr) {
			if (x->getData() == elem) {
				return true;
			} 
			x = x->getNext();
		}
		return false;
	}	
	T& at(int pos) {
		failIf(pos >= size);
		failIf(empty());
		Node *x = first;
		for(int i = 0; i < pos; i++) {
			x = x->getNext();
		}
		return x->getData();
	}
	T& getFirst() {
		return first->getData();
	}
	void print() {
		if(empty()) return;
		Node* n = first;
		while(n != nullptr) {
			cout << " " << n->getData();
			n = n->getNext();
		}
		cout << endl;
	}
};

#endif
