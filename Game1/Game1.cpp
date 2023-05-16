#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZEX = 5;
const int SIZEY = 5;
const int MAX_ITERATIONS = 15;

struct for_ask_user { int au = 0; };
struct ask_about_move_object { int r = 0; int c = 0; };


///////////////////////////////////////////////// BoardHandler
char ** fill_board(char** board)
{
    for (int i = 0; i < SIZEX; i++)
    {
        for (int j = 0; j < SIZEY; j++)
        {
            board[i][j] = rand() % (5 - 1 + 1) + (1);
        } 
    }

    return board;
}
///////////////////////////////////////////////// BoardHandler
void print_board(char** board)
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

void print_final_massage(const std::chrono::high_resolution_clock::time_point& start, int number_of_moves)
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


/////////////////GameManager
bool check_win(int all_matches)
{
    if (all_matches == MAX_ITERATIONS)
        return true;
    return false;
}

///////////////////////////////////////////////// MatchHandler
char** remove_items(char**& board)
{
    int count = 0;
    for (int j = 0; j < SIZEY; j++)
    {
        for (int i = SIZEX - 1; i > 0; i--) 
        {
            if (board[i][j] == 0)
            {   
                if (board[i - 1][j] != 0)
                {
                    swap(board[i - 1][j], board[i + count][j]);
                }
                else
                {
                    count++;
                }
            }
        }
        for (int i = 0; i < SIZEX; i++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = rand() % (5 - 1 + 1) + (1);
            }
            else
            {
                break;
            }
        }
    }

    return board;
}

///////////////////////////////////////////////// MatchHandler
int check_sequences(char**& board, ask_about_move_object obj, int direction, int all_matches)
{
    int iacheika;
    int counter;
    int k;
    int additional_row;
    
    if (direction == 1 || direction == 2)
    {
        additional_row = direction == 1 ? obj.r - 1 : obj.r;

        for (int i = additional_row; i <= additional_row + 1; i++)
        {
            counter = 0;

            k = obj.c - 2 > 0 ? obj.c - 2 : 0;
            for (int j = k; j <= obj.c + 2 && j < SIZEY; j++)
            {
                iacheika = board[i][j];
                if (iacheika == board[i][obj.c])
                {
                    counter++;
                    if (counter == 3)
                    {
                        all_matches++;
                        for (int l = k; l <= k + 2; l++)
                        {
                            board[i][l] = 0;
                        }
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

        counter = 0;
        k = additional_row - 2 > 0 ? additional_row - 2 : 0;
        char current_symbol = board[k][obj.c];
        for (int i = k + 1; i <= additional_row + 3 && i < SIZEX; i++)
        {
            iacheika = board[i][obj.c];
            if (iacheika == current_symbol)
            {
                counter++;
                if (counter == 2)
                {
                    all_matches++;
                    for (int l = k; l <= k + 2; l++)
                    {
                        board[l][obj.c] = 0;
                    }
                }
            }
            else
            {
                current_symbol = iacheika;
                counter = 0;
                k = i;
            }
        }
    }
   
    if (direction == 3 || direction == 4)
    {
        additional_row = direction == 3 ? obj.c - 1 : obj.c;

        for (int j = additional_row; j <= additional_row + 1; j++)
        {
            counter = 0;

            k = obj.r - 2 > 0 ? obj.r - 2 : 0;
            for (int i = k; i <= obj.r + 2 && i < SIZEY; i++)
            {
                iacheika = board[i][j];
                if (iacheika == board[obj.r][j])
                {
                    counter++;
                    if (counter == 3)
                    {
                        all_matches++;
                        for (int l = k; l <= k + 2; l++)
                        {
                            board[l][j] = 0;
                        }
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

        counter = 0;
        k = additional_row - 2 > 0 ? additional_row - 2 : 0;
        char current_symbol = board[obj.r][k];
        for (int j = k + 1; j <= additional_row + 3 && j < SIZEY; j++)
        {
            iacheika = board[obj.r][j];
            if (iacheika == current_symbol)
            {
                counter++;
                if (counter == 2)
                {
                    all_matches++;
                    for (int l = k; l <= k + 2; l++)
                    {
                        board[obj.r][l] = 0;
                    }
                }
            }
            else
            {
                current_symbol = iacheika;
                counter = 0;
                k = j;
            }
        }
    }

    return all_matches;
}

///////////////////////////////////////////////// UserCommunicator
int get_direction()
{
    int  answer_user;
    cout << "In which direction are we moving? Number:" << endl << "1. up" << endl << "2. down" << endl << "3. left" << endl << "4. right" << endl;
    while (!(cin >> answer_user))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return answer_user;
}

///////////////////////////////////////////////// UserCommunicator
void fill_object(ask_about_move_object& obj)
{
    cout << "The object we want to move" << endl;
    cout << "Horizontal number: ";
    while (!(cin >> obj.r)) 
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Vertical number: ";
    while (!(cin >> obj.c))
    {
        cout << "Incorrect input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

///////////////////////////////////////////////// Validator
vector<int> move(ask_about_move_object& obj)
{
    vector<int> directions;
    if (obj.r != 0)
    {
        directions.push_back(1);
    }
    if (obj.r != SIZEX - 1)
    {
        directions.push_back(2);
    }
    if (obj.c != 0)
    {
        directions.push_back(3);
    }
    if (obj.c != SIZEY - 1)
    {
        directions.push_back(4);
    }

    return directions;
}

///////////////////////////////////////////////// Validator
int validate_user_input_move(char** board, ask_about_move_object& obj)
{
    vector<int> directions = move(obj);
    bool prov = false;
    bool prov_cout = false;
    int answer_user;

    while(!prov)
    {
        answer_user = get_direction();
        for (int i = 0; i < directions.size(); i++)
        {
            if (answer_user == directions[i])
            {
                prov = true;
            }
        }
        system("cls");
        if (prov_cout)
        {
            cout << "invalid" << endl;
        }
        print_board(board);
        prov_cout = true;
    }

    return answer_user;
}

///////////////////////////////////////////////// Validator
void validate_user_input_object(ask_about_move_object& obj, char** board)
{
    bool prov = false;
    obj = { -1, -1 };
    while (obj.r > SIZEX - 1 || obj.c > SIZEY - 1 || obj.r < 0 || obj.c < 0)
    {
        if (prov)
        {
            cout << "invalid" << endl;
            system("cls");
            print_board(board);
        }
        fill_object(obj);
        prov = true;
    }
}

///////////////////////////////////////////////// GameHandler
int ask_user(ask_about_move_object& obj, int answer_user, char** board)
{
    validate_user_input_object(obj, board);
    return validate_user_input_move(board, obj);
}

///////////////////////////////////////////////// GameHandler
void make_replacement(ask_about_move_object obj, char** board, int new_y, int new_x)
{
    char replacement_box;
    replacement_box = board[obj.r][obj.c];
    board[obj.r][obj.c] = board[new_x][new_y];
    board[new_x][new_y] = replacement_box;
}

///////////////////////////////////////////////// GameHandler
void change_cells(int answer_user, ask_about_move_object obj, char** board)
{
    int up = 1;
    int down = 2;
    int left = 3;
    int right = 4;

    if (answer_user == up)
    {
        make_replacement(obj, board, obj.c, obj.r - 1);
    }
    else if (answer_user == down)
    {
        make_replacement(obj, board, obj.c, obj.r + 1);
    }
    else if (answer_user == left)
    {
        make_replacement(obj, board, obj.c - 1, obj.r);
    }
    else if (answer_user == right)
    {
        make_replacement(obj, board, obj.c + 1, obj.r);
    }
}


void break_match(char** board)
{
    for (int i = 0; i < SIZEX; i++)
    {
        for (int j = 0; j < SIZEY; j++)
        {
            if (j < SIZEY - 2 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                for (int k = 2; k <= 6; k++)
                {
                    int i1 = i > 0 ? i - 1 : 0;
                    int i2 = i < SIZEX - 1 ? i + 1 : SIZEX - 1;
                    if (board[i][j + 1] != k && k != board[i1][j + 1] && k != board[i2][j + 1])
                    {
                        board[i][j + 1] = k;
                    }
                }
            }
            if (i < SIZEX - 2 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
            {
                for (int p = 2; p <= 6; p++)
                {
                    //int j1 = j > 0 ? j - 1 : 0;
                    //int j2 = j < SIZEY - 1 ? j + 1 : SIZEY - 1;
                    if (board[i + 1][j] != p && !((j < SIZEY - 1 && board[i + 1][j + 1] == p) || ( j > 0 && board[i + 1][j - 1] == p)))
                    {
                        board[i + 1][j] = p;
                    }
                }
            }
        }
    }
}

///////////////////////////////////////////////// BoardHandler
char** create_board()
{
    char** board = new char* [SIZEX];

    for (int i = 0; i < SIZEX; i++)
    {
        board[i] = new char[SIZEY];
    }
    return board;
}

int main()
{
    //srand(time(NULL));
    char** board = create_board();
    int answer_user = 0;
    int combo_matches = 0;
    int all_matches = 0;
    int number_of_moves = 0;
    ask_about_move_object obj;

    board = fill_board(board);

    break_match(board);

    bool game_over = false;
    auto start = high_resolution_clock::now();
    while (!game_over)
    {
        print_board(board);
        answer_user = ask_user(obj, answer_user, board);
        number_of_moves++;
        change_cells(answer_user, obj, board);
        system("cls");
        all_matches = check_sequences(board, obj, answer_user, all_matches); 
        remove_items(board);
        break_match(board);
        game_over = check_win(all_matches);
    }

    print_final_massage(start, number_of_moves);
            
    return 0;
}
