#pragma once
#include "Lista.h"
#include "Inimigo.h"
class Gerenciador_Colisões
{
private:
	Lista<Inimigo>* LIs;
public:
	Gerenciador_Colisões();
	bool Colidindo(sf::RectangleShape eu, sf::RectangleShape alvo);
	void Colidir(Entidade* temp, Entidade* alvo);
};

