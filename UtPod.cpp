//DOCUMENT HERE

#include "UtPod.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

//default constructor
//sets memory size to MAX_MEMORY
UtPod::UtPod() {
   memSize = MAX_MEMORY;
   songs = NULL;
   srand(time(0));
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
   if((size > MAX_MEMORY) || (size <= 0)) {     //Memory set to max if memory input out of range
      memSize = MAX_MEMORY;
   }
   else {
      memSize = size;
   }
   songs = NULL;
   srand(time(0));
}

/* FUNCTION - int addSong
  * attempts to add a new song to the UtPod
      o returns a 0 if successful
      o returns -1 if not enough memory to add the song

  precondition: s is a valid Song

  input parms - song passed by reference that cannot be changed

  output parms - song is added as a linked list node at the end of linked list
 */
int UtPod::addSong(Song const &s) {
   if(getRemainingMemory() >= s.getSize()) {
      SongNode *newSong;
      newSong = new SongNode;
      newSong->s.setArtist(s.getArtist());
      newSong->s.setTitle(s.getTitle());
      newSong->s.setSize(s.getSize());
      newSong->next = NULL;

      if(songs == NULL) {  //empty list of songs
         songs = newSong;
      }
      else {   //add song to end of linked list
         SongNode *traversePointer;
         traversePointer = songs;
         while(traversePointer->next != NULL){
            traversePointer = traversePointer->next;
         }

         traversePointer->next= newSong;
      }

      return SUCCESS;
   }
   else {
      return NO_MEMORY;
   }
}

 /* FUNCTION - int removeSong
  * attempts to remove a song from the UtPod
  * removes the first instance of a song that is in the the UtPod multiple times
      o returns 0 if successful
      o returns -1 if nothing is removed

    input parms - song passed by reference that cannot be changed

    output parms - song is removed from linked list if song is there
 */
 int UtPod::removeSong(Song const &s) {
    SongNode *leadPtr;
    SongNode *followPtr;
    SongNode *tempPtr;
    leadPtr = songs;
    followPtr = songs;

    //lead ptr traverses through linked list and followPter is one node behind leadPtr
    //Whenever we reach a song in the list that equals the song we want to remove, we use tempPtr to point to the node
    //we want to delete.  LeadPtr points to the node after the node to be deleted, FollowPtr points to the previous node

    if (songs != NULL) {
       while (leadPtr != NULL) {
          if ((songs->s.getArtist() == s.getArtist()) && (songs->s.getSize() == s.getSize()) && (songs->s.getTitle() == s.getTitle())){
             tempPtr = songs;             //If want to remove first song in list, move songs pointer to next node and delete first node
             songs = songs->next;
             delete tempPtr;
             leadPtr = songs;
             followPtr = songs;
             return SUCCESS;
          }
          else if ((leadPtr->s.getArtist() == s.getArtist()) && (leadPtr->s.getSize() == s.getSize()) && (leadPtr->s.getTitle() == s.getTitle())){
              tempPtr = leadPtr;          //Removing song that is not first node in list
              leadPtr = leadPtr->next;
              delete tempPtr;
              followPtr->next = leadPtr;
              return SUCCESS;
          }
          else{
              followPtr = leadPtr;
              leadPtr = leadPtr->next;
          }
       }
    }
    return NOT_FOUND;
 }

 /* FUNCTION - void shuffle
  *  shuffles the songs into random order
     o will do nothing if there are less than two songs in the current list

    input parms - none

    output parms - none
 */
 void UtPod::shuffle() {
    SongNode *traversePointer;
    traversePointer = songs;
    int numSongs = 0;
    if(songs != NULL){
       while (traversePointer != NULL){                     //Counting total number of songs
          numSongs++;
          traversePointer = traversePointer->next;
       }
    }
    for (int i = 0; i < (2*numSongs); i++){
       int ptrOneIndex = rand() % numSongs;                 //Point to 2 different nodes based off of random # generated
       int ptrTwoIndex = rand() % numSongs;
       SongNode *ptrOne = songs;
       SongNode *ptrTwo = songs;
       Song temp;
       for (int j = 0; j < ptrOneIndex; j++){               //traversing pointer One
          ptrOne = ptrOne->next;
       }
       for (int j = 0; j < ptrTwoIndex; j++){               //traversing pointer Two
          ptrTwo = ptrTwo->next;
       }
       temp = ptrTwo->s;
       ptrTwo->s = ptrOne->s;
       ptrOne->s = temp;
    }
 }

 /* FUNCTION - void showSongList
  * prints the current list of songs in order from first to last to standard output
  * format - Title, Artist, size in MB (one song per line)

    input parms - none

    output parms - none
 */
 void UtPod::showSongList() {
    SongNode *traversePointer;
    traversePointer = songs;
    if(songs != NULL){
       while (traversePointer != NULL){               //Traverses through song list and displays data for each song
          cout << traversePointer->s << endl;
          traversePointer = traversePointer->next;
       }
    }
 }

 /* FUNCTION - void sortSongList
  *  sorts the songs in ascending order
     o will do nothing if there are less than two songs in the current list

    input parms - none

    output parms - none
 */
 void UtPod::sortSongList() {
   SongNode *smallestPtr = songs;                  //Current smallest pointer through loop
   SongNode *insertPtr= songs;                     //Pointer we put smallest ptr into
   SongNode *traversePtr = songs;                  //Pointer used to traverse through list
   Song temp;

   if (songs != NULL) {
      while (insertPtr->next != NULL) {
         traversePtr = insertPtr;                  //Reinitialize traversePtr and smallestPtr to only sort songs after songs that were already sorted
         smallestPtr = insertPtr;
         while (traversePtr != NULL) {
            if (traversePtr->s < smallestPtr->s) {
               smallestPtr = traversePtr;
            }
            traversePtr = traversePtr->next;
         }
         temp = smallestPtr->s;                   //Puts data of smallestPtr->s into node that needs to be sorted
         smallestPtr->s = insertPtr->s;
         insertPtr->s = temp;

         insertPtr = insertPtr->next;
      }
   }


 }

 /* FUNCTION - void clearMemory
  * clears all the songs from memory

    input parms - none

    output parms - none
 */
 void UtPod::clearMemory() {
    SongNode *tempPointer;
    tempPointer = songs;
    if (songs != NULL) {
       while (songs->next != NULL) {            //Traversing through song list and deleting each song
          songs = tempPointer->next;
          delete tempPointer;
          tempPointer = songs;
       }
       delete songs;
       songs = NULL;
    }

 }

  /* FUNCTION - int getRemainingMemory
  *  returns the amount of memory available for adding new songs

    input parms - none

    output parms - returns remaining memory in UtPod
 */
 int UtPod::getRemainingMemory() {
    SongNode *traversePointer;
    traversePointer = songs;
    int usedMemory = 0;
       while (traversePointer != NULL){                  //Adding up size of each song present in song list
          usedMemory += traversePointer->s.getSize();
          traversePointer = traversePointer->next;
       }

    return (getTotalMemory()-usedMemory);

 }

//deconstructor
 UtPod::~UtPod(){
   clearMemory();                                        //Deletes any songs still remaining in UTPod
}
