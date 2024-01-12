#include <unistd.h>
#include <iostream>
#include <string>
#include "singlelinkedlist.hh"
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
	os << s.getTitle();
	return os;
}

int main() {
	Music yolo;
	SingleLinkedList<Song> playlist;
	playlist.push_back(Song("Imagine", 3.0, "song3.ogg"));
	playlist.push_back(Song("Bohemian Rapsody", 3.0, "song2.ogg"));
	
	for(int i = 0; i < playlist.getSize(); i++) {
		playlist.at(i).play(yolo);
		usleep(10000);
		yolo.Stop();
		cout << "Next song!!" << endl;
	}
	
	//m.Pause();
	cout << "Hola listas\n";
	
	int i;
	cin >> i;
	/*
	SingleLinkedList<int> f;
	f.push_back(0);
	cout << f.find(0) << endl;
	* */
	/*
	SingleLinkedList<Point2D> figure;
	//figure.pop_back();
	figure.push_back(Point2D(0.0,10.0));
	figure.push_back(Point2D(1.0,10.0));
	figure.print();
	
	cout << figure.find(Point2D(1.0,3.1415)) << endl; 
	* */
	/*
	for (int i = 0; i < 10; i++) {
		figure.push_back(Point2D(3.9*i, 5.0*i));
	}
	figure.print();
	cout << figure.getSize() << endl;
	*/
	//figure.print();
	/*
	
	SingleLinkedList<Song> playlist;
	playlist.push_back(Song("Perdon", 5.3, "John"));
	playlist.print();
	 */
	return 0;
}
