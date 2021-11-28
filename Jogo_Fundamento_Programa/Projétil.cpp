#include "Projétil.h"

Projétil::Projétil(bool esquerda, float x, float y):Entidade(x,y)
{
	this->esquerda = esquerda;
	this->x = x;
	this->y = y;
	sprite.setPosition(sf::Vector2f(x, y));
	sprite = sf::RectangleShape(sf::Vector2f(10.0f,10.0f));
	sprite.setFillColor(sf::Color::Red);
	if (esquerda)
	{
		velocidadeHorizontal = -7.f;
	}
	else
	{
		velocidadeHorizontal = 7.f;
	}
	time(&tempoCapturado);
}

Projétil::~Projétil()
{
}

void Projétil::Executar()
{
	
	velocidadeVertical = 0;
	Entidade::Executar();
	Imprimir_se();
	if(capturado)
	{
		time_t now;
		time(&now);
		if((double)(now - tempoCapturado) > 0.75f)
		{
			morto = true;
		}
	}
	else
	{
		time(&tempoCapturado);
	}
	if(velocidadeHorizontal == 0 && !capturado && !paralizado)
	{
		morto = true;
	}
	if (esquerda)
	{
		velocidadeHorizontal = -7.f;
	}
	else
	{
		velocidadeHorizontal = 7.f;
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
