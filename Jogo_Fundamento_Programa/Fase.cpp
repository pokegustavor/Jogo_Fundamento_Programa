#include "Fase.h"



Fase::Fase() :laranja(235, 130, 17)
{
	listaEntidades = nullptr;
	j1 = nullptr;
	j2 = nullptr;
	gerenciador_Colid = nullptr;
	chao = nullptr;
	end = nullptr;
	pontuacao = nullptr;
	internalPont = 0.f;
	numInimigosToWin = -1;
	anti_visao = nullptr;
}

Fase::~Fase()
{
}

void Fase::Imprimir_se()
{
}

void Fase::Executar()
{
	gerenciador->window->clear();
	sf::RectangleShape poderBarra = sf::RectangleShape(sf::Vector2f(200.f, 25.f));
	poderBarra.setPosition(0.f, 50.f);
	gerenciador->window->draw(poderBarra);
	sf::RectangleShape poderCarga = sf::RectangleShape(sf::Vector2f(200.f, 25.f));
	poderCarga.setPosition(0.f, 50.f);
	poderCarga.setFillColor(sf::Color::Blue);

	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text powerDesc = sf::Text("Time Power Charge", font, 20);
	powerDesc.setFillColor(sf::Color::White);
	powerDesc.setPosition(0.f, 25.f);
	gerenciador->window->draw(powerDesc);
	int targetsAlive = numInimigosToWin;
	for (int i = 0; i < listaEntidades->LEs.Length(); i++) //Executa todos os objetos
	{
		Entidade* temp = listaEntidades->LEs.getItem(i);
		if (temp == nullptr)break;
		if(temp->getSprite()->getFillColor() == sf::Color::Cyan)
		{
			targetsAlive--;
		}
		if (chao != nullptr && (gerenciador_Colid->Colidindo(*temp->getSprite(), *chao->getSprite()))) //Verificar se está no chão
		{
			if (temp->velocidadeVertical > 0)
			{
				temp->velocidadeVertical = 0;
			}
			temp->noChao = true;
		}
		else
		{
			temp->noChao = false;
		}
		if (temp->getSprite()->getFillColor() == sf::Color::Green || temp->getSprite()->getFillColor() == laranja || temp->getSprite()->getRotation() == 45)
		{
			//Plataforma verdes não caem, nem o final da fase
			temp->velocidadeVertical = 0;
			temp->noChao = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !j1->morto && ((j1->poderAtivo && j1->cargaPoder > 0.f) || j1->cargaPoder > 20.f))
		{
			//Parar o tempo
			sf::RectangleShape tempo = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
			tempo.setFillColor(sf::Color::Transparent);
			tempo.setOutlineColor(sf::Color::White);
			tempo.setOutlineThickness(7.f);
			tempo.setPosition(sf::Vector2f(j1->x - 50.f + j1->getSprite()->getSize().x / 2, j1->y - 50.f + j1->getSprite()->getSize().y / 2));
			gerenciador->window->draw(tempo);
			if (gerenciador_Colid->Colidindo(*temp->getSprite(), tempo) && temp != j1)
			{
				temp->paralizado = true;
				temp->velocidadeHorizontal = 0;
				temp->velocidadeVertical = 0;
			}
			else if (temp != j1->alvo)
			{
				temp->paralizado = false;
			}

		}
		else if (temp != j1->alvo)
		{
			temp->paralizado = false;

		}
		for (int j = 0; j < listaEntidades->LEs.Length(); j++) //Verifica colisões
		{
			Entidade* alvo = listaEntidades->LEs.getItem(j);
			if (alvo == temp || temp->getSprite()->getFillColor() == sf::Color::Green || temp->getSprite()->getFillColor() == laranja || temp->getSprite()->getRotation() == 45 || (temp->getSprite()->getFillColor() == sf::Color::Red && alvo->getSprite()->getFillColor() == sf::Color::Red))continue;
			if (gerenciador_Colid->Colidindo(*temp->getSprite(), *alvo->getSprite()))
			{
				if ((alvo->getSprite()->getFillColor() == sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Green && temp->getSprite()->getFillColor() != laranja))
				{
					if (temp->getSprite()->getFillColor() != sf::Color::Cyan)
					{
						temp->morto = true;
					}
					else if((alvo->velocidadeHorizontal == -7.f || alvo->velocidadeHorizontal == 7.f))
					{
						temp->morto = true;
						alvo->morto = true;
					}
				}
				if(temp->getSprite()->getFillColor() == sf::Color::Red && alvo->getSprite()->getFillColor() != sf::Color::Red && alvo->getSprite()->getFillColor() != sf::Color::Green && alvo->getSprite()->getFillColor() != laranja)
				{
					if (alvo->getSprite()->getFillColor() != sf::Color::Cyan)
					{
						alvo->morto = true;
					}
					else if((temp->velocidadeHorizontal == -7.f || temp->velocidadeHorizontal == 7.f))
					{
						temp->morto = true;
						alvo->morto = true;
					}
				}
				gerenciador_Colid->Colidir(temp, alvo);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && j1->alvo == nullptr && (sf::Mouse::getPosition(*gerenciador->window).x > temp->x && sf::Mouse::getPosition(*gerenciador->window).x < temp->x + temp->getSprite()->getSize().x) &&
			(sf::Mouse::getPosition(*gerenciador->window).y > temp->y && sf::Mouse::getPosition(*gerenciador->window).y < temp->y + temp->getSprite()->getSize().y) && temp != chao && temp != j1 && temp != j2 && temp->getSprite()->getFillColor() != sf::Color::Green && temp->getSprite()->getRotation() != 45.f &&
			temp->getSprite()->getFillColor() != laranja)
		{
			//Sistema captura
			j1->alvo = temp;
			temp->capturado = true;
		}
		else if (j1->alvo != nullptr && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//soltar alvo
			j1->alvo->capturado = false;
			j1->alvo = nullptr;
		}
		//carga e descarga do poder
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ((j1->poderAtivo && j1->cargaPoder > 0.f) || j1->cargaPoder > 20.f))
		{
			j1->poderAtivo = true;
			j1->cargaPoder -= 0.02f;
			if (j1->cargaPoder < 0)j1->cargaPoder = 0.f;
		}
		else
		{
			j1->poderAtivo = false;
			j1->cargaPoder += 0.007f;
			if (j1->cargaPoder > 100)j1->cargaPoder = 100.f;
		}
		poderCarga.setPosition(-100.f - (100 - j1->cargaPoder * 2), 50.f);
		gerenciador->window->draw(poderCarga);
		if (temp->morto)
		{
			//Morte
			listaEntidades->LEs.Remove(temp);
			if(temp != j1 && temp != j2)
			{
				temp->~Entidade();
			}
			continue;
		}
		temp->Executar();
		if (end != nullptr && (gerenciador_Colid->Colidindo(*j1->getSprite(), *end->getSprite()) || (j2 != nullptr && gerenciador_Colid->Colidindo(*j2->getSprite(), *end->getSprite()))))
		{
			j1->finalizado = true;
		}
	}
	if(numInimigosToWin > 0 && numInimigosToWin - targetsAlive <= 0)
	{
		j1->finalizado = true;
	}
	internalPont += 0.05f;
	if (internalPont > 1.f)
	{
		(*pontuacao)--;
		internalPont = 0.f;
	}
	if (*pontuacao < 0)*pontuacao = 0;
	sf::Text pontua = sf::Text(std::to_string(*pontuacao), font, 20);
	pontua.setFillColor(sf::Color::White);
	pontua.setPosition(0.f, 80.f);
	gerenciador->window->draw(pontua);
	if(anti_visao != nullptr)
	{
		anti_visao->Executar();
	}
	gerenciador->window->display();

}
