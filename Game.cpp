//
// Created by Jacob Allen on 15/11/18.
//

#include "Game.h"
#include <iostream>

Game::Game(bool p1Bot, bool p2Bot) {
	if (p1Bot) {
		this->player1 = new Bot(White);
	} else {
		this->player1 = new Human(White);
	}
	if (p2Bot) {
		this->player2 = new Bot(Black);
	} else {
		this->player2 = new Human(Black);
	}
	this->whosTurn = this->player1;
	this->board = new Board(this->player1, this->player2);
	system("clear");
	this->board->drawBoard();
	this->gameOver = false;

}

void Game::play() {
	int moves = 0; //just to end game to use valgrind.
	while (!this->gameOver && moves < 200) { //!gameOver) {
		this->gameOver = !whosTurn->getInput(this->board, whosTurn == this->player1 ? this->player2 : this->player1);
		if (!this->gameOver) {
			board->performMove(whosTurn, whosTurn == this->player1 ? this->player2 : this->player1);
		}
		this->nextPlayer();
		//if (moves % 10000 == 0) {
		system("clear");
		board->drawBoard();
		std::cout << moves++ << std::endl; // for debug
		//}
		//moves++;
	}
	std::cout << "Bot cant find any more moves\n Game Over" << std::endl;
}

void Game::nextPlayer() {
	if (this->whosTurn == this->player1) {
		this->whosTurn = this->player2;
	} else {
		this->whosTurn = this->player1;
	}
}

Game::~Game() {
	//TODO: Bot->moveTo is allready deleted if the game actualy ends
	delete this->board;
	delete this->player2;
	delete this->player1;
}
