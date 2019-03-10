//
// Created by Jacob Allen on 15/11/18.
//

#include "Player.h"
//#include <vector>
#include <iostream>
#include <string>

Player::Player(Team team) {
	this->team = team;
	this->moveFrom = nullptr;
	this->moveTo = nullptr;
}

Player::Player(Player *toCopy, Board *test_board) {
	this->team = toCopy->team;
	this->moveFrom = new Position(toCopy->moveFrom);
	this->moveTo = new Position(toCopy->moveTo);
	Piece *temp;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			temp = test_board->getPiece(row, col);
			if (temp && temp->getTeam() == this->team) {
				this->addPiece(temp);
			}
		}
	}
}

Team Player::getTeam() const {
	return this->team;
}

void Player::addPiece(Piece *piece) {
	this->pieces.push_back(piece);
}

void Player::removePiece(Piece *piece) {
	for (int i = 0; i < (int) this->pieces.size(); i++) {
		if (this->pieces[i] == piece) {
			this->pieces.erase(this->pieces.begin() + i);
			return;
		}
	}
}


bool Player::canEatKing(Board *testBoard) {
	for (int i = 0; i < (int) this->pieces.size(); i++) {
		if (this->pieces[i]->canEatKing(testBoard)) {
			return true;
		}
	}
	return false;
}


Player::~Player() {
	;
}



