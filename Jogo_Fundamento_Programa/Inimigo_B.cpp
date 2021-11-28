#include "Inimigo_B.h"

void Inimigo_B::Atirar()
{
	bool esquerda = true;
	if(alvo->x > x)
	{
		esquerda = false;
	}
	Projétil* tiro = new Projétil(esquerda, x + sprite.getSize().x / 4, y + sprite.getSize().y / 4);
	//Projétil* tiro = new Projétil(esquerda, 500.f, 500.f);
	tiro->setGerenciador(gerenciador);
	entidades->LEs.Add(tiro);
}

Inimigo_B::Inimigo_B(Jogador* jogador1, Jogador* jogador2, float x, float y):Inimigo(x,y)
{
	this->jogador1 = jogador1;
	this->jogador2 = jogador2;
	time(&ultimoTiro);
	sprite.setFillColor(sf::Color::Red);
}

Inimigo_B::~Inimigo_B()
{
}

void Inimigo_B::Executar()
{
	AtualizarAlvo();
	time_t now;
	time(&now);
	if(paralizado)
	{
		time(&ultimoTiro);
	}
	if ((double)(now - ultimoTiro) > 3.0 && alvo != nullptr && !paralizado)
	{
		time(&ultimoTiro);
		Atirar();
	}
	capturado = false;
	Inimigo::Executar();
	Imprimir_se();
}

void Inimigo_B::Imprimir_se()
{
	Entidade::Imprimir_se();
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(sf::Vector2f(x, y));
	gerenciador->window->draw(shape);
}

void Inimigo_B::AtualizarAlvo()
{
	float DistanciaX = 0;
	float DistanciaY = 0;
	float DistanciaX2 = 0;
	float DistanciaY2 = 0;
	if (alvo != nullptr && alvo->morto)alvo = nullptr;
	if (jogador1 != nullptr && jogador1->morto)jogador1 = nullptr;
	if (jogador2 != nullptr && jogador2->morto)jogador2 = nullptr;
	if (jogador1 == nullptr && jogador2 != nullptr)
	{
		alvo = jogador2;
		return;
	}
	if (jogador1 != nullptr && jogador2 == nullptr)
	{
		alvo = jogador1;
		return;
	}
	if (jogador1 != nullptr)
	{
		if (jogador1->x > x)
		{
			DistanciaX = jogador1->x - x;
		}
		else
		{
			DistanciaX = x - jogador1->x;
		}
		if (jogador1->y > y)
		{
			DistanciaY = jogador1->y - y;
		}
		else
		{
			DistanciaY = y - jogador1->y;
		}
	}
	if (jogador2 != nullptr)
	{
		if (jogador2->x > x)
		{
			DistanciaX2 = jogador2->x - x;
		}
		else
		{
			DistanciaX2 = x - jogador2->x;
		}
		if (jogador2->y > y)
		{
			DistanciaY2 = jogador2->y - y;
		}
		else
		{
			DistanciaY2 = y - jogador2->y;
		}
		if (DistanciaX + DistanciaY > DistanciaX2 + DistanciaY2)
		{
			alvo = jogador2;
			return;
		}
	}
	alvo = jogador1;
}
