#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Car.h"
#include "Map.h"
#include "Menu.h"
#include "Music.h"
#include "Player.h"
using namespace sf;

int main()
{
	const int x{ 0 };

	RenderWindow window(VideoMode(1366, 768), "New_Window", Style::Fullscreen, ContextSettings());

	Player player(x);

	Event event;

	while (window.isOpen())
	{
		player.Refresh(window);

		while (window.pollEvent(event)) // <- Обработчик событий
		{
			player.Game_event(window, event);
		}

		player.Move_car_on_rows();

		window.clear(Color::Cyan);

		// <- Отрисовка графики
		player.Draw_graphics(window);

		window.display();
	}
}
