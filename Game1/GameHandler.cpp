#include "GameHandler.h"

bool GameHandler::check_win(int all_matches)
{
    return all_matches == MAX_ITERATIONS;
}

int GameHandler::ask_user(Coordinates* obj, int answer_user, BoardHandler* board)
{
    Validator checkInput = Validator();

    checkInput.validate_user_input_object(obj, board);
    return checkInput.validate_user_input_move(board, obj);
}

void GameHandler::make_replacement(Coordinates* obj, BoardHandler* bh, int new_y, int new_x)
{
    char** board = bh->getBoard();
    swap(board[obj->getRow()][obj->getCol()], board[new_x][new_y]);
}

void GameHandler::change_cells(int answer_user, Coordinates* obj, BoardHandler* board)
{
    switch(answer_user)
    {
        case UP:
            make_replacement(obj, board, obj->getCol(), obj->getRow() - 1);
            break;
        case DOWN:
            make_replacement(obj, board, obj->getCol(), obj->getRow() + 1);
            break;
        case LEFT:
            make_replacement(obj, board, obj->getCol() - 1, obj->getRow());
            break;
        case RIGHT:
            make_replacement(obj, board, obj->getCol() + 1, obj->getRow());
            break;
    }
}
