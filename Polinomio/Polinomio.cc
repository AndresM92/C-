#include "list2.hh"
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

class Term {
private:
  int coeff;
  int expo;

public:
  Term() {}
  Term(int c, int e) : coeff(c), expo(e) {}
  int getExpo() const { return expo; }
  int getCoeff() const { return coeff; }

  int eval(int v) const { //
    return coeff * (pow(v, expo));
  }

  Term mult (const Term& t) const{
    return Term (getCoeff()* t.getCoeff(),getExpo()+ t.getExpo());
  }

};

ostream &operator<<(ostream &os, const Term &t) {
  os << t.getCoeff() << "*x^" << t.getExpo();
  return os;
}

class Poly {
private:
  List<Term> poly;

public:
  Poly() : poly() {}

  int n=0;
  void addTerm(Term t) { //

    if(poly.isEmpty()){
      poly.push_back(t);
      n= t.getExpo();
    }else{
      if(t.getExpo()<n){
        poly.push_front(t);
        n=t.getExpo();
      }else{
          poly.push_back(t);
        }
    }
  }

  void print() const { //
    poly.print();
  }


  int degree() const { //
    return poly.front().getExpo();
  }

  int eval(int v) const {
    int r = 0;
    List<Term> p(poly);
    while (!p.isEmpty()) {
      const Term &f = p.front();
      r = r + f.eval(v);
      p.pop_front();
    }
    return r;
  }

  Poly add1(const Poly &other) const {//Suma de polinomios
    Poly r;
    List<Term> p(poly);
    List<Term> q(other.poly);
    while (!p.isEmpty() && !q.isEmpty()) {
      const Term &fp = p.front();
      const Term &fq = q.front();
      if (fp.getExpo() == fq.getExpo()) {
        Term n(fp.getCoeff() + fq.getCoeff(), fp.getExpo());
        r.addTerm(n);
        p.pop_front();
        q.pop_front();
      } else if (fp.getExpo() < fq.getExpo()) { //
        Term n(fp.getCoeff(), fp.getExpo());
        r.addTerm(n);
        p.pop_front();
      } else {
        Term n(fq.getCoeff(), fq.getExpo());
        r.addTerm(n);
        q.pop_front();
      }
    }
    while (!p.isEmpty()) {
      const Term &fp = p.front();
      Term n(fp.getCoeff(), fp.getExpo());
      r.addTerm(n);
      p.pop_front();
    }
    while (!q.isEmpty()) {
      const Term &fq = q.front();
      Term n(fq.getCoeff(),fq.getExpo());
      r.addTerm(n);
      q.pop_front();
    }
    return r;
  }

 Poly mult ( const Term & t )const{//multiplica un termino con un polinomio
   Poly r;
   List<Term> p(poly);
   while(!p.isEmpty()){
     const Term &z= p.front();
      r.addTerm(t.mult(z));
      p.pop_front();
   }
   return r;
 }

 Poly mult(const Poly& other) const {//multiplica un polinomio con otro polinomio y lo suma
   Poly r;
   List<Term> p(poly);
   //List<Term> q(other.poly);
   while(!p.isEmpty()) {
     const Term& tp = p.front();
     Poly t = other.mult(tp);
     cout << "t: ";
     t.print();
     r = r.add1(t);
     cout << "r: ";
     r.print();
     p.pop_front();
   }

   return r;
 }

};

int main() {
  cout << "Polinomios" << endl;

  Term t1(4,6);
  Term t2(2, 1);
  Term t3(5, 2);

  Poly p;
  p.addTerm(t3);
  p.addTerm(t1);
  p.addTerm(t2);
  p.print();

  Term q0(8,9);
  Term q1(5, 4);
  Term q2(3, 1);

  Poly q;
  q.addTerm(q1);
  q.addTerm(q0);
  q.addTerm(q2);
  q.print();

/*
  Poly r = p.add1(q);
  cout<<"Sumados es: "<<endl;
  r.print();
  cout<<endl;
  cout<<"multiplicados es: "<<endl;
  */

  Poly r = p.mult(q);
  r.print();
  return 0;
}
