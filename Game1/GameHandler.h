#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <iostream>
#include "BoardHandler.h"
#include "Coordinates.h"
#include "Constants.h"
#include "Validator.h"

using namespace std;

class GameHandler
{
private:
	int up = 1;
	int down = 2;
	int left = 3;
	int right = 4;
	char replacement_box;

public:
	bool check_win(int);
	int ask_user(Coordinates*, int, BoardHandler*);
	void make_replacement(Coordinates*, BoardHandler*, int, int);
	void change_cells(int, Coordinates*, BoardHandler*);

};

#endif // !GAMEHANDLER_H