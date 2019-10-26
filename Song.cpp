#include "Song.h"

using namespace std;

/*Golfer::Golfer()
{
   name = "";
   eMail = "";
   handicap = MAX_HANDICAP;
}

Golfer::Golfer(string name)
{
   this->name = name;
   eMail = "";
   handicap = MAX_HANDICAP;
}*/

Song::Song()
{
   artist = "";
   title = "";
   size = 0;
}

Song::Song(string _artist, string _title, int _size)
{
   artist = _artist;
   title = _title;
   size = _size;
}

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

bool Song::operator ==(Song const &rhs)
{
   return (artist == rhs.artist &&
            title == rhs.title &&
           size == rhs.size);
}

Song::~Song()
{
   cout << "debug - in destructor for "<< artist <<endl;
}

ostream& operator << (ostream& out, const Song &g)
{
   out << g.getArtist() << " (" << g.getTitle() << ") - " << g.getSize();
   return out;
}
  

      