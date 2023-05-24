#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H
#include <iostream>
#include <iomanip>
#include "Constants.h"

using namespace std;

class BoardHandler
{
private:
	char** board;

public:
	void fill_board();
	void print_board();
	void create_board();
	char** getBoard();
};

#endif // !BOARDHANDLER_H