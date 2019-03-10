//
// Created by Jacob Allen on 15/11/18.
//

#include "Rook.h"

Rook::Rook(int row, int col, Team team) : Piece(row, col, team) {
	this->symbol = {"♖", "♜"};
}

Piece *Rook::copyPiece() {
	return new Rook(this->getPosition()->row, this->getPosition()->col, this->getTeam());
}

void Rook::generateMoves(Board *board) {
	int row, col;
	for (int horizontal = -1; horizontal <= 1; horizontal++) {
		for (int vertical = (horizontal == 0 ? -1 : 0); vertical <= (horizontal == 0 ? 1 : 0); vertical += 2) {
			for (int i = 1; i < 8; i++) {
				row = this->getPosition()->row + (i * horizontal);
				col = this->getPosition()->col + (i * vertical);
				if (row >= 0 && row < 8 && col >= 0 && col < 8) { // Valid Position

					if (!board->getPiece(row, col)) { // No piece
						this->addPosition(row, col);
					} else if (board->getPiece(row, col)->getTeam() != this->getTeam()) { //Enemies piece
						this->addPosition(row, col);
						break;
					} else { //Own piece
						break;
					}

				}
			}
		}
	}
}

Rook::~Rook() {

}
