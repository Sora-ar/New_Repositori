#include "UserCommunicator.h"

void UserCommunicator::print_final_massage(const std::chrono::high_resolution_clock::time_point& start, int number_of_moves)
{
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "* * * * * * * * * * * * * *" << endl;
    cout << "*                         *" << endl;
    cout << "*       You win!!!        *" << endl;
    cout << "*                         *" << endl;
    cout << "* * * * * * * * * * * * * *" << endl;
    cout << endl;
    cout << "Number of moves: " << number_of_moves << endl;
    cout << "TIME: " << duration.count() / 60 << "min. " << duration.count() % 60 << "sec." << endl;
}

int UserCommunicator::valid_input()
{
    int item = 0;
    while (!(cin >> item))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return item;
}

int UserCommunicator::get_direction(vector<int> directions)
{
    string DIRECTIONS[4] = { "up", "down", "left", "right" };
    cout << "In which direction are we moving? Number:" << endl;
    for (int i = 0; i < directions.size(); i++)
        cout << directions[i] << ". " << DIRECTIONS[directions[i] - 1] << endl;

    return valid_input();
}

void UserCommunicator::fill_object(Coordinates* obj)
{
    cout << "The object we want to move" << endl;
    cout << "Horizontal number: ";
    obj->setRow(valid_input());
    cout << "Vertical number: ";
    obj->setCol(valid_input());
}
