//
// Created by Jacob Allen on 14/11/18.
//

#include "Piece.h"
#include "Board.h"
#include "Player.h"


Piece::Piece(int row, int col, Team team) {
	this->currentLocation = new Position(row, col);
	this->moved = false;
	this->team = team;
}

//Piece *Piece::copyPiece() {
//this->currentLocation = new Position(toCopy->currentLocation->row, toCopy->currentLocation->col);
//this->moved = toCopy->moved;
//this->team = toCopy->team;
//}

bool Piece::getMoved() const {
	return this->moved;
}

Position *Piece::getPosition() const {
	return this->currentLocation;
}

void Piece::addPosition(int row, int col) {
	allPositions.push_back(new Position(row, col));
}

int Piece::howManyMoves() {
	return (int) this->allPositions.size();
}

Position *Piece::getMove(int move) {
	return this->allPositions[move];
}

void Piece::setPosition(int row, int col) {
	this->currentLocation->updatePosition(row, col);
}

Team Piece::getTeam() const {
	return this->team;
}

std::string Piece::getSymbol() const {
	return this->team == White ? symbol[0] : symbol[1];
}

bool Piece::checkValidMove(Position *moveTo, Board *board) {
	//This function is only called by Humans, it will check if the chosen move is actually one of the available moves
	this->removeMoves();
	this->generateMoves(board);
	for (int i = 0; i < (int) this->allPositions.size(); i++) {
		if (this->allPositions[i]->operator==(moveTo)) {
			return true;
		}
	}
	return false;
}

bool Piece::movedIntoCheck(Position *moveTo, Board *board, Player *otherPlayer) {
	//remove moves that put you into check.

	// Copy board (test_board)
	// Copy player (test_otherPlayer)
	// test_board->peformMove
	// call player checkCheck to go through all their pieces to check if they can each king
	Board *testBoard = new Board(board); // This makes a copy to test on.
	Player *test_otherPlayer = otherPlayer->makeCopy(testBoard); // Make a copy of other so piece list can be altered
	//test_otherPlayer->moveTo = moveTo; dont think this is needed

	testBoard->performMove(this, moveTo, test_otherPlayer); // Play the desired move to test
	//Check if you are moving into check.
	if (test_otherPlayer->canEatKing(testBoard)) { //Yes, you moved into check
		delete test_otherPlayer;
		delete testBoard;
		return true;
	} else { // No, you are not trying to move into check so can continue.
		delete test_otherPlayer;
		delete testBoard;
		return false;
	}


}

void Piece::setMoved() {
	this->moved = true;
}

bool Piece::canEatKing(Board *board) {
	this->removeMoves();
	this->generateMoves(board);
	Piece *temp;
	for (int i = 0; i < (int) this->allPositions.size(); i++) {
		temp = board->getPiece(this->allPositions[i]);
		if (temp && temp->getTeam() != this->team && temp->isKing()) {
			return true;
		}
	}
	return false;
}

bool Piece::isKing() {
	return false;
}

void Piece::removeMoves() {
	for (int i = (int) this->allPositions.size() - 1; i >= 0; i--) {
		if (this->allPositions[i] != nullptr) {
			delete this->allPositions[i];
		}
	}
	this->allPositions.clear();
}

Piece::~Piece() {
	this->removeMoves();
	delete this->currentLocation;
}