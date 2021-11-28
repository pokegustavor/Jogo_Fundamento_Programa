#include "Fase_2.h"

Fase_2::Fase_2(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador, int* pontuacao)
{
	this->j1 = j1;
	this->j2 = j2;
	this->gerenciador = gerenciador;
	this->pontuacao = pontuacao;
	*this->pontuacao = 500;
	numInimigosToWin = 3;
	gerenciador_Colid = new Gerenciador_Colisões;
	listaEntidades = new ListaEntidades;
	listaEntidades->LEs.Add(j1);
	j1->x = 30.f;
	j1->y = 680.f;
	if (j2 != nullptr)
	{
		listaEntidades->LEs.Add(j2);
		j2->x = 70.f;
		j2->y = 680.f;
	}
	//criar espinhos
	int num_Inim = (rand() % 4) + 20;
	Obstaculo* spike;
	for(int i = 0; i < num_Inim; i++)
	{
		spike = new Obstaculo_B(sf::Vector2f(20.f, 20.f), (float)(rand()%1000) + 175.f, 610.f - ((rand() % 6) * 80.f));
		spike->setGerenciador(gerenciador);
		listaEntidades->LEs.Add(spike);
	}
	//Criar obtsáculos
	Obstaculo* o1;
	for (int i = 0; i < 6; i++)
	{
		o1 = new Obstaculo_A(sf::Vector2f(1300.f, 20.f), 150.f, 620.f - (i*80));
		o1->setGerenciador(gerenciador);
		listaEntidades->LEs.Add(o1);
		o1 = new Obstaculo_A(sf::Vector2f(100.f, 20.f), 0.f, 640.f - (i * 80));
		o1->setGerenciador(gerenciador);
		listaEntidades->LEs.Add(o1);
		o1 = new Obstaculo_A(sf::Vector2f(100.f, 20.f), 1550.f, 640.f - (i * 80));
		o1->setGerenciador(gerenciador);
		listaEntidades->LEs.Add(o1);
	}
	//o1 = new Obstaculo_A(sf::Vector2f(1250.f, 20.f), 150.f, 540.f);
	//o1->setGerenciador(gerenciador);
	//listaEntidades->LEs.Add(o1);
	//Criar chão
	chao = new Obstaculo(sf::Vector2f(2000.0f, 200.0f), 0, 700.f);
	chao->getSprite()->setFillColor(sf::Color::Green);
	chao->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(chao);
	//Criar chefão
	num_Inim = (rand() % 4) + 3;
	for (int i = 0; i < num_Inim; i++)
	{
		Inimigo* i1 = new Inimigo_C(j1, j2, 800.f, 680.f);
		i1->setGerenciador(gerenciador);
		i1->setListEnt(listaEntidades);
		listaEntidades->LEs.Add(i1);
	}
	//Criar inimigos
	num_Inim = (rand() % 3) + 3;
	sf::Vector2f posicoes[5];
	for (int i = 0; i < 5; i++)
	{
		posicoes[i] = sf::Vector2f(0.f, 0.f);
	}
	for (int i = 0; i < num_Inim; i++)
	{
		bool nascido = true;
		do
		{
			int randpos = rand() % 7;
			sf::Vector2f posivelPos;
			switch (randpos)
			{
			case 0:
				posivelPos = sf::Vector2f(1580.f, 620.f);
				break;
			case 1:
				posivelPos = sf::Vector2f(1580.f, 540.f);
				break;
			case 2:
				posivelPos = sf::Vector2f(1580.f, 460.f);
				break;
			case 3:
				posivelPos = sf::Vector2f(1580.f, 380.f);
				break;
			case 4:
				posivelPos = sf::Vector2f(1580.f, 300.f);
				break;
			case 5:
				posivelPos = sf::Vector2f(1580.f, 220.f);
				break;
			case 6:
				posivelPos = sf::Vector2f(1580.f, 680.f);
				break;
			}
			for (int j = 0; j < 5; j++)
			{
				if (posicoes[j] == posivelPos)
				{
					nascido = false;
					break;
				}
			}
			if (nascido)
			{
				sf::Vector2f nulo = sf::Vector2f(0.f, 0.f);
				for (int j = 0; j < 5; j++)
				{
					if (posicoes[j] != nulo)
					{
						posicoes[j] = posivelPos;
						break;
					}
				}
				Inimigo_B* i2 = new Inimigo_B(j1, j2, posivelPos.x, posivelPos.y);
				i2->setGerenciador(gerenciador);
				i2->setListEnt(listaEntidades);
				listaEntidades->LEs.Add(i2);
			}
		} while (!nascido);
	}
	anti_visao = new Obstaculo_C(sf::Vector2f(gerenciador->window->getSize().x/5.f,(float)gerenciador->window->getSize().y), gerenciador->window->getSize().x - gerenciador->window->getSize().x / 5.f, 0);
	anti_visao->setGerenciador(gerenciador);
}

Fase_2::~Fase_2()
{
}

void Fase_2::Executar()
{
	Fase::Executar();
}
