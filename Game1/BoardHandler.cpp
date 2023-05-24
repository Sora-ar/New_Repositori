#include "BoardHandler.h"

void BoardHandler::fill_board()
{
    for (int i = 0; i < SIZEX; i++)
        for (int j = 0; j < SIZEY; j++)
            board[i][j] = rand() % 5 + 1;  
}

void BoardHandler::print_board()
{
    cout << "     ";
    for (int i = 0; i < number_of_ids; i++)
        cout << i << "   ";
    cout << endl;

    for (int i = 0; i < SIZEX; i++)
    {
        cout << i << ".";
        for (int j = 0; j < SIZEY; j++)
            cout << setw(4) << board[i][j];
        cout << endl;
    }
}

void BoardHandler::create_board()
{
    board = new char* [SIZEX];

    for (int i = 0; i < SIZEX; i++)
        board[i] = new char[SIZEY];
}

char** BoardHandler:: getBoard()
{
    return board;
}