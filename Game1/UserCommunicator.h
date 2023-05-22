#ifndef USERCOMMUNICATOR_H
#define USERCOMMUNICATOR_H
#include <iostream>
#include <chrono>
#include "Coordinates.h"
#include "Validator.h"
#include "Constants.h"

using namespace std;
using namespace std::chrono;

class UserCommunicator
{
public:
	void print_final_massage(const std::chrono::high_resolution_clock::time_point& start, int number_of_moves);
	int get_direction(vector<int> directions);
	void fill_object(Coordinates* obj);


};

#endif // !USERCOMMUNICATOR_H