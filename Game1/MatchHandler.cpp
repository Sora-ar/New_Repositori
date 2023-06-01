#include "MatchHandler.h"

char** MatchHandler::remove_items(BoardHandler* bh)
{
    count = 0;
    char** board = bh->getBoard();

    for (int j = 0; j < SIZEY; j++)
    {
        for (int i = SIZEX - 1; i > 0; i--)
            if (board[i][j] == 0)
            {
                if (board[i - 1][j] != 0)
                    swap(board[i - 1][j], board[i + count][j]);
                else
                    count++;
            }

        for (int i = 0; i < SIZEX; i++)
        {
            if (board[i][j] == 0)
                board[i][j] = rand() % (5 - 1 + 1) + (1);
            else
                break;
        }
    }

    return board;
}

void MatchHandler::check_sequences_horizontal(BoardHandler* bh, Coordinates* obj, int direction, int& all_matches)
{
    char** board = bh->getBoard();
    int x = obj->getRow();
    int y = obj->getCol();

    additional_row = direction == 1 ? x - 1 : x;

    for (int i = additional_row; i <= additional_row + 1; i++)
    {
        counter = 0;
        k = y - 2 > 0 ? y - 2 : 0;
        for (int j = k; j <= y + 2 && j < SIZEY; j++)
        {
            cell = board[i][j];
            if (cell == board[i][y])
            {
                counter++;
                if (counter == 3)
                {
                    all_matches++;
                    for (int l = k; l <= k + 2; l++)
                        board[i][l] = 0;
                    break;
                }
            }
            else
            {
                counter = 0;
                k = j + 1;
            }
        }

    }

    check_sequences_horizontal_to_vertical(bh, obj, all_matches);
}

void MatchHandler::check_sequences_horizontal_to_vertical(BoardHandler* bh, Coordinates* obj, int& all_matches)
{
    char** board = bh->getBoard();
    int x = obj->getRow();
    int y = obj->getCol();

    counter = 0;
    k = additional_row - 2 > 0 ? additional_row - 2 : 0;
    char current_symbol = board[k][y];

    for (int i = k + 1; i <= additional_row + 3 && i < SIZEX; i++)
    {
        cell = board[i][y];
        if (cell == current_symbol)
        {
            counter++;
            if (counter == 2)
            {
                all_matches++;
                for (int l = k; l <= k + 2; l++)
                    board[l][y] = 0;
            }
        }
        else
        {
            current_symbol = cell;
            counter = 0;
            k = i;
        }
    }
}

void MatchHandler::check_sequences_vertical(BoardHandler* bh, Coordinates* obj, int direction, int& all_matches)
{
    char** board = bh->getBoard();
    int x = obj->r;
    int y = obj->c;

    additional_row = direction == 3 ? y - 1 : y;
    for (int j = additional_row; j <= additional_row + 1; j++)
    {
        counter = 0;
        k = x - 2 > 0 ? x - 2 : 0;
        for (int i = k; i <= x + 2 && i < SIZEY; i++)
        {
            cell = board[i][j];
            if (cell == board[x][j])
            {
                counter++;
                if (counter == 3)
                {
                    all_matches++;
                    for (int l = k; l <= k + 2; l++)
                        board[l][j] = 0;
                    break;
                }
            }
            else
            {
                counter = 0;
                k = i + 1;
            }
        }

    }

    check_sequences_horizontal_to_vertical(bh, obj, all_matches);
}

void MatchHandler::check_sequences_vertical_to_horizontal(BoardHandler* bh, Coordinates* obj, int& all_matches)
{
    char** board = bh->getBoard();
    int x = obj->getRow();
    int y = obj->getCol();

    counter = 0;
    k = additional_row - 2 > 0 ? additional_row - 2 : 0;
    char current_symbol = board[x][k];

    for (int j = k + 1; j <= additional_row + 3 && j < SIZEY; j++)
    {
        cell = board[x][j];
        if (cell == current_symbol)
        {
            counter++;
            if (counter == 2)
            {
                all_matches++;
                for (int l = k; l <= k + 2; l++)
                    board[x][l] = 0;
            }
        }
        else
        {
            current_symbol = cell;
            counter = 0;
            k = j;
        }
    }
}



int MatchHandler::check_sequences(BoardHandler* bh, Coordinates* obj, int direction, int all_matches)
{
    if (direction == 1 || direction == 2)
        check_sequences_horizontal(bh, obj, direction, all_matches);
    else
        check_sequences_vertical(bh, obj, direction, all_matches);

    return all_matches;
}

void MatchHandler::break_match_horizontal(BoardHandler*& bh, int x, int y, int z)
{
    char** board = bh->getBoard();

    if (board[x][y + 1] != z && !((x < SIZEX - 1 && board[x + 1][y + 1] == z) || (x > 0 && board[x - 1][y + 1] == z)))
        board[x][y + 1] = z;
}

void MatchHandler::break_match_vertical(BoardHandler*& bh, int x, int y, int z)
{
    char** board = bh->getBoard();

    if (board[x + 1][y] != z && !((y < SIZEY - 1 && board[x + 1][y + 1] == z) || (y > 0 && board[x + 1][y - 1] == z)))
        board[x + 1][y] = z;
}

void MatchHandler::break_match(BoardHandler* bh)
{
    char** board = bh->getBoard();

    for (int i = 0; i < SIZEX; i++)
    {
        for (int j = 0; j < SIZEY; j++)
        {
            if (j < SIZEY - 2 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
                for (int k = 2; k <= 6; k++)
                {
                    //int i1 = i > 0 ? i - 1 : 0;
                    //int i2 = i < SIZEX - 1 ? i + 1 : SIZEX - 1;
                    //if (board[i][j + 1] != k && k != board[i1][j + 1] && k != board[i2][j + 1])
                    break_match_horizontal(bh, i, j, k);
                }
            if (i < SIZEX - 2 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
            {
                for (int p = 2; p <= 6; p++)
                {
                    //int j1 = j > 0 ? j - 1 : 0;
                    //int j2 = j < SIZEY - 1 ? j + 1 : SIZEY - 1;
                    break_match_vertical(bh, i, j, p);
                }
            }
        }
    }
}
