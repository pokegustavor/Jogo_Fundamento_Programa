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



