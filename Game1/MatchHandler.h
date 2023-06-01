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
	void check_sequences_horizontal(BoardHandler* bh, Coordinates* obj, int direction, int& all_matches);
	void check_sequences_horizontal_to_vertical(BoardHandler* bh, Coordinates* obj, int& all_matches);
	void check_sequences_vertical(BoardHandler* bh, Coordinates* obj, int direction, int& all_matches);
	void check_sequences_vertical_to_horizontal(BoardHandler* bh, Coordinates* obj, int& all_matches);
	int check_sequences(BoardHandler*, Coordinates*, int, int);
	void break_match_horizontal(BoardHandler*& bh, int x, int y, int z);
	void break_match_vertical(BoardHandler*& bh, int x, int y, int z);
	void break_match(BoardHandler*);

};

#endif // !MATCHHANDLER_H