#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Cell
{
private:
	bool status;			//0 = dead, 1 = alive
	int neighbours;			
	float position_x;		
	float position_y;		
	VertexArray cellbody;	

public:
	void InitCell(float resolution, float position_x, float position_y, bool status);

	void SetPosition_x(float position_x);
	void SetPosition_y(float position_y);
	float GetPosition_x();
	float GetPosition_y();
	void SetStatus(bool status);
	bool GetStatus();
	void SetNeighbours(int neighbours);
	int GetNeighbours();
	VertexArray GetCellBody();

};