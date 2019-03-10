//
// Created by Jacob Allen on 5/12/18.
//

#ifndef CHESS_BOT_H
#define CHESS_BOT_H
#include "Player.h"

class Bot : public Player {
public:
	explicit Bot(Team team);

	explicit Bot(Bot *toCopy, Board *test_board);

	bool getInput(Board *board, Player *enemy) override;

	Player *makeCopy(Board *test_board) override;

	virtual ~Bot();
};


#endif //CHESS_BOT_H
