#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

using namespace std;

class BoardHandler
{

public:
	void fill_board();
	void print_board();
	void create_board();
	char** getBoard();
private:
	char** board;

};

#endif // !BOARDHANDLER_H