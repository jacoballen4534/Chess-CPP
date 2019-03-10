//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece {
public:
	Bishop(int row, int col, Team team);

	Piece *copyPiece();

	void generateMoves(Board *board);

	virtual ~Bishop();

};

#endif //CHESS_BISHOP_H