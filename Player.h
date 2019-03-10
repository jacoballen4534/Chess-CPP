//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H
#include "Piece.h"
#include "King.h"
#include <vector>

class Player {
protected:
	std::vector<Piece *> pieces;
	Team team;

public:
	Position *moveFrom;
	Position *moveTo;

	Player(Team team);
	Player(Player *toCopy, Board *test_board);

	void addPiece(Piece *piece);

	void removePiece(Piece *piece);

	virtual Player* makeCopy(Board* test_board) = 0;

	Team getTeam() const;

	virtual bool getInput(Board *board, Player *enemy) = 0;

	bool canEatKing(Board* testBoard);

	virtual ~Player();
};


#endif //CHESS_PLAYER_H
