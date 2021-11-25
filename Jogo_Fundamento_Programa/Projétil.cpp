#include "Proj�til.h"

Proj�til::Proj�til(bool esquerda = false)
{
	this->esquerda = esquerda;
	sprite = sf::RectangleShape(sf::Vector2f(10.0f,10.0f));
	sprite.setFillColor(sf::Color::White);
}

Proj�til::~Proj�til()
{
}

void Proj�til::Executar()
{
	if(esquerda)
	{
		velocidadeHorizontal = -0.2f;
	}
	else
	{
		velocidadeHorizontal = 0.2f;
	}
	velocidadeVertical = 0;
	Entidade::Executar();
	if(velocidadeHorizontal == 0 && !capturado)
	{
		morto = true;
	}
}
