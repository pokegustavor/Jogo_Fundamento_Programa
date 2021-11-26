#include "Fase_1.h"

Fase_1::Fase_1(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador)
{
	this->j1 = j1;
	this->j2 = j2;
	chao = new Obstaculo(sf::Vector2f(2000.0f, 200.0f));
	chao->x = 0;
	chao->y = 700.0f;
	chao->getSprite()->setPosition(0.0f, 700.0f);
	chao->getSprite()->setFillColor(sf::Color::Green);
	Inimigo_A* i1 = new Inimigo_A(j1, j2);
	i1->setGerenciador(gerenciador);
	listaEntidades = new ListaEntidades;
	listaEntidades->LEs.Add(j1);
	listaEntidades->LEs.Add(chao);
	chao->setGerenciador(gerenciador);
	this->gerenciador = gerenciador;
	gerenciador_Colid = new Gerenciador_Colisões;
	Inimigo_B* i2 = new Inimigo_B(j1, j2);
	i2->setGerenciador(gerenciador);
	i2->setListEnt(listaEntidades);
	i2->x = 700.0f;
	i2->y = 500.0f;
	listaEntidades->LEs.Add(i2);
	Obstaculo_A* o1 = new Obstaculo_A(sf::Vector2f(200.f, 50.f));
	o1->setGerenciador(gerenciador);
	o1->getSprite()->setPosition(sf::Vector2f(1000.f, 600.f));
	listaEntidades->LEs.Add(o1);
	if (j2 != nullptr)
	{
		listaEntidades->LEs.Add(j2);
	}
	listaEntidades->LEs.Add(i1);
}

Fase_1::~Fase_1()
{
}

void Fase_1::Executar()
{
	gerenciador->window->clear();
	for (int i = 0; i < listaEntidades->LEs.Length(); i++) //Executa todos os objetos
	{
		Entidade* temp = listaEntidades->LEs.getItem(i);
		if (temp == nullptr)break;
		if (gerenciador_Colid->Colidindo(temp, chao))
		{
			temp->velocidadeVertical = 0;
			temp->noChao = true;
		}
		else
		{
			temp->noChao = false;
		}
		if(temp->getSprite()->getFillColor() == sf::Color::Green)
		{
			temp->velocidadeVertical = 0;
			temp->noChao = true;
		}
		for (int j = 0; j < listaEntidades->LEs.Length(); j++) //Verifica colisões Y
		{
			Entidade* alvo = listaEntidades->LEs.getItem(j);
			if (alvo == temp || temp == chao)continue;
			if (gerenciador_Colid->Colidindo(temp, alvo))
			{
				if (temp->y + temp->getSprite()->getSize().y > alvo->y && (alvo->noChao || alvo->capturado))
				{
					temp->noChao = true;
					if (temp->y < alvo->y - alvo->getSprite()->getSize().y / 2)
					{
						temp->y = alvo->y - temp->getSprite()->getSize().y;
					}
				}
				if (alvo->getSprite()->getFillColor() == sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Red && temp->getSprite()->getFillColor() != sf::Color::Green)
				{
					temp->morto = true;
				}
				if(alvo->getSprite()->getFillColor() == sf::Color::Green)
				{
					temp->velocidadeVertical = 0;
					temp->noChao = true;
				}
			}
		}
		/*
		temp->noChao = false;
		if (temp == chao)
		{
			temp->noChao = true;
		}
		if(gerenciador_Colid->Colidindo(temp,chao))
		{
			temp->noChao = true;
		}
		*/
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && j1->alvo == nullptr && (sf::Mouse::getPosition(*gerenciador->window).x > temp->x && sf::Mouse::getPosition(*gerenciador->window).x < temp->x + temp->getSprite()->getSize().x) &&
			(sf::Mouse::getPosition(*gerenciador->window).y > temp->y && sf::Mouse::getPosition(*gerenciador->window).y < temp->y + temp->getSprite()->getSize().y) && temp != chao && temp != j1 && temp != j2 && temp->getSprite()->getFillColor() != sf::Color::Green)
		{
			j1->alvo = temp;
			temp->capturado = true;
			temp->velocidadeHorizontal = 0;
			temp->velocidadeVertical = 0;
		}
		else if (j1->alvo != nullptr && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			j1->alvo->capturado = false;
			j1->alvo = nullptr;
		}
		temp->Executar();
		temp->noChao = false;
		if (temp->morto)
		{
			listaEntidades->LEs.Remove(temp);
		}
	}
	gerenciador->window->display();
}
