//
// Created by Jacob Allen on 28/12/18.
//

#include "Human.h"

Human::Human(Team team) : Player(team) {

}

Human::Human(Human *toCopy, Board *test_board) : Player(toCopy, test_board) {

}

Player *Human::makeCopy(Board *test_board) {
	return new Human(this, test_board);
}

bool Human::getInput(Board *board, Player *enemy) {

	std::string from;
	std::string to;

	while (true) { //Get user input
		std::cout << (this->getTeam() == Black ? "Black" : "White") << " Enter move: ";
		std::cin >> from;
		std::cin >> to;
		//Check if it is on the board
		if (tolower(from[0]) - 97 < 0 || tolower(from[0]) - 97 > 8 || tolower(to[0]) - 97 < 0 ||
				tolower(to[0]) - 97 > 8 || 56 - from[1] < 0 || 56 - from[1] > 8 || 56 - to[1] < 0 ||
				56 - to[1] > 8) {
			//This is not on the board
			std::cout << "Please enter a valid position" << std::endl;
			continue;
		}
		// This is on the board, now check if this is your piece
		Piece *piece = board->getPiece(56 - from[1], tolower(from[0]) - 97);
		if (!piece || piece->getTeam() != this->team) {
			std::cout << "This is not your piece" << std::endl;
			continue;
		}

		// This is your piece, now check if the destination is a valid move.
		Position *tempTo = new Position(56 - to[1], tolower(to[0]) - 97);
		if (!piece->checkValidMove(tempTo, board)) {
			std::cout << "this is not a valid move." << std::endl;
			delete tempTo;
			continue;
		}

		// This is your piece and the destination is a valid position. Final check - Check if you are moving into check.
		if (piece->movedIntoCheck(tempTo, board, enemy)) {
			delete tempTo;
			std::cout << "You are either in check or are trying to move into check. This is not allowed" << std::endl;
			continue;
		}

		delete this->moveTo;
		delete this->moveFrom;
		delete tempTo;

		this->moveTo = new Position(56 - to[1], tolower(to[0]) - 97);
		this->moveFrom = new Position(56 - from[1], tolower(from[0]) - 97);
		return true;
	}
}


Human::~Human() {
	delete this->moveTo;
	delete this->moveFrom;
	this->pieces.clear();
}
