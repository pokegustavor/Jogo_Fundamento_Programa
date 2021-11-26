#include "Obstaculo.h"

Obstaculo::Obstaculo(sf::Vector2f size, float x, float y):Entidade(x,y)
{
	sprite = sf::RectangleShape(size);
	sprite.setPosition(sf::Vector2f(x, y));
}

Obstaculo::~Obstaculo()
{
}
