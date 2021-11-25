#include "Inimigo_A.h"

Inimigo_A::Inimigo_A(Jogador* jogador1, Jogador* jogador2):Inimigo::Inimigo()
{
	this->jogador1 = jogador1;
	this->jogador2 = jogador2;
	AtualizarAlvo();
	sprite.setFillColor(sf::Color::Red);
}

Inimigo_A::~Inimigo_A()
{
}

void Inimigo_A::AtualizarAlvo()
{
	float DistanciaX = 0;
	float DistanciaY = 0;
	float DistanciaX2 = 0;
	float DistanciaY2 = 0;
	if(jogador1 != nullptr)
	{
		if(jogador1->x > x)
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
	if(jogador2 != nullptr)
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
		if(DistanciaX + DistanciaY > DistanciaX2 + DistanciaY2)
		{
			alvo = jogador2;
			return;
		}
	}
	alvo = jogador1;
}

void Inimigo_A::Executar()
{
	AtualizarAlvo();
	if (alvo != nullptr)
	{
		if (alvo->x > x)
		{
			x += 0.05f;
		}
		else if (alvo->x < x)
		{
			x -= 0.05f;
		}
		if (alvo->y < y - sprite.getSize().y/2 && noChao)
		{
			velocidadeVertical = -0.1f;
		}
	}
	Personagem::Executar();
}
