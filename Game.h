//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "Player.h"
#include "Board.h"
#include "Bot.h"
#include "Human.h"

class Game {
public:
	Player *player1; // Player 1 = Bottom = White
	Player *player2; // Player 2 = Top = Black
	Board *board;
	Player *whosTurn;
	bool validMove;
	bool gameOver;

	Game(bool p1Bot, bool p2Bot);

	void play();

	void nextPlayer();

	//bool updateValidMove();


	virtual ~Game();
};


#endif //CHESS_GAME_H
