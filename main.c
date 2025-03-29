#include <stdio.h>
#include "defs.h"

#define FEN1 "8/5pk1/6p1/8/8/7P/4Q1P1/2q3K1 w - - 6 38"
#define FEN2 "r1bqr1k1/pp2p1bp/2p2pN1/3p3n/2PP4/3BP3/PP1N1PPP/R2Q1RK1 b - - 0 12"

int main() {

   AllInit();

   S_BOARD board[1];

   ParseFen(START_FEN, board);
   PrintBoard(board);

   ParseFen(FEN1, board);
   PrintBoard(board);

   ParseFen(FEN2, board);
   PrintBoard(board);

   return 0;
}