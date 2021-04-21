#include "Enemy.h"

Enemy::Enemy()
	: _Health(14)
{
	texture.loadFromFile(TEXTURE_PATH);
	sprite.setTexture(texture);
}

void Enemy::Update()
{
	std::cout << _Health;
}


void Enemy::move(float speed)
{
	sprite.move(-speed, 0);
	if (_direction && (sprite.getPosition().y - speed / 2) > 0) {
		sprite.move(0, -5);
	}
	else {
		_direction = false;
	}
	if (!_direction && (sprite.getPosition().y + texture.getSize().y + speed / 2) < 200) {
		sprite.move(0, +5);
	}
	else {
		_direction = true;
	}
}
