#include "Song.h"

using namespace std;

//default constructor
Song::Song()
{
   artist = "";
   title = "";
   size = 0;
}

//constructor where user passes in a valid artist, title, and size
Song::Song(string _artist, string _title, int _size)
{
   artist = _artist;
   title = _title;
   size = _size;
}

//overload for < symbol
bool Song::operator <(Song const &rhs)
{
   if(artist < rhs.artist){
      return true;
   }
   else if((artist == rhs.artist) && (title < rhs.title)){
      return true;
   }
   else if((artist == rhs.artist) && (title == rhs.title) && (size < rhs.size)){
      return true;
   }
   else{
      return false;
   }
}

//overload for > symbol
bool Song::operator >(Song const &rhs)
{
   if(artist > rhs.artist){
      return true;
   }
   else if((artist == rhs.artist) && (title > rhs.title)){
      return true;
   }
   else if((artist == rhs.artist) && (title == rhs.title) && (size > rhs.size)){
      return true;
   }
   else{
      return false;
   }
}

//overload for == symbol
bool Song::operator ==(Song const &rhs)
{
   return (artist == rhs.artist &&
            title == rhs.title &&
           size == rhs.size);
}

ostream& operator << (ostream& out, const Song &g)
{
   out << g.getTitle() << " - " << g.getArtist() << " - " << g.getSize() << " MB";
   return out;
}
