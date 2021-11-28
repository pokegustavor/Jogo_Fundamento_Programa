#include "Menu.h"

Menu::Menu(Gerenciador_Grafico* gerenciador, int* level, bool* twoPlayers)
{
	this->level = level;
	this->gerenciador = gerenciador;
	atual = 0;
	holdingMouse = false;
	this->twoPlayers = twoPlayers;
	for(int i = 0; i < 5; i++)
	{
		valorRank[i] = -1;
	}
}

Menu::~Menu()
{
}

void Menu::Executar()
{
	if (!holdingMouse)
	{
		switch (atual)
		{
		case 0:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y > 200.0f && sf::Mouse::getPosition(*gerenciador->window).y < 275.0f)
			{
				//Ver níveis
				holdingMouse = true;
				atual = 1;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y > 300.0f && sf::Mouse::getPosition(*gerenciador->window).y < 375.0f)
			{
				//Ver Rank
				holdingMouse = true;
				atual = 2;
				for (int i = 0; i < 5; i++)
				{
					valorRank[i] = -1;
				}
				ifstream records = ifstream("records.txt");
				int count = 0;
				string line;
				while (!records.eof() && count < 5)
				{
					if (getline(records, line))
					{
						nomeRank[count] = line.substr(0, line.find(','));
						valorRank[count] = stoi(line.substr(line.find(',') + 1, line.size()));
						count++;
					}
				}
				records.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y > 400.0f && sf::Mouse::getPosition(*gerenciador->window).y < 475.0f)
			{
				//Sair do jogo
				holdingMouse = true;
				gerenciador->window->close();
			}
			break;
		case 1:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 625.0f && sf::Mouse::getPosition(*gerenciador->window).y > 75.0f && sf::Mouse::getPosition(*gerenciador->window).y < 175.0f)
			{
				//Dois Jogadores
				holdingMouse = true;
				*twoPlayers = !*twoPlayers;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y >200.0f && sf::Mouse::getPosition(*gerenciador->window).y < 275.0f)
			{
				//Jogar fase 1
				holdingMouse = true;
				*level = 0;
				atual = 0;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y >300.0f && sf::Mouse::getPosition(*gerenciador->window).y < 375.0f)
			{
				//Jogar fase 2
				holdingMouse = true;
				*level = 1;
				atual = 0;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y > 400.0f && sf::Mouse::getPosition(*gerenciador->window).y < 475.0f)
			{
				//Voltar ao Menu
				holdingMouse = true;
				atual = 0;
			}
			break;
		case 2:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*gerenciador->window).x > 525.0f && sf::Mouse::getPosition(*gerenciador->window).x < 1025.0f && sf::Mouse::getPosition(*gerenciador->window).y > 600.0f && sf::Mouse::getPosition(*gerenciador->window).y < 675.0f)
			{
				//Voltar ao Menu
				holdingMouse = true;
				atual = 0;
			}
			break;
		}
	}
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		holdingMouse = false;
	}
	Imprimir_se();
}

void Menu::Imprimir_se()
{
	gerenciador->window->clear();
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1600.0f, 800.0f));
	background.setFillColor(sf::Color::Green);
	gerenciador->window->draw(background);
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text title = sf::Text("Reality Base", font, 100);
	sf::RectangleShape baseButton = sf::RectangleShape(sf::Vector2f(500.0f, 75.0f));
	sf::Text text = sf::Text("Play", font, 50);
	sf::RectangleShape button = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	button.setFillColor(sf::Color::White);
	sf::RectangleShape button2 = sf::RectangleShape(sf::Vector2f(75.0f, 75.0f));
	button2.setFillColor(sf::Color::Black);
	switch (atual)
	{
	case 0:
		title.setOutlineColor(sf::Color::Red);
		title.setFillColor(sf::Color::Red);
		title.setPosition(sf::Vector2f(500.0f, 50.0f));
		gerenciador->window->draw(title);
		
		baseButton.setPosition(sf::Vector2f(525.0f, 200.0f));
		text.setFillColor(sf::Color::Black);
		text.setPosition(sf::Vector2f(730.0f, 200.0f));
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);

		baseButton.setPosition(sf::Vector2f(525.0f, 300.0f));
		text.setPosition(sf::Vector2f(690.0f, 300.0f));
		text.setString("Ranking");
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);

		baseButton.setPosition(sf::Vector2f(525.0f, 400.0f));
		text.setPosition(sf::Vector2f(730.0f, 400.0f));
		text.setString("Exit");
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);
		break;
	case 1:

		baseButton.setPosition(sf::Vector2f(525.0f, 200.0f));
		text.setFillColor(sf::Color::Black);
		text.setPosition(sf::Vector2f(690.0f, 200.0f));
		text.setString("Level 1");

		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);

		baseButton.setPosition(sf::Vector2f(525.0f, 300.0f));
		text.setPosition(sf::Vector2f(690.0f, 300.0f));
		text.setString("Level 2");
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);

		baseButton.setPosition(sf::Vector2f(525.0f, 400.0f));
		text.setPosition(sf::Vector2f(715.0f, 400.0f));
		text.setString("Back");
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);

		button.setPosition(sf::Vector2f(525.0f, 75.0f));
		button2.setPosition(sf::Vector2f(537.0f, 87.0f));
		gerenciador->window->draw(button);
		if(*twoPlayers)
		{
			gerenciador->window->draw(button2);
		}
		text.setPosition(sf::Vector2f(650.0f, 95.0f));
		text.setString("Two Players");
		gerenciador->window->draw(text);
		break;
	case 2:
		title.setString("Ranking");
		title.setOutlineColor(sf::Color::Red);
		title.setFillColor(sf::Color::Red);
		title.setPosition(sf::Vector2f(575.0f, 50.0f));
		gerenciador->window->draw(title);
		for(int i = 0; i < 5; i++)
		{
			if(valorRank[i] == -1)
			{
				break;
			}
			text.setPosition(sf::Vector2f(575.0f, 165.0f + (i * 75.f)));
			text.setFillColor(sf::Color::Blue);
			text.setString("#" + to_string(i+1) + " " + nomeRank[i] + ": " + to_string(valorRank[i]));
			gerenciador->window->draw(text);
		}
		baseButton.setPosition(sf::Vector2f(525.0f, 600.0f));
		text.setPosition(sf::Vector2f(720.0f, 600.0f));
		text.setFillColor(sf::Color::Black);
		text.setString("Back");
		gerenciador->window->draw(baseButton);
		gerenciador->window->draw(text);
		break;
	}
	gerenciador->window->display();
}
