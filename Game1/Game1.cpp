#include <iostream>
#include <iomanip>

using namespace std;

const int SIZEX = 5;
const int SIZEY = 5;
const int MAX_ITERATIONS = 50;

struct for_ask_user { int au = 0; };
struct ask_about_move_object { int r = 0; int c = 0; };

void change_cells(int answer_user, ask_about_move_object obj, char** board);
void validate_move(ask_about_move_object& obj, char** board, int row_1, int col_1, int row_2, int col_2, int answer_user);


char ** fill_board(char** board)
{
    for (int i = 0; i < SIZEX; i++)
    {
        for (int j = 0; j < SIZEY; j++)
        {
            board[i][j] = rand() % (5 - 1 + 1) + (1);
        } 
    } // comm

    return board;
}

void print_board(char** board) //char* simvol
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

void calculate_points(int combo_matches)
{
    int points = 10;
    int combo_points = 50;
    int combo_p = 0;
    int point_p = 0; 
    int max_combo = 0;

    if (combo_matches == 1)
    {
        point_p += points;
    }

    combo_p = combo_points * combo_matches;

    if (combo_matches > max_combo)
    {
        max_combo = combo_matches;
    }

    int score = combo_p + point_p;

    cout << "Scrore: " << score << endl;
    cout << "Max combo: " << max_combo << endl;
    cout << endl;
}

char** remove_items(char**& board)
{
    for (int j = 0; j < SIZEY; j++)
    {
        int k = SIZEX - 1;
        for (int i = SIZEX -1; i >= 0; i--) 
        {
            if (board[i][j] == 0)
            {                
                swap(board[k][j], board[k - 1][j]);
                k--;
            }
        }
        for (int i = k; i >= 0; i--)
        {
            board[i][j] = rand() % (5 - 1 + 1) + (1);
        }
    }

    return board;
}

int check_sequences_and_remove(char**& board, ask_about_move_object obj)
{
    int all_matches = 0;
    bool found_match = true;
    while (found_match)
    {
        found_match = false;

        for (int i = 0; i <= obj.r; i++)
        {
            for (int j = 0; j <= obj.c - 2; j++)
            {
                if (board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
                {
                    int match_value = board[i][j];
                    int k = j;
                    while (k < obj.c && board[i][k] == match_value)
                    {
                        board[i][k] = 0;
                        all_matches++;
                        k++;
                    }
                    found_match = true;
                }
            }
        }
        
        for (int j = 0; j <= obj.c; j++)
        {
            for (int i = 0; i <= obj.r - 2; i++)
            {
                if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
                {
                    int match_value = board[i][j];
                    int k = j;
                    while (k < obj.r && board[k][j] == match_value)
                    {
                        board[k][j] = 0;
                        all_matches++;
                        k++;
                    }
                    found_match = true;
                }
            }
        }
        remove_items(board);
    }

    return all_matches;
}

int delete_and_count_combo(char** board, ask_about_move_object obj, int all_matches)
{
    int combo_matches = 0;

    do {
        all_matches = check_sequences_and_remove(board, obj);
        combo_matches += all_matches;
    } while (all_matches > 0);

    return combo_matches;
}

int get_direction(int answer_user)
{
    cout << "In which direction are we moving? Number:" << endl << "1. up" << endl << "2. down" << endl << "3. left" << endl << "4. right" << endl;
    cin >> answer_user;

    return answer_user;
}

void fill_object(ask_about_move_object& obj)
{
    cout << "The object we want to move" << endl;
    cout << "Horizontal number: ";
    cin >> obj.r;
    cout << "Vertical number: ";
    cin >> obj.c;
}

int validate_user_input_move(int answer_user, char** board)
{
    while (answer_user <= 0 && answer_user > 4)
    {
        cout << "invalid" << endl;
        system("cls");

        print_board(board);
        answer_user = get_direction(answer_user);
    }
    return answer_user;
}

void validate_user_input_object(ask_about_move_object& obj, char** board)
{
    while (obj.r > SIZEX || obj.c > SIZEY)
    {
        cout << "invalid" << endl;
        system("cls");

        print_board(board);
        fill_object(obj);
    }
}

int ask_user(ask_about_move_object& obj, int answer_user, char** board)
{
    fill_object(obj);
    validate_user_input_object(obj, board);
    return get_direction(answer_user);
}

void validate_move(ask_about_move_object& obj, char** board, int row_1, int col_1, int row_2, int col_2, int answer_user)
{
    if (row_1 < 0 || row_1 >= SIZEX || col_1 < 0 || col_1 >= SIZEY || row_2 < 0 || row_2 >= SIZEX || col_2 < 0 || col_2 >= SIZEY)
    {
        cout << "Try again!" << endl;

        system("cls");
        print_board(board);
        answer_user = ask_user(obj, answer_user, board);
        answer_user = validate_user_input_move(answer_user, board);
        change_cells(answer_user, obj, board);
    }
}

void make_replacement(ask_about_move_object obj, char** board, int new_y, int new_x)
{
    char replacement_box;
    replacement_box = board[obj.r][obj.c];
    board[obj.r][obj.c] = board[new_x][new_y];
    board[new_x][new_y] = replacement_box;
}

void change_cells(int answer_user, ask_about_move_object obj, char** board)
{
    int up = 1;
    int down = 2;
    int left = 3;
    int right = 4;

    if (answer_user == up)
    {
        validate_move(obj, board, obj.r, obj.c, obj.r - 1, obj.c, answer_user);
        make_replacement(obj, board, obj.c, obj.r - 1);
    }
    else if (answer_user == down)
    {
        validate_move(obj, board, obj.r, obj.c, obj.r + 1, obj.c, answer_user);
        make_replacement(obj, board, obj.c, obj.r + 1);
    }
    else if (answer_user == left)
    {
        validate_move(obj, board, obj.r, obj.c, obj.r, obj.c - 1, answer_user);
        make_replacement(obj, board, obj.c - 1, obj.r);
    }
    else if (answer_user == right)
    {
        validate_move(obj, board, obj.r, obj.c, obj.r, obj.c + 1, answer_user);
        make_replacement(obj, board, obj.c + 1, obj.r);
    }
}

void shuffle_board(char**& board, ask_about_move_object obj)
{
    for (int i = 0; i < obj.r; i++)
    {
        for (int j = 0; j < obj.c; j++) 
        {
            int random_row = rand() % obj.r;
            int random_col = rand() % obj.c;
            swap(board[i][j], board[random_row][random_col]);
        }
    }
}

bool check_moves(char** board, ask_about_move_object obj)
{
    for (int i = 0; i < obj.r; i++)
    {
        for (int j = 0; j < obj.c; j++)
        {
            if (j < obj.c - 2)
            {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
                {
                    return true;
                }
            }
            if (i < obj.r - 2)
            {
                if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
                {
                    return true;
                }
            }
        }
    }
    return false;
} 

char* character_array()
{
    char simvol[5];
    for (int i = 2, n = 0; i <= 6; ++i, ++n)
    {
        simvol[n] = (char)i;
    }

    return simvol;
}

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
    char* simvol = character_array();
    int answer_user = 0;
    int combo_matches = 0;
    int all_matches = 0;
    ask_about_move_object obj;
    board = fill_board(board);

    int iterations = 0;
    while (check_moves(board, obj) && iterations < MAX_ITERATIONS)
    {
        shuffle_board(board, obj);
        iterations++;
    }

    bool game_over = false;
    if (iterations == MAX_ITERATIONS)
    {
        game_over = true;
    }

    while (!game_over)
    {
        print_board(board);
        answer_user = ask_user(obj, answer_user, board);
        answer_user = validate_user_input_move(answer_user, board);
        change_cells(answer_user, obj, board);
        system("cls");
        all_matches = check_sequences_and_remove(board, obj);
        //board = remove_items(board);
        combo_matches = delete_and_count_combo(board, obj, all_matches);
        calculate_points(combo_matches);
        
        /*if (!check_moves(board, obj))
        {
            game_over = true;
        }*/
    }

    return 0;
}
