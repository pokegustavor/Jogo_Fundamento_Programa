#include "Inimigo.h"

Inimigo::Inimigo(float x, float y):Personagem(x,y)
{
	num_vidas = 1;
	alvo = nullptr;
	jogador1 = nullptr;
	jogador2 = nullptr;
	entidades = nullptr;
}

Inimigo::~Inimigo()
{
}

void Inimigo::Executar()
{
	
	Personagem::Executar();
}

void Inimigo::setListEnt(ListaEntidades* lista)
{
	entidades = lista;
}
