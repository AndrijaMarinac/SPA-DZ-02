#include<vector>
#include "Cell.h"
using namespace sf;

void Cell::InitCell(float resolution, float position_x, float position_y, bool status)
{
	cellbody.setPrimitiveType(Quads);
	cellbody.resize(4);
	SetNeighbours(0);
	SetPosition_x(position_x);
	SetPosition_y(position_y);
	SetStatus(status);

	cellbody[0].position = Vector2f(position_x, position_y);
	cellbody[1].position = Vector2f(position_x + resolution, position_y);
	cellbody[2].position = Vector2f(position_x + resolution, position_y + resolution);
	cellbody[3].position = Vector2f(position_x, position_y + resolution);
 
	if (status == 0)
	{
		cellbody[0].color = Color::Black;
		cellbody[1].color = Color::Black;
		cellbody[2].color = Color::Black;
		cellbody[3].color = Color::Black;
	}
	if (status == 1)
	{
		cellbody[0].color = Color::White;
		cellbody[1].color = Color::White;
		cellbody[2].color = Color::White;
		cellbody[3].color = Color::White;
	}
}

void Cell::SetPosition_x(float position_x)
{
	this->position_x = position_x;
}

void Cell::SetPosition_y(float position_y)
{
	this->position_y = position_y;
}

float Cell::GetPosition_x()
{
	return position_x;
}

float Cell::GetPosition_y()
{
	return position_y;
}

void Cell::SetStatus(bool status)
{
	this->status = status;

	if (status == 0)
	{
		cellbody[0].color = Color::Black;
		cellbody[1].color = Color::Black;
		cellbody[2].color = Color::Black;
		cellbody[3].color = Color::Black;
	}
	if (status != 0)
	{
		cellbody[0].color = Color::White;
		cellbody[1].color = Color::White;
		cellbody[2].color = Color::White;
		cellbody[3].color = Color::White;
	}
}

bool Cell::GetStatus()
{
	return status;
}

VertexArray Cell::GetCellBody()
{
	return cellbody;
}

void Cell::SetNeighbours(int neighbours)
{
	this->neighbours = neighbours;
}

int Cell::GetNeighbours()
{
	return neighbours;
}
