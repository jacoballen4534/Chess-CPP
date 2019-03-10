//
// Created by Jacob Allen on 15/11/18.
//

#include "Position.h"
#include <iostream>

Position::Position(int row, int col) {
	this->row = row;
	this->col = col;
}

Position::Position(Position *toCopy) {
	if (toCopy) {
		this->row = toCopy->row;
		this->col = toCopy->col;
	} else {
		this->row = -1;
		this->col = -1;
	}
}

void Position::updatePosition(int row, int col) {
	this->row = row;
	this->col = col;
}

bool Position::operator==(const Position *other) {
	return (this->row == other->row && this->col == other->col);
}

Position::~Position() {

}