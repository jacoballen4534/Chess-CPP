//
// Created by Jacob Allen on 15/11/18.
//

#include "King.h"

King::King(int row, int col, Team team) : Piece(row, col, team) {
	this->symbol = {"♔", "♚"};
}

Piece *King::copyPiece() {
	return new King(this->getPosition()->row, this->getPosition()->col, this->getTeam());
}

bool King::isKing() {
	return true;
}

void King::generateMoves(Board *board) {
	int row, col;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				row = this->getPosition()->row + i;
				col = this->getPosition()->col + j;
				if (row >= 0 && row < 8 && col >= 0 && col < 8) { // Valid Position
					if (!board->getPiece(row, col)) { // No piece
						this->addPosition(row, col);
					} else if (board->getPiece(row, col)->getTeam() != this->getTeam()) { //Enemies piece
						this->addPosition(row, col);
					}
				}
			}
		}
	}
	//	TODO: Add Castling
}

King::~King() {

}
