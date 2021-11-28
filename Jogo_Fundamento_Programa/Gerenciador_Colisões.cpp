#include "Gerenciador_Colis�es.h"

Gerenciador_Colis�es::Gerenciador_Colis�es()
{
	LIs = new Lista<Inimigo>;
}

bool Gerenciador_Colis�es::Colidindo(sf::RectangleShape eu, sf::RectangleShape alvo)
{
	if(eu.getPosition().x + eu.getSize().x <= alvo.getPosition().x)
	{
		return false;
	}
	if (eu.getPosition().x >= alvo.getPosition().x + alvo.getSize().x)
	{
		return false;
	}
	if (eu.getPosition().y + eu.getSize().y <= alvo.getPosition().y)
	{
		return false;
	}
	if (eu.getPosition().y >= alvo.getPosition().y + alvo.getSize().y)
	{
		return false;
	}
	return true;
}

void Gerenciador_Colis�es::Colidir(Entidade* temp, Entidade* alvo)
{
	bool colidido = false;
	sf::RectangleShape colisionObj;
	colisionObj = sf::RectangleShape(alvo->getSprite()->getSize());
	//Colis�o por baixo
	colisionObj.setPosition(alvo->x, alvo->y + alvo->getSprite()->getSize().y);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeVertical < 0)temp->velocidadeVertical = 0;
		temp->getSprite()->setPosition(alvo->x, alvo->y + alvo->getSprite()->getSize().y);
		colidido = true;
	}
	//Colis�o pela esquerda
	colisionObj.setPosition(alvo->x - alvo->getSprite()->getSize().x, alvo->y + 1);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeHorizontal > 0)temp->velocidadeHorizontal = 0;
		temp->getSprite()->setPosition(alvo->x - temp->getSprite()->getSize().x, temp->y);
		colidido = true;
	}
	//Colis�o pela direita
	colisionObj.setPosition(alvo->x + alvo->getSprite()->getSize().x, alvo->y + 1);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeHorizontal < 0)temp->velocidadeHorizontal = 0;
		temp->getSprite()->setPosition(alvo->x + alvo->getSprite()->getSize().x, temp->y);
		colidido = true;
	}
	//Colis�o por cima
	colisionObj.setPosition(alvo->x, alvo->y - alvo->getSprite()->getSize().y);
	if (Colidindo(*temp->getSprite(), colisionObj) && !colidido)
	{
		if (temp->velocidadeVertical > 0)temp->velocidadeVertical = 0;
		temp->getSprite()->setPosition(alvo->x, alvo->y + temp->getSprite()->getSize().y);
		temp->noChao = true;
		colidido = true;
	}
}



