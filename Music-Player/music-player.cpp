
#include "list2.hh"
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;
using namespace sf;

class Song {
private:
  string fileName_;
  Music* soundDevice_;

public:
  Song()
      : soundDevice_(nullptr) {}
  Song(const string& fn, Music* sd)
      : fileName_(fn)
      , soundDevice_(sd) {}
  void play() const {
    if (!soundDevice_->openFromFile(fileName_)) {
      cerr << "Problem opening file " << fileName_ << endl;
      return;
    }
    soundDevice_->play();
  }
};

class Player {
private:
  List<Song> songs_;
  Music soundDevice_;
  int currentsong_;

public:
  Player(const string& fileName)
      : soundDevice_(),currentsong_(0) {
    ifstream is(fileName);
    string line;
    while (getline(is, line)) {
      Song s(line, &soundDevice_);
      songs_.push_back(s);
    }
    cout << "Read information of " << songs_.getSize() << endl;
  }
  void playFirst() {
    const Song& song = songs_.front();
    song.play();
    currentsong_++;
  }

  void playnext(){
    List<Song> c(songs_);
    int i=0;
    while(i !=currentsong_ && !c.isEmpty()){
      c.pop_front();
      i++;
    }
    if(c.isEmpty()){cout<<"last song player"<<endl;}
    else{
    c.front().play();
    currentsong_++;
    }
  }

};

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "Missing arguments." << endl << "./music songs.txt" << endl;
    return EXIT_FAILURE;
  }
  string songsFile(argv[1]);
  cout << "Music player" << endl;
  Player player(songsFile);
  bool close = false;

  while (!close) {
    cout << "Options: " << endl;
    cout << "\tshow: "
         << "Displays the files available to play" << endl;
    cout << "\tnext: "
         << "Plays the next song" << endl;
    cout << "\tquit: "
         << "Exits the player" << endl;
    string input;
    cin >> input;
    if (input == "show") {
      player.playFirst();
    } else if (input == "next") {
      player.playnext();
    } else if (input == "quit") {
      close = true;
    } else {
      cerr << "Option " << input << " not recognized" << endl;
    }
  }
  return 0;
}
