#include "defs.h"

#define PAWNMOVES "r1bqkbnr/pp2pppp/2np4/1B6/3NP3/8/PPP2PPP/RNBQK2R b KQkq - 2 5"

int main() {

   AllInit();

   S_BOARD board[1];

   ParseFen(PAWNMOVES,board);
   PrintBoard(board);

   S_MOVELIST list[1];

   GenerateAllMoves(board,list);

   return 0;
}