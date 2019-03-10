cmake_minimum_required(VERSION 3.12)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess main.cpp Piece.cpp Piece.h Position.cpp Position.h King.cpp King.h Queen.cpp Queen.h Rook.cpp Rook.h Bishop.cpp Bishop.h Knight.cpp Knight.h Pawn.cpp Pawn.h Game.cpp Game.h Player.cpp Player.h Board.cpp Board.h Bot.cpp Bot.h Human.cpp Human.h)