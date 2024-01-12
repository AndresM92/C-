
#ifndef __STACK_HH__
#define __STACK_HH__

#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Stack {
private:
  list<T> storage;
public:
  Stack() {}
  void push(T elem) { storage.push_back(elem); }
  void pop() { storage.pop_back(); }
  T& top() {
	  cout << "Con ampersand\n";
	   return storage.back();
  }
  const T& top() const { 
	    cout << "Con const y ampersand\n";
	  return storage.back(); 
  }
  int size() const { return storage.size(); }
  bool empty() const { return storage.empty();}
};

#endif
