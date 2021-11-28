#include "Gerenciador_Colisões.h"

Gerenciador_Colisões::Gerenciador_Colisões()
{
	LIs = new Lista<Inimigo>;
}

bool Gerenciador_Colisões::Colidindo(sf::RectangleShape eu, sf::RectangleShape alvo)
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

void Gerenciador_Colisões::Colidir(Entidade* temp, Entidade* alvo)
{
	bool colidido = false;
	sf::RectangleShape colisionObj;
	colisionObj = sf::RectangleShape(alvo->getSprite()->getSize());
	//Colisão por baixo
	colisionObj.setPosition(alvo->x, alvo->y + alvo->getSprite()->getSize().y);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeVertical < 0)temp->velocidadeVertical = 0;
		temp->getSprite()->setPosition(alvo->x, alvo->y + alvo->getSprite()->getSize().y);
		colidido = true;
	}
	//Colisão pela esquerda
	colisionObj.setPosition(alvo->x - alvo->getSprite()->getSize().x, alvo->y + 1);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeHorizontal > 0)temp->velocidadeHorizontal = 0;
		temp->getSprite()->setPosition(alvo->x - temp->getSprite()->getSize().x, temp->y);
		colidido = true;
	}
	//Colisão pela direita
	colisionObj.setPosition(alvo->x + alvo->getSprite()->getSize().x, alvo->y + 1);
	if (Colidindo(*temp->getSprite(), colisionObj))
	{
		if (temp->velocidadeHorizontal < 0)temp->velocidadeHorizontal = 0;
		temp->getSprite()->setPosition(alvo->x + alvo->getSprite()->getSize().x, temp->y);
		colidido = true;
	}
	//Colisão por cima
	colisionObj.setPosition(alvo->x, alvo->y - alvo->getSprite()->getSize().y);
	if (Colidindo(*temp->getSprite(), colisionObj) && !colidido)
	{
		if (temp->velocidadeVertical > 0)temp->velocidadeVertical = 0;
		temp->getSprite()->setPosition(alvo->x, alvo->y + temp->getSprite()->getSize().y);
		temp->noChao = true;
		colidido = true;
	}
}



