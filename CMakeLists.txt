cmake_minimum_required(VERSION 3.30)
project(chess_engine C)

set(CMAKE_C_STANDARD 11)

add_executable(chess_engine main.c init.c bitboards.c hashkeys.c
        board.c
        data.c)
