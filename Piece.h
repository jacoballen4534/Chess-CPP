//
// Created by Jacob Allen on 14/11/18.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "Position.h"
#include <vector>
#include <string>
#include <iostream>

class Board;

class Player;

enum Team {
	Black,
	White
};

class Piece {

protected:
	void addPosition(int row, int col);

	std::vector<std::string> symbol;


private:
	Position *currentLocation;
	bool moved;
	std::vector<Position *> allPositions; //Valid moves
	Team team;

public:

	Piece(int row, int col, Team team);

	virtual Piece *copyPiece() = 0;

	void removeMoves();

	bool getMoved() const;

	Team getTeam() const;

	void setPosition(int row, int col);

	virtual void generateMoves(Board *board) = 0;

	Position *getPosition() const;

	std::string getSymbol() const;

	bool checkValidMove(Position *moveTo, Board *board);

	bool canEatKing(Board *board);

	virtual bool isKing();

	void setMoved();

	int howManyMoves();

	Position *getMove(int move);

	bool movedIntoCheck(Position *moveTo, Board *board, Player *otherPlayer);

	virtual ~Piece();
};

#endif //CHESS_PIECE_H
