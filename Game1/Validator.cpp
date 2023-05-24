#include "Validator.h"

vector<int> Validator::move(Coordinates* obj)
{
    vector<int> directions;
    if (obj->getRow() != 0)
        directions.push_back(1);
    if (obj->getRow() != SIZEX - 1)
        directions.push_back(2);
    if (obj->getCol() != 0)
        directions.push_back(3);
    if (obj->getCol() != SIZEY - 1)
        directions.push_back(4);

    return directions;
}

int Validator::validate_user_input_move(BoardHandler* bordH, Coordinates* obj)
{

    vector<int> directions = move(obj);
    bool prov = false;
    bool prov_cout = false;
    int answer_user;

    while (!prov)
    {
        answer_user = ip.get_direction(directions);
        for (int i = 0; i < directions.size(); i++)
            if (answer_user == directions[i])
                prov = true;

        system("cls");
        if (prov_cout)
            cout << "invalid" << endl;

        bordH->print_board();
        prov_cout = true;
    }

    return answer_user;
}

void Validator::validate_user_input_object(Coordinates* obj, BoardHandler* bordH)
{
    bool prov = false;
    int tmp = -1;
    obj->setRow(tmp);
    obj->setCol(tmp);

    while (obj->getRow() > SIZEX - 1 || obj->getCol() > SIZEY - 1 || obj->getRow() < 0 || obj->getCol() < 0)
    {
        if (prov)
        {
            cout << "invalid" << endl;
            system("cls");
            bordH->print_board();
        }

        ip.fill_object(obj);
        prov = true;
    }
}
