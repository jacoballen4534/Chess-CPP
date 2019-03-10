//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {
public:
	//TODO: Elpassant, Promotion - set moved to true on new piece - look at rules on picking new piece.
	Pawn(int row, int col, Team team);

	Piece *copyPiece();

	void generateMoves(Board *board);

	virtual ~Pawn();

};

#endif //CHESS_PAWN_H
