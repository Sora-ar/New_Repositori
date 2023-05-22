#include "GameHandler.h"

bool GameHandler::check_win(int all_matches)
{
    if (all_matches == MAX_ITERATIONS)
        return true;
    return false;
}

int GameHandler::ask_user(Coordinates* obj, int answer_user, BoardHandler* board)
{
    Validator checkInput = Validator();

    checkInput.validate_user_input_object(obj, board);
    return checkInput.validate_user_input_move(board, obj);
}

void GameHandler::make_replacement(Coordinates* obj, BoardHandler* bh, int new_y, int new_x)
{
    int x = obj->getRow();
    int y = obj->getCol();
    char** board = bh->getBoard();
    replacement_box = board[x][y];
    board[x][y] = board[new_x][new_y];
    board[new_x][new_y] = replacement_box;
    // bh->setBoard(board);
}

void GameHandler::change_cells(int answer_user, Coordinates* obj, BoardHandler* board)
{
    if (answer_user == up)
    {
        make_replacement(obj, board, obj->getCol(), obj->getRow() - 1);
    }
    else if (answer_user == down)
    {
        make_replacement(obj, board, obj->getCol(), obj->getRow() + 1);
    }
    else if (answer_user == left)
    {
        make_replacement(obj, board, obj->getCol() - 1, obj->getRow());
    }
    else if (answer_user == right)
    {
        make_replacement(obj, board, obj->getCol() + 1, obj->getRow());
    }
}
