#ifndef GOLFER_H
#define GOLFER_H

#include <string>
#include <iostream>

using namespace std;

class Song {

private:
    string artist;
    string title;
    int size;

public:
    Song();
    //Song(string name);
    Song(string artist, string title, int size);

    string getArtist() const
    { return artist; }

    void setArtist(string artistName)
    { artist = artistName; }

    string getTitle() const
    { return title; }

    void setTitle(string t)
    { title = t; }

    int getSize() const
    { return size; }

    void setSize(int h)
    { size = h; }

    bool operator <(Song const &rhs);
    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);

    //~Song();

};


ostream& operator << (ostream& out, const Song &g);


#endif