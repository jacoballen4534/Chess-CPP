//
// Created by Jacob Allen on 15/11/18.
//

#include "Pawn.h"

Pawn::Pawn(int row, int col, Team team) : Piece(row, col, team) {
	this->symbol = {"♙", "♟"};
}

Piece *Pawn::copyPiece() {
	return new Pawn(this->getPosition()->row, this->getPosition()->col, this->getTeam());
}

void Pawn::generateMoves(Board *board) {
	int row = 1;
	int col = this->getPosition()->col;
	int direction = this->getTeam() == White ? -1 : +1; // Black moves "Down" (+'ve) while white moves "Up" (-'ve)

	for (int i = (this->getMoved() ? 1 : 2); i > 0; i--) {
		row = this->getPosition()->row + (i * direction);
		if (row >= 0 && row < 8 && col >= 0 && col < 8) { // Valid Position
			if (!board->getPiece(row, col)) {
				this->addPosition(row, col);
			}
		}
	}
	for (int horizontal = -1; horizontal <= 1; horizontal += 2) {
		if (row >= 0 && row < 8 && col + horizontal >= 0 && col + horizontal < 8) { // Valid Position
			if (board->getPiece(row, col + horizontal) &&
					board->getPiece(row, col + horizontal)->getTeam() != this->getTeam()) {
				this->addPosition(row, col + horizontal);
			}
		}
	}
}

Pawn::~Pawn() {

}
