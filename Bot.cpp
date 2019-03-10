//
// Created by Jacob Allen on 5/12/18.
//

#include "Bot.h"

Bot::Bot(Team team) : Player(team) {

}

Bot::Bot(Bot *toCopy, Board *test_board) : Player(toCopy, test_board) {

}

Player *Bot::makeCopy(Board *test_board) {
	return new Bot(this, test_board);
}

bool Bot::getInput(Board *board, Player *enemy) {

	delete this->moveTo;
	delete this->moveFrom;

	for (int i = 0; i < (int) this->pieces.size(); i++) {
		this->pieces[i]->removeMoves();
		this->pieces[i]->generateMoves(board);
		for (int j = 0; j < this->pieces[i]->howManyMoves(); j++) {
			if (!this->pieces[i]->movedIntoCheck(this->pieces[i]->getMove(j), board, enemy)) {
				//TODO:Pick random piece and move
				this->moveFrom = new Position(this->pieces[i]->getPosition());
				this->moveTo = new Position(this->pieces[i]->getMove(j));
				return true;
			}
		}

	}
	return false;
}

Bot::~Bot() {
//	For some reason if the bot is in checkmate, move to/from are allready deleted "Positions"
//	delete this->moveTo;
//	delete this->moveFrom;
	this->pieces.clear();
}
