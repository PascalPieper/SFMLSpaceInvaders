#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Entity.h"
#include "IOReading.h"
#include <iostream>
#include "FilePath.h"
using namespace sf;
int main()
{
	IOReading io;
	FilePath path("test", "test");
	int test = io.ProvideInt(&path, "test", 1);
	std::cout << test;
	EntityManager em;
	em.CreateBackground("test", Vector2f{ 4.f, 9.f });

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Texture text;
	text.loadFromFile("rainerSmall.jpg");

	RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	Sprite sprite(text);
	sprite.setPosition(5.f, 5.f);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(320, 240);
	rectangle.setOrigin(rectangle.getSize().x / 2,
		rectangle.getSize().y / 2);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sprite.move(0, 0.01f);
		window.clear();
		window.draw(shape);
		window.draw(rectangle);
		window.draw(sprite);
		window.display();
	}

	return 0;
}