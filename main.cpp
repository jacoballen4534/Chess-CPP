#include <iostream>
#include "Game.h"

int main(int argc, char *argv[]) {
	Game *game;

	/*//This is all just for testing
											Use valgrind: valgrind --leak-check=full ./chess.
	std::cout << argc << std::endl;
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << (strcmp(argv[2], "2")) << std::endl;
	std::cout << std::endl;*/

	if (argc == 1) {
		game = new Game(false, true); //For Debugger
	} else if (argc == 2) {
		game = new Game((strcmp(argv[1], "2") == 0), (strcmp(argv[1], "1") == 0) || (strcmp(argv[1], "2") == 0));
	} else {
		game = new Game(false, false);
	}

	game->play();
	delete game;
	return 0;
}