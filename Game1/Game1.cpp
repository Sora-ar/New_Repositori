#include <iostream>
#include <iomanip>

using namespace std;


/*
int validate()
{
    int number;
    while (true)
    {
        cin >> number;
        if (number < 0)
        {
            cout << "valide" << endl;
            return number;
        }
        else
        {
            cout << "invalide" << endl;
        }
    }
}


void change_cells()
{

}

void check_sequences()
{

}

void replace_sequences()
{

}

void break_sequences()
{

}

void calculate_points()
{

}*/

/*void peremeshenie(char ** board, int sizeX, int sizeY)
{
    int nomi = 0;
    int nomj = 0;
    int up = 1;
    int down = 2;
    int left = 3;
    int right = 4;
    int otvet_polz = 0;
    cout << "Объект, который хотим переместить" << endl;
    cout << "Номер по горизонтали: ";
    cin >> nomi;
    cout << "Номер по вертикали: ";
    cin >> nomj;
    cout << "В какую сторону двигаем? Цифра:" << endl << "1. вверх" << endl << "2. вниз" << endl << "3. влево" <<  endl << "4. вправо" << endl;
    cin >> otvet_polz;


    while(true)
    {
        if(otvet_polz == 0 || otvet_polz > 4)
        {
            system("cls");
            playing_field(board, sizeX, sizeY);
            peremeshenie(board, sizeX, sizeY);
        }
        break;
    }

    int tmp;
    int smena[0][0];
    if(otvet_polz == up)
    {
        tmp = smena[nomi][nomj];
        smena[nomi][nomj] = motvet[nomi][nomj - 1];
        smena[nomi][nomj - 1] = tmp;
    }
    else if(otvet_polz == down)
    {
        motvet[nomi][nomj] = motvet[nomi][nomj + 1];
    }
    else if(otvet_polz == left)
    {
        motvet[nomi][nomj] = motvet[nomi - 1][nomj];
    }
    else //if(otvet_polz == right)
    {

        motvet[nomi][nomj] = motvet[nomi + 1][nomj];
    }


}*/
/*
void validate_user_input()
{
    while(true)
    {

    }

}

void ask_user()
{
    int number_
}*/

void print_board(char** board, int sizeX, int sizeY, char* simvol)
{
    int array_numbering[5] = { 1, 2, 3, 4, 5 };

    cout << "     ";
    for (int i = 0; i < 5; i++)
    {
        cout << array_numbering[i] << "   ";
    }
    cout << endl;

    char s[sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        cout << i + 1 << ".";
        for (int j = 0; j < sizeY; j++)
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

char** create_board(int sizeX, int sizeY)
{
    char** board = new char* [sizeX];

    for (int i = 0; i < sizeX; i++)
    {
        board[i] = new char[sizeY];
    }

    return board;
}

int main()
{
    const int sizeX = 5;
    const int sizeY = 5;
    char** board = create_board(sizeX, sizeY);
    char* simvol = character_array();
    print_board(board, sizeX, sizeY, simvol);

    return 0;
}
