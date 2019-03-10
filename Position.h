//
// Created by Jacob Allen on 15/11/18.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


class Position {
public:
	int row;
	int col;

	Position(int row, int col);

	Position(Position *toCopy);

	void updatePosition(int row, int col);

	bool operator==(const Position *other);

	~Position();
};


#endif //CHESS_POSITION_H
