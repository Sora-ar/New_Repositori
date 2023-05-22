#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include "BoardHandler.h"
#include "Coordinates.h"
#include "Constants.h"
#include "GameHandler.h"
#include "UserCommunicator.h"
#include "Validator.h"
#include "MatchHandler.h"

using namespace std;
using namespace std::chrono;

int main()
{
    BoardHandler* bordH = new BoardHandler();
    GameHandler gameH = GameHandler();
    MatchHandler matchH = MatchHandler();
    UserCommunicator userPrint = UserCommunicator();
    Coordinates* obj = new Coordinates();
    bordH->create_board();
    int answer_user = 0;
    int combo_matches = 0;
    int all_matches = 0;
    int number_of_moves = 0;

    bordH->fill_board();
    bordH->getBoard();
    matchH.break_match(bordH);

    bool game_over = false;
    auto start = high_resolution_clock::now();
    while (!game_over)
    {
        bordH->print_board();
        answer_user = gameH.ask_user(obj, answer_user, bordH);
        number_of_moves++;
        gameH.change_cells(answer_user, obj, bordH);
        system("cls");
        all_matches = matchH.check_sequences(bordH, obj, answer_user, all_matches); 
        matchH.remove_items(bordH);
        matchH.break_match(bordH);
        game_over = gameH.check_win(all_matches);
    }

    userPrint.print_final_massage(start, number_of_moves);
            
    return 0;
}
