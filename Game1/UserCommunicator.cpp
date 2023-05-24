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

int UserCommunicator::get_direction(vector<int> directions)
{
    int  answer_user;
    string DIRECTIONS[4] = { "up", "down", "left", "right" };
    // make a loop
    cout << "In which direction are we moving? Number:" << endl;
    for (int i = 0; i < directions.size(); i++)
    {
        cout << directions[i] << ". " << DIRECTIONS[directions[i] - 1] << endl;
    }
    while (!(cin >> answer_user))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return answer_user;
}

void UserCommunicator::fill_object(Coordinates* obj)
{
    int tmp;
    cout << "The object we want to move" << endl;
    cout << "Horizontal number: ";
    while (!(cin >> tmp))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    obj->setRow(tmp);
    cout << "Vertical number: ";
    while (!(cin >> tmp))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    obj->setCol(tmp);
}

