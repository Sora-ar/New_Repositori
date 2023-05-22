#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <vector>
#include "BoardHandler.h"
#include "Coordinates.h"
#include "Constants.h"
#include "UserCommunicator.h"

using namespace std;

class Validator
{
public:
	vector<int> move(Coordinates* obj);
	int validate_user_input_move(BoardHandler* bordH, Coordinates* obj);
	void validate_user_input_object(Coordinates* obj, BoardHandler* bordH);

};

#endif // !VALIDATOR_H