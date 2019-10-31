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
   cout << endl;
   cout << "--- UTPOD SIZE TESTING ---" << endl;
   //TEST: UTPOD SIZE > 512
   UtPod outOfRange(1000);
   cout << "Memory of size > 512 test: " << outOfRange.getTotalMemory() << endl;
   //TEST: UTPOD SIZE IN RANGE
   UtPod inRange(365);
   cout << "Memory of size in range test: " << inRange.getTotalMemory() << endl;
   //TEST: UTPOD SIZE 0
   UtPod zero(0);
   cout << "Memory of size 0 test: " << zero.getTotalMemory() << endl;
   //TEST: UTPOD SIZE < 0
   UtPod Below(-2);
   cout << "Memory of size < 0 test: " << Below.getTotalMemory() << endl;
   //TEST USING THESE 2 UTPODS
   UtPod test512;
   UtPod test256(256);

   cout << endl;
   cout << "--- SONG SIZE TOO BIG TESTING ---" << endl;
   //TEST: SONG ONLY ADDED IF THERE IS ENOUGH SPACE
   Song s0 ("small", "llams", 255);
   Song s1("medium", "muidem", 10);
   Song s2 ("big", "gib", 513);
   int result = test256.addSong(s0);
   cout << "Song added if enough space (0 success): " << result << endl;
   result = test256.addSong(s1);
   cout << "Song added if enough space (-1 no memory): " << result << endl;
   test256.showSongList();
   result = test512.addSong(s2);
   cout << "Song added if enough space (-1 no memory): " << result << endl;
   result = test512.addSong(s1);
   cout << "Song added if enough space (0 success): " << result << endl;
   test512.showSongList();
   test512.clearMemory(); //TEST FOR CLEAR MEMORY
   test256.clearMemory();

   cout << endl;
   cout << "--- REMOVING SONGS TESTING ---" << endl;
   Song s3("One", "Six", 10);
   Song s4("Two", "Seven", 7);
   Song s5("Three", "Eight", 7);
   Song s6("Four", "Nine", 7);
   Song s7("Three", "Eight", 7);
   Song s8("Three", "Eight", 7);
   Song s9("Five", "Ten", 28);
   test256.addSong(s3);
   test256.addSong(s4);
   test256.addSong(s5);
   test256.addSong(s6);
   cout << "Song List: " << endl;
   test256.showSongList();
   //TEST: REMOVING SONGS THAT DON'T EXIST
   Song s10("Hundred", "Eight", 7);
   result = test256.removeSong(s10);
   cout << "Remove Song (-2 not found): " << result << endl;
   Song s11("Three", "Four", 7);
   result = test256.removeSong(s11);
   cout << "Remove Song (-2 not found): " << result << endl;
   Song s12("Three", "Eight", 9);
   result = test256.removeSong(s12);
   cout << "Remove Song (-2 not found): " << result << endl;
   //TEST: REMOVING FIRST AND LAST SONG
   cout << endl << "Removing first and last song... " << endl;
   test256.removeSong(s3);
   test256.removeSong(s6);
   test256.showSongList();
   //TEST: REMOVING A SONG WITH MULTIPLE COPIES OF THE SAME SONG
   test256.addSong(s3);
   test256.addSong(s4);
   test256.addSong(s5);
   test256.addSong(s6);
   test256.addSong(s7);
   test256.addSong(s8);
   test256.addSong(s9);
   cout << "Song List: " << endl;
   test256.showSongList();
   Song s13("Three", "Eight", 7);
   test256.removeSong(s13);
   cout << endl << "Removed one song out of multiple: " << endl;
   test256.showSongList();
   test256.removeSong(s7);
   test256.removeSong(s7);
   test256.removeSong(s7);
   test256.removeSong(s3);
   test256.removeSong(s4);
   test256.removeSong(s6);
   test256.removeSong(s9);
   cout << endl << "One Song left: " << endl;
   test256.showSongList();    //SHOW SONG LIST WORKS WITH ONE SONG
   //TEST: REMOVING SONG IN A LIST OF 0 AND 1 SONG
   test256.removeSong(s4);
   test256.showSongList();    //SHOW SONG LIST WORKS WITH 0 SONGS
   result = test256.removeSong(s4);
   cout << endl << "Removing song from 0 song list (-2 not found): " << result << endl;
   test256.showSongList();

   cout << endl << "--- SHUFFLE TESTING ---" << endl;
   test256.addSong(s3);
   test256.addSong(s4);
   test256.addSong(s5);
   test256.addSong(s6);
   test256.addSong(s9);
   cout << "Shuffle #1: " << endl;
   test256.shuffle();
   test256.showSongList();
   cout << endl << "Shuffle #2: " << endl;
   test256.shuffle();
   test256.showSongList();
   cout << endl << "Shuffle #3: " << endl;
   test256.shuffle();
   test256.showSongList();
   cout << endl << "Shuffle #4: " << endl;
   test256.shuffle();
   test256.showSongList();
   cout << endl << "Shuffle #5: " << endl;
   test256.shuffle();
   test256.showSongList();
   //TEST: SHUFFLE WITH 0, 1, 2 SONGS
   test256.removeSong(s9);
   test256.removeSong(s6);
   test256.removeSong(s5);
   cout << endl << "Shuffle these two songs: " << endl;
   test256.showSongList();
   cout << endl << "Shuffle 2 songs: " << endl;
   test256.shuffle();
   test256.showSongList();
   test256.removeSong(s4);
   cout << endl << "Shuffle 1 song: " << endl;
   test256.shuffle();
   test256.showSongList();
   test256.removeSong(s3);
   cout << endl << "Shuffle 0 songs: " << endl;
   test256.shuffle();
   test256.showSongList();

   cout << endl << "--- SORTING TESTING ---" << endl;
   test256.clearMemory();
   //TEST: SORT 1 SONG
   cout << "Sorting 1 song: " << endl;
   test256.addSong(s3);
   test256.sortSongList();
   test256.showSongList();
   //TEST: SORT 2 SONGS
   cout << endl << "Sorting 2 songs: " << endl;
   test256.addSong(s6);
   test256.sortSongList();
   test256.showSongList();
   //TEST: SORT WITH MUTIPLE SONGS BEING THE EXACT SAME
   cout << endl << "Sorting with multiple same songs: " << endl;
   test256.addSong(s4);
   test256.addSong(s5);
   test256.addSong(s7);
   test256.addSong(s8);
   test256.addSong(s9);
   test256.sortSongList();
   test256.showSongList();
   //TEST: SORT WITH SIZE DIFFERED ONLY
   cout << endl << "Sort with size different only: " << endl;
   Song s14("Three", "Eight", 9);
   test256.addSong(s14);
   test256.sortSongList();
   test256.showSongList();
   //TEST: SORT WITH ARTIST SAME ONLY
   cout << endl << "Sort with artist same only: " << endl;
   Song s15("Three", "Twenty", 9);
   test256.addSong(s15);
   test256.sortSongList();
   test256.showSongList();
   //TEST: SORT WITH ARTIST DIFFERENT ONLY
   cout << endl << "Sort with artist different only: " << endl;
   Song s16("Two", "Eight", 9);
   test256.addSong(s16);
   test256.sortSongList();
   test256.showSongList();

   cout << endl;
   cout << "--- REMAINING MEMORY TESTING ---" << endl;
   cout << "Remaining Memory: " << test256.getRemainingMemory() << endl;
   Song s17("Two", "Eight", 156);
   test256.addSong(s17);
   cout << "Remaining Memory when full: " << test256.getRemainingMemory() << endl;
   test256.clearMemory();
   cout << "Remaining Memory when empty: " << test256.getRemainingMemory() << endl;
   test256.showSongList();
}