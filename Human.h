//
// Created by Jacob Allen on 28/12/18.
//

#ifndef CHESS_HUMAN_H
#define CHESS_HUMAN_H
#include "Player.h"

class Human : public Player {
public:
	explicit Human(Team team);

	explicit Human(Human *toCopy, Board *test_board);

	bool getInput(Board *board, Player *enemy) override;

	Player *makeCopy(Board *test_board) override;

	virtual ~Human();
};


#endif //CHESS_HUMAN_H
