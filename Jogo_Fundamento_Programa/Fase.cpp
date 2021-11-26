#include "Fase.h"



Fase::Fase():laranja(235, 130, 17)
{
	listaEntidades = nullptr;
	j1 = nullptr;
	j2 = nullptr;
	gerenciador_Colid = nullptr;
	chao = nullptr;
	end = nullptr;
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
	for (int i = 0; i < listaEntidades->LEs.Length(); i++) //Executa todos os objetos
	{
		Entidade* temp = listaEntidades->LEs.getItem(i);
		if (temp == nullptr)break;
		if (gerenciador_Colid->Colidindo(*temp->getSprite(), *chao->getSprite())) //Verificar se está no chão
		{
			temp->velocidadeVertical = 0;
			temp->noChao = true;
		}
		else
		{
			temp->noChao = false;
		}
		if (temp->getSprite()->getFillColor() == sf::Color::Green || temp->getSprite()->getFillColor() == laranja)
		{
			//Plataforma verdes não caem, nem o final da fase
			temp->velocidadeVertical = 0;
			temp->noChao = true;
		}
		for (int j = 0; j < listaEntidades->LEs.Length(); j++) //Verifica colisões
		{
			Entidade* alvo = listaEntidades->LEs.getItem(j);
			if (alvo == temp || temp->getSprite()->getFillColor() == sf::Color::Green || temp->getSprite()->getFillColor() == laranja)continue;
			if (gerenciador_Colid->Colidindo(*temp->getSprite(), *alvo->getSprite()))
			{
				if (temp->y + temp->getSprite()->getSize().y > alvo->y && (alvo->noChao || alvo->capturado))
				{
					temp->noChao = true;
					if (temp->y < alvo->y - alvo->getSprite()->getSize().y / 2)
					{
						temp->y = alvo->y - temp->getSprite()->getSize().y;
					}
				}
				if (alvo->getSprite()->getFillColor() == sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Green && temp->getSprite()->getFillColor() != laranja)
				{
					temp->morto = true;
				}
				if (alvo->getSprite()->getFillColor() == sf::Color::Green)
				{
					temp->velocidadeVertical = 0;
					temp->noChao = true;
				}
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && j1->alvo == nullptr && (sf::Mouse::getPosition(*gerenciador->window).x > temp->x && sf::Mouse::getPosition(*gerenciador->window).x < temp->x + temp->getSprite()->getSize().x) &&
			(sf::Mouse::getPosition(*gerenciador->window).y > temp->y && sf::Mouse::getPosition(*gerenciador->window).y < temp->y + temp->getSprite()->getSize().y) && temp != chao && temp != j1 && temp != j2 && temp->getSprite()->getFillColor() != sf::Color::Green && temp->getSprite()->getRotation() != 45.f &&
			temp->getSprite()->getFillColor() != laranja)
		{
			//Sistema captura
			j1->alvo = temp;
			temp->capturado = true;
			temp->velocidadeHorizontal = 0;
			temp->velocidadeVertical = 0;
		}
		else if (j1->alvo != nullptr && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//soltar alvo
			j1->alvo->capturado = false;
			j1->alvo = nullptr;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !j1->morto)
		{
			sf::RectangleShape tempo = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
			tempo.setFillColor(sf::Color::Transparent);
			tempo.setOutlineColor(sf::Color::White);
			tempo.setOutlineThickness(7.f);
			tempo.setPosition(sf::Vector2f(j1->x - 50.f + j1->getSprite()->getSize().x / 2, j1->y - 50.f + j1->getSprite()->getSize().y / 2));
			gerenciador->window->draw(tempo);
			if(gerenciador_Colid->Colidindo(*temp->getSprite(), tempo) && temp != j1)
			{
				temp->paralizado = true;
				temp->velocidadeHorizontal = 0;
				temp->velocidadeVertical = 0;
			}
			else if(temp != j1->alvo)
			{
				temp->paralizado = false;
			}
		}
		else if(temp != j1->alvo)
		{
			temp->paralizado = false;
		}
		temp->Executar();
		temp->noChao = false;
		if (temp->morto)
		{
			//Morte
			listaEntidades->LEs.Remove(temp);
		}
		if(gerenciador_Colid->Colidindo(*j1->getSprite(),*end->getSprite())|| (j2 != nullptr && gerenciador_Colid->Colidindo(*j2->getSprite(), *end->getSprite())))
		{
			j1->finalizado = true;
		}
	}
	gerenciador->window->display();
}
