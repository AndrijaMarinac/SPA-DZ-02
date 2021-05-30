#include <SFML/Graphics.hpp>
#include<SFML/System/Time.hpp>
#include<SFML/System/Clock.hpp>
#include<ctime>
#include<cmath>
#include<vector>

#include"Grid.h"
using namespace std;
using namespace sf;

int main()
{
	Clock clock;
	RenderWindow window(VideoMode(800, 600), "Game of Life!");
	window.setFramerateLimit(60);
	Time refresh = seconds(2.0f);

	Grid GameOfLife(4,window);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();	
		
		GameOfLife.draw(window);	

		GameOfLife.CheckStatus();	

		Time elapsed = clock.getElapsedTime();	
		if (elapsed >= refresh)	
		{
			clock.restart();	
		}

		window.display();
	}

	return 0;
}