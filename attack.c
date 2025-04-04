//
// Created by mach on 29/03/25.
//
#include <stdio.h>

#include "defs.h"

const int KnDir[8] = { -8, - 19, -21, -12, 8, 19, 21, 12 };
const int RkDir[4] = { -1, -10, 1, 10};
const int BiDir[4] = { -9, -11, 11, 9 };
const int KiDir[8] = { -1, -10, 11, 10, -9, -11, 11, 9};

int SqAttacked(const int sq, const int side, const S_BOARD *pos) {
    int pce, index, t_sq, dir;

    ASSERT(SqOnBoard(sq));
    ASSERT(SideValid(side));
    ASSERT(CheckBoard(pos));

    // Check for pawn attacks
    if (side == WHITE) {
        if (pos->pieces[sq-11] == wP || pos->pieces[sq-9] == wP) {
            return TRUE;
        }
    } else {
        if (pos->pieces[sq+11] == bP || pos->pieces[sq+9] == bP) {
            return TRUE;
        }
    }

    // Check for knight attacks
    for (index = 0; index < 8; ++index) {
        pce = pos->pieces[sq + KnDir[index]];
        if (pce != OFFBOARD && pce != EMPTY) {
            if (IsKn(pce) && PieceCol[pce] == side) {
                return TRUE;
            }
        }
    }

    // Check for Rook and Queen attacks
    for (index = 0; index < 4; ++index) {
        dir = RkDir[index];
        t_sq = sq + dir;
        pce = pos->pieces[t_sq];
        while (pce != OFFBOARD) {
            if (pce != EMPTY) {
                if (IsRQ(pce) && PieceCol[pce] == side) {
                    return TRUE;
                }
                break;
            }
            t_sq += dir;
            pce = pos->pieces[t_sq];
        }
    }

    // Check for Bishop and Queen attacks
    for (index = 0; index < 4; ++index) {
        dir = BiDir[index];
        t_sq = sq + dir;
        pce = pos->pieces[t_sq];
        while (pce != OFFBOARD) {
            if (pce != EMPTY) {
                if (IsBQ(pce) && PieceCol[pce] == side) {
                    return TRUE;
                }
                break;
            }
            t_sq += dir;
            pce = pos->pieces[t_sq];
        }
    }

    // Check for King attacks
    for (index = 0; index < 8; ++index) {
        pce = pos->pieces[sq + KiDir[index]];
        if (pce != OFFBOARD && pce != EMPTY) {
            if (IsKi(pce) && PieceCol[pce] == side) {
                return TRUE;
            }
        }
    }
    return FALSE;
}