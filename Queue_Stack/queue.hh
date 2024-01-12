#ifndef __QUEUE_HH__
#define __QUEUE_HH__

#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue {
private:
  list<T> storage;
public:
  Queue() {}
  void push(T elem) { storage.push_back(elem); }
  void pop() { storage.pop_front(); }
  T& front() { return storage.front();}
  const T& front() const { return storage.front(); }
  int size() const { return storage.size(); }
  bool empty() const { return storage.empty();}
};

#endif
