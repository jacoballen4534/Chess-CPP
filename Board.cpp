//
// Created by Jacob Allen on 15/11/18.
//

#include "Board.h"
#include <iostream>
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

Board::Board(Player *player1, Player *player2) {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (row == 1 || row == 6) {
				this->board[row][col] = new Pawn(row, col, row == 1 ? Black : White);
				(row == 1 ? player2 : player1)->addPiece(this->board[row][col]);
			} else if (row == 0 || row == 7) {
				if (col == 0 || col == 7) {
					this->board[row][col] = new Rook(row, col, row == 0 ? Black : White);
				} else if (col == 1 || col == 6) {
					this->board[row][col] = new Knight(row, col, row == 0 ? Black : White);
				} else if (col == 2 || col == 5) {
					this->board[row][col] = new Bishop(row, col, row == 0 ? Black : White);
				} else if (col == 3) {
					this->board[row][col] = new Queen(row, col, row == 0 ? Black : White);
				} else {
					this->board[row][col] = new King(row, col, row == 0 ? Black : White);
				}
				(row == 0 ? player2 : player1)->addPiece(this->board[row][col]);
			} else {
				this->board[row][col] = nullptr;
			}
		}
	}
}

Board::Board(Board *toCopy) {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (toCopy->getPiece(row, col)) {
				this->board[row][col] = toCopy->getPiece(row, col)->copyPiece();
			} else {
				this->board[row][col] = nullptr;
			}
		}
	}
}

Piece *Board::getPiece(int row, int col) {
	return this->board[row][col];
}

Piece *Board::getPiece(Position *position) {
	return this->board[position->row][position->col];
}

void Board::drawBoard() {
	for (int row = 0; row < 8; row++) {
		std::cout << 8 - row;
		for (int col = 0; col < 8; col++) {
			if (this->board[row][col]) { // !=nullptr
				std::cout << " " << this->board[row][col]->getSymbol();
			} else {
				std::cout << " ·";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "  a b c d e f g h " << std::endl;
}

void Board::performMove(Player *player, Player *enemy) {
	if (this->board[player->moveTo->row][player->moveTo->col]) { //Eating enemy piece
		enemy->removePiece(this->getPiece(player->moveTo->row, player->moveTo->col));
		delete this->getPiece(player->moveTo->row, player->moveTo->col);
	}
	this->board[player->moveTo->row][player->moveTo->col] = this->board[player->moveFrom->row][player->moveFrom->col];
	this->board[player->moveFrom->row][player->moveFrom->col] = nullptr;
	this->getPiece(player->moveTo->row, player->moveTo->col)->setPosition(player->moveTo->row, player->moveTo->col);
	this->getPiece(player->moveTo->row, player->moveTo->col)->setMoved();
}

void Board::performMove(Piece *piece, Position *moveTo, Player *enemy) {
	if (this->board[moveTo->row][moveTo->col]) {
		enemy->removePiece(this->board[moveTo->row][moveTo->col]);
		delete this->board[moveTo->row][moveTo->col];
	}
	this->board[moveTo->row][moveTo->col] = this->board[piece->getPosition()->row][piece->getPosition()->col];
	this->board[piece->getPosition()->row][piece->getPosition()->col] = nullptr;
	this->getPiece(moveTo->row, moveTo->col)->setPosition(moveTo->row, moveTo->col);
	this->getPiece(moveTo->row, moveTo->col)->setMoved();
}

Board::~Board() {
	Piece *temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			temp = this->board[i][j];
			delete temp;
		}
	}
}
