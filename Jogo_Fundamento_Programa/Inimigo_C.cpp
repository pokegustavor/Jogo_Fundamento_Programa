#include "Inimigo_C.h"

Inimigo_C::Inimigo_C(Jogador* jogador1, Jogador* jogador2, float x, float y):Inimigo(x,y)
{
	this->jogador1 = jogador1;
	this->jogador2 = jogador2;
	time(&ultimoSpawn);
	time(&ultimoTP);
	sprite.setFillColor(sf::Color::Cyan);
}

Inimigo_C::~Inimigo_C()
{
}

void Inimigo_C::Executar()
{
	time_t now;
	time(&now);
	capturado = false;
	if(paralizado)
	{
		time(&ultimoSpawn);
		time(&ultimoTP);
	}
	if((double)(now - ultimoSpawn) > 3.f)
	{
		time(&ultimoSpawn);
		if (rand() % 4 == 1)
		{
			Inimigo_A* servo = new Inimigo_A(jogador1, jogador2, x, y);
			servo->setGerenciador(gerenciador);
			entidades->LEs.Add(servo);
		}
	}
	if((double)(now - ultimoTP) > 1.f)
	{
		time(&ultimoTP);
		x = (float)(rand() % 1300) + 150.f;
		int destY = rand() % 6;
		y = 600.f - (destY * 80);
	}
	Inimigo::Executar();
	Entidade::Imprimir_se();
}
