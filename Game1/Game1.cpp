#include <iostream>
#include <iomanip>

using namespace std;

char** create_board(int SIZEX, int SIZEY);
char* character_array();
void print_board(char** board, int SIZEX, int SIZEY, char* simvol);
int ask_user(char** board, int SIZEX, int SIZEY, char* simvol);
void validate_user_input_object(int row, int col, char** board, int SIZEX, int SIZEY, char* simvol);
void validate_user_input_move(int answer_user, char** board, int SIZEX, int SIZEY, char simvol);
void change_cells(int SIZEX, int SIZEY, int answer_user, int row, int col);

/*
void calculate_points()
{

}

void break_sequences()
{

}

void replace_sequences()
{

}

void check_sequences()
{

}*/

void change_cells(int SIZEX, int SIZEY, int answer_user, int row, int col)
{
    int up = 1;
    int down = 2;
    int left = 3;
    int right = 4;



    int tmp;
    int smena[SIZEX][SIZEY];
    int motvet[SIZEX][SIZEY];
    if (answer_user == up)
    {
        tmp = smena[row][col];
        smena[row][col] = motvet[row][col - 1];
        smena[row][col - 1] = tmp;
    }
    else if (answer_user == down)
    {
        motvet[row][col] = motvet[row][col + 1];
    }
    else if (answer_user == left)
    {
        motvet[row][col] = motvet[row - 1][col];
    }
    else //if((answer_user == right)
    {
        motvet[row][col] = motvet[row + 1][col];
    }
}

void validate_user_input_move(int answer_user, char** board, int SIZEX, int SIZEY, char* simvol)
{
    if (answer_user == 0 && answer_user > 4)
    {
        cout << "invalid" << endl;
        system("cls");
        print_board(board, SIZEX, SIZEY, simvol);
        ask_user(SIZEX, SIZEY);
    }
    else
    {
        cout << "Good job!" << endl;
    }

}

void validate_user_input_object(int row, int col, char** board, int SIZEX, int SIZEY, char* simvol)
{
    if (row > SIZEX && col > SIZEY)
    {
        cout << "invalid" << endl;
        system("cls");
        print_board(board, SIZEX, SIZEY, simvol);
        ask_user(SIZEX, SIZEY);
    }
    else
    {
        cout << "Nice!" << endl;
    }
}

int ask_user(char ** board, int SIZEX, int SIZEY, char* simvol)
{
    int row = 0;
    int col = 0;
    cout << "The object we want to move" << endl;
    cout << "Horizontal number: ";
    cin >> row;
    cout << "Vertical number: ";
    cin >> col;

    validate_user_input_object(row, col, SIZEX, SIZEY, board, simvol);

    int answer_user = 0;
    cout << "In which direction are we moving? Number:" << endl << "1. up" << endl << "2. down" << endl << "3. left" << endl << "4. right" << endl;
    cin >> answer_user;

    validate_user_input_move(answer_user, board, SIZEX, SIZEY, simvol);

    return answer_user;
}

void print_board(char** board, int SIZEX, int SIZEY, char* simvol)
{
    int array_numbering[5] = { 1, 2, 3, 4, 5 };

    cout << "     ";
    for (int i = 0; i < 5; i++)
    {
        cout << array_numbering[i] << "   ";
    }
    cout << endl;

    char s[SIZEX];
    for (int i = 0; i <SIZEX; i++)
    {
        cout << i + 1 << ".";
        for (int j = 0; j < SIZEY; j++)
        {
            s[i] = rand() % (4 - 0 + 1) + (0);
            board[i][j] = s[i];
            cout << setw(4) << board[i][j];
        }
        cout << endl;
    }
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

char** create_board(int SIZEX, int SIZEY)
{
    char** board = new char* [SIZEX];

    for (int i = 0; i < SIZEX; i++)
    {
        board[i] = new char[SIZEY];
    }
    // comment

    return board;
}

int main()
{
    const int SIZEX = 5;
    const int SIZEY = 5;
    char** board = create_board(SIZEX, SIZEY);
    char* simvol = character_array();
    print_board(board, SIZEX, SIZEY, simvol);
    ask_user(SIZEX, SIZEY);
    validate_user_input_object(answer_user);
    change_cells(SIZEX, SIZEY, answer_user, row, col);

    return 0;
}
