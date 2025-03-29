//
// Created by mach on 28/03/25.
//

#include "defs.h"

int Sq120To64[BRD_SQ_NUM];
int Sq64To120[64];

void InitSq120To64() {

  int index = 0;
  int file = FILE_A;
  int rank = RANK_1;
  int sq = A1;
  int sq64 = 0;

  for (index = 0; index < BRD_SQ_NUM; index++) {
    Sq120ToSq64[index] = 65;
  }

}

void AllInit() {

}