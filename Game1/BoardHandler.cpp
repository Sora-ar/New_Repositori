#include <iostream>
#include <iomanip>
#include "BoardHandler.h"

const int SIZEX = 5;
const int SIZEY = 5;

void BoardHandler::fill_board()
{
    for (int i = 0; i < SIZEX; i++)
    {
        for (int j = 0; j < SIZEY; j++)
        {
            board[i][j] = rand() % (5 - 1 + 1) + (1);
        }
    }
}

void BoardHandler::print_board()
{
    const int number_of_ids = 5;
    int upper_ids[number_of_ids] = { 0, 1, 2, 3, 4 };

    cout << "     ";
    for (int i = 0; i < number_of_ids; i++)
    {
        cout << upper_ids[i] << "   ";
    }
    cout << endl;

    for (int i = 0; i < SIZEX; i++)
    {
        cout << i << ".";
        for (int j = 0; j < SIZEY; j++)
        {
            cout << setw(4) << board[i][j];
        }
        cout << endl;
    }
}

void BoardHandler::create_board()
{
    board = new char* [SIZEX];

    for (int i = 0; i < SIZEX; i++)
    {
        board[i] = new char[SIZEY];
    }
}

char** BoardHandler:: getBoard()
{
    return board;
}