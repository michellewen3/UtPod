//DOCUMENT HERE

#include "UtPod.h"

using namespace std;

UtPod::UtPod() {
   memSize = MAX_MEMORY;
   songs = NULL;
}

UtPod::UtPod(int size) {
   if((size > MAX_MEMORY) || (size <= 0)) {
      memSize = MAX_MEMORY;
   }
   else {
      memSize = size;
   }
   songs = NULL;
}
    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms -

     output parms -
    */

int UtPod::addSong(Song const &s) {
   if(getRemainingMemory() >= s.getSize()) {
      SongNode *newSong;
      newSong = new SongNode;
      newSong->s.setArtist(s.getArtist());
      newSong->s.setTitle(s.getTitle());
      newSong->s.setSize(s.getSize());
      newSong->next = NULL;
      /*cout << newSong->s.getArtist() << endl;
      cout << newSong->s.getTitle() << endl;
      cout << newSong->s.getSize() << endl;
      cout << newSong->next;*/

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


       input parms -

       output parms -
    */

    int UtPod::removeSong(Song const &s) {
       SongNode *leadPtr;
       SongNode *followPtr;
       SongNode *tempPtr;
       leadPtr = songs;
       followPtr = songs;

       if (songs != NULL) {
         while (leadPtr != NULL) {
            if ((songs->s.getArtist() == s.getArtist()) && (songs->s.getSize() == s.getSize()) && (songs->s.getTitle() == s.getTitle())){
               tempPtr = songs;
               songs = songs->next;
               delete tempPtr;
               leadPtr = songs;
               followPtr = songs;
            }
            else if ((leadPtr->s.getArtist() == s.getArtist()) && (leadPtr->s.getSize() == s.getSize()) && (leadPtr->s.getTitle() == s.getTitle())){
                tempPtr = leadPtr;
                leadPtr = leadPtr->next;
                delete tempPtr;
                followPtr->next = leadPtr;
             }
             else{
                followPtr = leadPtr;
                leadPtr = leadPtr->next;
             }
         }
      }
    }


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */

    void UtPod::shuffle() {
    }


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms -

       output parms -
    */

    void UtPod::showSongList() {
       SongNode *traversePointer;
       traversePointer = songs;
       if(songs != NULL){
          while (traversePointer != NULL){
             cout << traversePointer->s << endl;
             traversePointer = traversePointer->next;
          }
       }
    }


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */

    void UtPod::sortSongList() {
    }


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms -

       output parms -
    */
    void UtPod::clearMemory() {
       SongNode *tempPointer;
       tempPointer = songs;
       if (songs != NULL) {
          while (songs->next != NULL) {
             songs = tempPointer->next;
             delete tempPointer;
             tempPointer = songs;
          }
          delete songs;
          songs = NULL;
       }

    }


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */




    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms -

       output parms -
    */

    int UtPod::getRemainingMemory() {
       SongNode *traversePointer;
       traversePointer = songs;
       int usedMemory = 0;

          while (traversePointer != NULL){
             usedMemory += traversePointer->s.getSize();
             traversePointer = traversePointer->next;
          }

       return (getTotalMemory()-usedMemory);

    }


    UtPod::~UtPod(){

   }
