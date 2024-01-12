#include <iostream>
#include <string>
//#include <SMFL>
#include "singlelinkedlist.hh"



using namespace std;

class Point2D{
private:
	double x;
	double y;
public:
	Point2D(){x=0.0;y=0.0;}
	Point2D(double a, double b){x=a;y=b;}
	double getX()const {return x;}
	double getY()const {return y;}
};


ostream& operator << (ostream& os, const Point2D& p){// le digo a c una forma de imprimir
		os<<"("<<p.getX()<<","<<p.getY()<<")";
		return os;
	}

/*ostream& operator == (const Point2D& p,const Point2D& q){// le digo a c una forma de comparar
		return p.getX()== q.getX()&&  p.getY()== q.getY();
}*/



class song{
private:
	string name;
	double duration;
	string filename;
public:
	song(){
		name="no name";
		duration=0.0;
		filename="no file";
	}
	song (string n, double d, string fn){
		name=n;
		duration=d;
		filename=fn;
			
	}
	string getTitle () const {return name;}
};

ostream& operator << (ostream& os, const song& s){// le digo a c una forma de imprimir
		os<<s.getTitle();
		return os;
	}

int main(){
	
	/*Music m;
	m.OpenFromFile("song.ogg");
	//m.pause();
	*/
	cout<<"hola list "<<endl;
	
	SingleLinkedList<char>name;//crea la lista de tipo char
	
	name.push_back('Z');
	name.push_back('n');
	name.push_back('a');
	name.push_back('m');
	name.push_back('e');
	
	//name.print();
	name.find('l');
	
/*	cout<< name.getSize() <<endl;
	
	name.pop_back();
	
	name.pop_front();
	
	//name.print();
	
	cout<< name.getSize() <<endl;
	name.fine('l');
	
	SingleLinkedList<Point2D>figure;// puntos en el plano
	for(int i=0;i<10;i++)
	{
		figure.push_back(Point2D(3.9*i,5.0*i));
	}
	
	//figure.print();
	cout<< figure.getSize() <<endl;
	figure.pop_back();
	cout<< figure.getSize() <<endl;
	
	SingleLinkedList<song>playlist;// lista de canciones
	
	playlist.push_back(song("perdon",2.0,"jhon"));
	//playlist.print();*/

	return 0;
}
