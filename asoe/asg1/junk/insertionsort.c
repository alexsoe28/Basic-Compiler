// $Id: insertionsort.c,v 1.7 2011-09-02 20:40:04-07 - - $
//
// Use insertion sort to print oc_argv in sorted order.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true = 1} bool;

void insertion_sort (int nelem, char **array) {
   int sorted = 1;
   while (sorted < nelem) {
      int slot = sorted;
      char *element = array[slot];
      bool cont = true;
      while (cont) {
         if (slot == 0) {
            cont = false;
         }else if (strcmp (array[slot - 1], element) <= 0) {
            cont = false;
         }else {
            array[slot] = array[slot - 1];
            slot = slot - 1;
         }
      }
      array[slot] = element;
      sorted = sorted + 1;
   }
}

int main (int argc, char **argv) {
   insertion_sort (argc, argv);
   int argi = 0;
   while (argi < argc) {
      printf ("%s\n", argv[argi]);
      argi = argi + 1;
   }
}

