//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Piece.h"
#include "Board.h"


class Rook : public Piece {
public:
	Rook(int row, int col, Team team);

	Piece *copyPiece();

	void generateMoves(Board *board);

	virtual ~Rook();

};


#endif //CHESS_ROOK_H