#include <SFML/Graphics.hpp>
#include "IOReading.h"
#include <iostream>
#include "FilePath.h"
#include "Thor/Resources.hpp"
#include <Thor/Input.hpp>
#include "Entity.h"
using namespace sf;

int main()
{


	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	window.setFramerateLimit(60);
	GameManager gm;
	Entity et(&gm);

	/*
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
		*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		et.EntitySprite.move(5.f, 1.f);
		window.draw(et.EntitySprite);
		window.clear();
		window.display();
	}

	return 0;
}