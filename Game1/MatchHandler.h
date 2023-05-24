#ifndef MATCHHANDLER_H
#define MATCHHANDLER_H
#include <iostream>
#include <iomanip>
#include "BoardHandler.h"
#include "Coordinates.h"
#include "Constants.h"

class MatchHandler
{
private:
	int count;
	int cell;
	int counter;
	int k;
	int additional_row;

public:
	char** remove_items(BoardHandler*);
	int check_sequences(BoardHandler*, Coordinates*, int, int);
	void break_match(BoardHandler*);

	MatchHandler()
	{
		count = 0;
	}

};

#endif // !MATCHHANDLER_H