//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"
#include "Board.h"

class Knight : public Piece {
public:
	Knight(int row, int col, Team team);

	Piece *copyPiece();

	void generateMoves(Board *board);

	virtual ~Knight();

};


#endif //CHESS_KNIGHT_H
