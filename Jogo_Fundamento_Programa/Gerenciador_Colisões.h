#pragma once
#include "Lista.h"
#include "Inimigo.h"
class Gerenciador_Colis�es
{
private:
	Lista<Inimigo>* LIs;
public:
	Gerenciador_Colis�es();
	bool Colidindo(sf::RectangleShape eu, sf::RectangleShape alvo);
	void Colidir(Entidade* temp, Entidade* alvo);
};

