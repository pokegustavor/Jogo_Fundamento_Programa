#include "Obstaculo_A.h"

Obstaculo_A::Obstaculo_A(sf::Vector2f size):Obstaculo(size)
{
	sprite.setFillColor(sf::Color::Green);
}

Obstaculo_A::~Obstaculo_A()
{
}

void Obstaculo_A::Executar()
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
	Entidade::Executar();
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
}
