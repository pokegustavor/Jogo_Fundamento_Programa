#include "Personagem.h"

Personagem::Personagem(float x, float y):Entidade(x,y)
{
	num_vidas = 1;
}

Personagem::~Personagem()
{
}

void Personagem::Executar()
{
	if(num_vidas <= 0)
	{
		morto = true;
	}
	Entidade::Executar();
}
