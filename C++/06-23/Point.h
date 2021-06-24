#pragma once
#include "Default.h"

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	friend ostream& operator<<(ostream& os, const Point& pos);
};