#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
private:
	int r = 0; 
	int c = 0;

public:
	int getRow();
	int getCol();
	void setRow(int inputRow);
	void setCol(int);

};


#endif // !COORDINATES_H