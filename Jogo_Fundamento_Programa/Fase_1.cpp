#include "Fase_1.h"

Fase_1::Fase_1(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador)
{
	this->j1 = j1;
	this->j2 = j2;
	this->gerenciador = gerenciador;
	gerenciador_Colid = new Gerenciador_Colisões;
	listaEntidades = new ListaEntidades;
	listaEntidades->LEs.Add(j1);
	if (j2 != nullptr)
	{
		listaEntidades->LEs.Add(j2);
	}
	//Criar obtsáculos
	Obstaculo_B* o2 = new Obstaculo_B(sf::Vector2f(20.f, 20.f),1000.f,550.f);
	o2->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o2);
	Obstaculo_A* o1 = new Obstaculo_A(sf::Vector2f(200.f, 50.f), 1000.f, 600.f);
	o1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o1);
	//Criar chão
	chao = new Obstaculo(sf::Vector2f(2000.0f, 200.0f), 0, 700.f);
	chao->x = 0;
	chao->y = 700.0f;
	chao->getSprite()->setPosition(0.0f, 700.0f);
	chao->getSprite()->setFillColor(sf::Color::Green);
	chao->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(chao);
	//Criar inimigos
	Inimigo_A* i1 = new Inimigo_A(j1, j2,500.f,500.f);
	i1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(i1);

	Inimigo_B* i2 = new Inimigo_B(j1, j2,700.f,500.f);
	i2->setGerenciador(gerenciador);
	i2->setListEnt(listaEntidades);
	listaEntidades->LEs.Add(i2);
	
}

Fase_1::~Fase_1()
{
}

void Fase_1::Executar()
{
	Fase::Executar();
}
