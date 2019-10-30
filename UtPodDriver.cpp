/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
   UtPod outOfRange(1000);
   UtPod inRange(365);
   UtPod zero(0);
   UtPod Below(-2);
   cout << outOfRange.getTotalMemory() << " " << inRange.getTotalMemory() << " " << zero.getTotalMemory() << " " << Below.getTotalMemory() << endl;

   UtPod t;
   //cout << "Enter an artist, title, and song size" << endl;

   Song s0 ("big", "big", 513);
   t.addSong(s0);

   Song s1("Beatles", "Hey Jude1", 4);
   t.addSong(s1);
   Song s2("Beatles", "Hey Jude2", 5);
   t.addSong(s2);
   Song s3("ABBA", "test", 20);
   t.addSong(s3);
   Song s4("jkl", "fwohf", 3);
   t.addSong(s4);
   Song s5("qwer", "xcvn", 17);
   t.addSong(s5);

   Song s6("Beatles", "Hey Jude2", 6);
   Song s7("Beatles", "Hey Jude2", 7);
   Song s8("Beatles", "Hey Jude2", 7);
   Song s9("Beatles", "Hey Jude3", 7);
   Song s10("Beatles", "Hey Jude3", 7);
   Song s11("Beatles", "Hey Jude3", 5);
   Song s12("Beatles", "Hey Jude3", 8);
   Song s13("BTS", "Fake Love", 50);
   Song s14("Andy Mineo", "The Saints", 10);
   Song s15("andy mineo", "the saints", 2);
   Song s16("Lady Gaga", "Bad Romance", 3);
   Song s17("Kendrick Lamar", "i", 2);
   Song s18("Seventeen", "Mansae", 3);

   t.addSong(s6);
   t.addSong(s7);
   t.addSong(s8);
   t.addSong(s9);
   t.addSong(s10);
   t.addSong(s11);
   t.addSong(s12);
   t.addSong(s13);
   t.addSong(s14);
   t.addSong(s15);
   t.addSong(s16);
   t.addSong(s17);
   t.addSong(s18);
   t.showSongList();

   cout << "\nShuffle" << endl;
   t.shuffle();
   t.showSongList();

   cout << "\nSort" << endl;
   t.sortSongList();
   t.showSongList();

   cout <<"\nRemove and Add" << endl;
   t.removeSong(s4);
   t.addSong(s9);
   t.addSong(s9);
   t.removeSong(s9);
   t.removeSong(s1);
   t.removeSong(s10);
   t.showSongList();
   //t.removeSong(s1);

   t.clearMemory();
   t.addSong(s17);
   t.addSong(s17);
   t.addSong(s17);
   t.removeSong(s8);
   t.shuffle();
   t.sortSongList();
   cout <<"\nCleared memory and added song" << endl;
   t.showSongList();
   cout <<"\nRemove one song" << endl;
   t.removeSong(s17);
   t.showSongList();

   //t.clearMemory();
   //t.showSongList();
   //cout<< t.getRemainingMemory() <<endl;

   //t.addSong(s3);

   //t.showSongList();
   //cout<< t.getRemainingMemory() <<endl;



   //Song s2("Beatles", "Hey Jude2", 5);
   //cout << s1;

   /*if(s1 > s2){
      cout << "s1 after s2" << endl;
   }
   else if(s1 < s2){
      cout << "s1 before s2" << endl;
   }
   else if (s1 == s2){
      cout << "equal" << endl;
   }*/

   /*UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;*/
    

}