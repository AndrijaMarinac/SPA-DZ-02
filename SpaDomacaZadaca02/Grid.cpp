#include "Grid.h"


bool Grid::Rand()
{
	int temp = rand() % (12);
	if (temp == 2 || temp == 4 || temp == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Grid::Grid(int resolution, RenderWindow& window)
{
	srand(time(nullptr));

	this->resolution = resolution;
 
	width = (window.getSize().x / this->resolution);
	hight = (window.getSize().y / this->resolution);

	cellgrid.resize(hight);
	for (int i = 0; i < hight; i++)
	{
		cellgrid[i].resize(width);
	}

	for (int y = 0; y < hight; y++)
	{
		float position_y = y * this->resolution;

		for (int x = 0; x < width; x++)
		{
			float positon_x = x * this->resolution;	

			cellgrid[y][x].InitCell(this->resolution, positon_x, position_y, Rand());
		}
	}
}

void Grid::CheckStatus()
{
	for (int y = 1; y < (hight-1); y++)
	{
		for (int x = 1; x < (width-1); x++)
		{
			int Neighbours = 0;

			int yp = y + 1;
			int xp = x + 1;
			int ym = y - 1;
			int xm = x - 1;

			if (cellgrid[y][xp].GetStatus() == 1)
			{
				Neighbours++;
			} 
			if (cellgrid[yp][xp].GetStatus() == 1)
			{
				Neighbours++;
			}
			if (cellgrid[yp][x].GetStatus() == 1)
			{
				Neighbours++;
			}
			if(cellgrid[yp][xm].GetStatus() == 1)
			{
				Neighbours++;
			}
			if(cellgrid[y][xm].GetStatus() == 1)
			{
				Neighbours++;
			}
			if(cellgrid[ym][xm].GetStatus() == 1)
			{
				Neighbours++;
			}
			if(cellgrid[ym][x].GetStatus() == 1)
			{
				Neighbours++;
			}
			if(cellgrid[ym][xp].GetStatus() == 1)
			{
				Neighbours++;
			}
			
			cellgrid[y][x].SetNeighbours(Neighbours);
		}		
	}

	for (int y = 1; y < (hight - 1); y++)
	{
		for (int x = 1; x < (width - 1); x++)
		{
			if (cellgrid[y][x].GetStatus() == 1)	
			{
				if (cellgrid[y][x].GetNeighbours() < 2)		
				{
					cellgrid[y][x].SetStatus(0); 
				}
				if (cellgrid[y][x].GetNeighbours() > 3)		
				{
					cellgrid[y][x].SetStatus(0); 
				}
				cellgrid[y][x].SetNeighbours(0); 
			}
			if (cellgrid[y][x].GetStatus() == 0) 
			{
				if (cellgrid[y][x].GetNeighbours() > 2 && cellgrid[y][x].GetNeighbours() < 4) 
				{
					cellgrid[y][x].SetStatus(1); 
				}
				cellgrid[y][x].SetNeighbours(0); 
			}
		}
	}
}

void Grid::draw(RenderWindow& window)
{ 
	for (int y = 1; y < hight - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			window.draw(cellgrid[y][x].GetCellBody());
		}
	}
}

void Grid::Clear()
{
	for (int y = 0; y < hight; y++)
	{
		float position_y = y * this->resolution;	

		for (int x = 0; x < width; x++)
		{
			float positon_x = x * this->resolution;		

			cellgrid[y][x].InitCell(this->resolution, positon_x, position_y, Rand());
		}
	}
}