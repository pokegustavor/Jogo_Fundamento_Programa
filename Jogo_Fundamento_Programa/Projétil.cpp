#include "Projétil.h"

Projétil::Projétil(bool esquerda, float x, float y):Entidade(x,y)
{
	this->esquerda = esquerda;
	this->x = x;
	this->y = y;
	sprite.setPosition(sf::Vector2f(x, y));
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
		velocidadeHorizontal = -7.f;
	}
	else
	{
		velocidadeHorizontal = 7.f;
	}
	velocidadeVertical = 0;
	Entidade::Executar();
	Imprimir_se();
	if(velocidadeHorizontal == 0 && !capturado && !paralizado)
	{
		morto = true;
	}
}

void Projétil::Imprimir_se()
{
	if (!morto)
	{
		Entidade::Imprimir_se();
		sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
		shape.setFillColor(sf::Color::White);
		shape.setPosition(sf::Vector2f(x, y));
		gerenciador->window->draw(shape);
	}
}
