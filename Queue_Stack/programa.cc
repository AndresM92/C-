#include <unistd.h>
#include <iostream>
#include <string>
#include "queue.hh"
#include "stack.hh"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Point2D {
private:
  double x;
  double y;
public:
  Point2D() {x = 0.0; y = 0.0; }
  Point2D(double a, double b) { x = a; y = b; }
  double getX() const { return x; } 
  double getY() const { return y; } 
};

ostream& operator << (ostream& os, const Point2D& p) {
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

bool operator == (const Point2D& p, const Point2D& q) {
	return p.getX() == q.getX() && p.getY() == q.getY();
}

class Song {
private:
  string name;
  double duration;
  string fileName;
public:
  Song() {
	  name = "no name";
	  duration = 0.0;
	  fileName = "no file";
  }
  void setTime(double d) { duration = d; }
  
  double getTime() const {return duration; }
  
  Song(string n, double d, string fn) {
	  name = n;
	  duration = d;
	  fileName = fn;
  }
  string getTitle() const { return name; }
  void play(Music& m) {
	  m.OpenFromFile(fileName);
	  m.Play();
  }
};

ostream& operator << (ostream& os, const Song& s) {
	os << s.getTitle() << " -> " << s.getTime();
	return os;
}

int main() {
	Stack<Song> play;
	cout << play.size() << endl;
	play.push(Song("sol solecito", 5.2, "sol.ogg"));
	play.push(Song("las vocales", 5.2, "vocales.ogg"));
	play.push(Song("la iguana", 5.2, "iguana.ogg"));
	play.push(Song("sol solecito", 5.2, "sol.ogg"));
	play.push(Song("los pollitos", 5.2, "pollitos.ogg"));
	play.push(Song("la araña", 5.2, "araña.ogg"));
	play.push(Song("el mamut", 5.2, "mamut.ogg"));
	cout << play.size() << endl;
	cout << play.top().getTime() << endl;
	play.top().setTime(4.0);
	cout << play.top().getTime() << endl;
	
	/*
	while(!play.empty()) {
		Song s = play.front();
		//play.pop();
		cout << s << endl;
	}*/
	return 0;
}
