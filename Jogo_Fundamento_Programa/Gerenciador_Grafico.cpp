#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico()
{
	window = new sf::RenderWindow(sf::VideoMode(1600, 800), "Reality Base", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(30);
}
