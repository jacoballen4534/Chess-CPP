//
// Created by Jacob Allen on 15/11/18.
//

#include "Knight.h"

Knight::Knight(int row, int col, Team team) : Piece(row, col, team) {
	this->symbol = {"♘", "♞"};
}

Piece *Knight::copyPiece() {
	return new Knight(this->getPosition()->row, this->getPosition()->col, this->getTeam());
}

void Knight::generateMoves(Board *board) {
	int row, col;
	int variations[8][2] = {{1,  2},
	                        {1,  -2},
	                        {-1, 2},
	                        {-1, -2},
	                        {2,  -1},
	                        {2,  1},
	                        {-2, 1},
	                        {-2, -1}};

	for (auto &variation : variations) {
		row = this->getPosition()->row + variation[0];
		col = this->getPosition()->col + variation[1];
		if (row >= 0 && row < 8 && col >= 0 && col < 8) { // Valid Position
			if (!board->getPiece(row, col)) { // No piece
				this->addPosition(row, col);
			} else if (board->getPiece(row, col)->getTeam() != this->getTeam()) { //Enemies piece
				this->addPosition(row, col);
			}
		}
	}
//	TODO: Castle move
}

Knight::~Knight() {

}
