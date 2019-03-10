//
// Created by Jacob Allen on 15/11/18.
//

#include "Bishop.h"

Bishop::Bishop(int row, int col, Team team) : Piece(row, col, team) {
	this->symbol = {"♗", "♝"};
}

Piece *Bishop::copyPiece() {
	return new Bishop(this->getPosition()->row, this->getPosition()->col, this->getTeam());
}

void Bishop::generateMoves(Board *board) { // Moves are valid until another piece is hit.
	int row, col;
	for (int horizontal = -1; horizontal <= 1; horizontal += 2) {
		for (int vertical = -1; vertical <= 1; vertical += 2) {
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

Bishop::~Bishop() {

}
