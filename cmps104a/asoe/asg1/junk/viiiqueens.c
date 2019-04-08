// $Id: viiiqueens.c,v 1.1 2011-09-02 20:34:53-07 - - $

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

#define BOARD_SIZE 8

int is_safe (int *board, int newcol) {
   int col = 0;
   while (col < newcol) {
      if (board[col] == board[newcol]) return false;
      int diagonal = board[col] - board[newcol];
      if (diagonal == col - newcol) return false;
      if (diagonal == newcol - col) return false;
      col = col + 1;
   }
   return true;
}

void printqueens (int *board, int newcol) {
   int col = 0;
   while (col < newcol) {
      putchar (board[col] + '1');
      col = col + 1;
   }
   putchar ('\n');
}

void queens (int *board, int newcol) {
   if (newcol == BOARD_SIZE) printqueens (board, newcol);
   else {
      int row = 0;
      while (row < BOARD_SIZE) {
         board[newcol] = row;
         if (is_safe (board, newcol)) queens (board, newcol + 1);
         row = row + 1;
      }
   }
}

int main (void) {
   int *board = calloc (BOARD_SIZE, sizeof (int));
   queens (board, 0);
   return 0;
}
