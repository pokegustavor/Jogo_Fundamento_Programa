#include "Projétil.h"

Projétil::Projétil(bool esquerda = false)
{
	this->esquerda = esquerda;
	sprite = sf::RectangleShape(sf::Vector2f(10.0f,10.0f));
	sprite.setFillColor(sf::Color::Red);
}

Projétil::~Projétil()
{
}

void Projétil::Executar()
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
	Imprimir_se();
	if(velocidadeHorizontal == 0 && !capturado)
	{
		morto = true;
	}
}

void Projétil::Imprimir_se()
{
	Entidade::Imprimir_se();
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
	shape.setFillColor(sf::Color::White);
	shape.setPosition(sf::Vector2f(x, y));
	gerenciador->window->draw(shape);
}
