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



