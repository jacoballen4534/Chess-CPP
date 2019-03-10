//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"
#include "Board.h"

class Queen : public Piece {
public:
	Queen(int row, int col, Team team);

	Piece *copyPiece();

	void generateMoves(Board *board);

	virtual ~Queen();

};


#endif //CHESS_QUEEN_H
