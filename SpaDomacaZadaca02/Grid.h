#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include"Cell.h"
using namespace std;
using namespace sf;
class Grid
{
private:
	int resolution;					
	float width;				
	float hight;				
	vector<vector<Cell>> cellgrid;	
	bool Rand();	

public:
	Grid(int resolution, RenderWindow& window);
	void CheckStatus();
	void draw(RenderWindow& window);
	void Clear();

};

