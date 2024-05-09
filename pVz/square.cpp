#include "square.h"

Square::Square(float x , float y , std::string l_i , std::string i)
{
	width = x;
	height = y;
	free = true;
	line_id = l_i;
	id = i;

}

bool Square:: grow_plant(Plant *p)
{
	if(free == true)
	{
		current_plant = p;
		free = false;
		return true;
	}
	else
		return false;
}
std::string Square::get_id()
{
	return id;
}

void Square::Clean()
{
	free = true;
}