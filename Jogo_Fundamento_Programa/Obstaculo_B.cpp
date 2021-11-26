#include "Obstaculo_B.h"

Obstaculo_B::Obstaculo_B(sf::Vector2f size, float x, float y):Obstaculo(size,x,y)
{
	sprite.setFillColor(sf::Color::Red);
	sprite.setRotation(45.f);
}

Obstaculo_B::~Obstaculo_B()
{
}

void Obstaculo_B::Executar()
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
	Entidade::Executar();
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
}
