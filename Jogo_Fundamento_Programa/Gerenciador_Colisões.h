#pragma once
#include "Lista.h"
#include "Inimigo.h"
class Gerenciador_Colis�es
{
private:
	Lista<Inimigo>* LIs;
public:
	Gerenciador_Colis�es();
	bool Colidindo(Entidade* eu, Entidade* alvo);
};

