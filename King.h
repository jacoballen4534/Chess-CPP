//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Piece.h"
#include "Board.h"

class King : public Piece {
public:
	//TODO: Castle
	King(int row, int col, Team team);
	Piece *copyPiece();
	bool isKing();
	void generateMoves(Board *board);

	virtual ~King();
};


#endif //CHESS_KING_H
