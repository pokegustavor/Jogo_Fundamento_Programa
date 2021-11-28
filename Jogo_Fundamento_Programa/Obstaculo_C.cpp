#include "Obstaculo_C.h"

Obstaculo_C::Obstaculo_C(sf::Vector2f size,float x, float y):Obstaculo(size, x, y)
{
	time(&ultimaMuldanca);
	sprite.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
	sprite.setFillColor(sf::Color::Black);
}

Obstaculo_C::~Obstaculo_C()
{
}

void Obstaculo_C::Executar()
{
	time_t now;
	time(&now);
	if ((double)(now - ultimaMuldanca) > 6.f)
	{
		time(&ultimaMuldanca);
		int randPos = rand() % 5;
		this->x = (gerenciador->window->getSize().x / 5.f) * randPos;
		this->y = 0.f;
		sprite.setPosition(sf::Vector2f(x, y));
	}
	morto = false;
	capturado = false;
	velocidadeVertical = 0;
	Entidade::Executar();
	Imprimir_se();
}
