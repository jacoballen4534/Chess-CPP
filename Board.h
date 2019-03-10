//
// Created by Jacob Allen on 15/11/18.
//

#include "Position.h"

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Piece.h"
#include "Player.h"


class Board {
private:
	Piece *board[8][8];
public:
	Board(Player *player1, Player *player2);

	Board(Board *toCopy);

	Piece *getPiece(int row, int col);

	Piece *getPiece(Position* position);

	bool placePiece(Piece piece, Position* position);

	void performMove(Piece *piece, Position *moveTo, Player *enemy);

	bool validMove(Piece piece, Position position);

	void performMove(Player *player, Player *enemy);

	void drawBoard();

	virtual ~Board();
};


#endif //CHESS_BOARD_H
