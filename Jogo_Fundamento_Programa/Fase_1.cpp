#include "Fase_1.h"

Fase_1::Fase_1(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador)
{
	this->j1 = j1;
	this->j2 = j2;
	this->gerenciador = gerenciador;
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
	//Criar obtsáculos
	Obstaculo_B* s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f),1000.f,582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 980.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 960.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 940.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 920.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 900.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 880.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 860.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	s1 = new Obstaculo_B(sf::Vector2f(20.f, 20.f), 840.f, 582.f);
	s1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(s1);
	Obstaculo_A* o1 = new Obstaculo_A(sf::Vector2f(200.f, 20.f), 1600.f, 650.f);
	o1->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o1);
	Obstaculo_A* o2 = new Obstaculo_A(sf::Vector2f(800.f, 20.f), 550.f, 590.f);
	o2->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o2);
	Obstaculo_A* o3 = new Obstaculo_A(sf::Vector2f(300.f, 20.f), 200.f, 540.f);
	o3->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o3);
	Obstaculo_A* o4 = new Obstaculo_A(sf::Vector2f(100.f, 20.f), 0.f, 510.f);
	o4->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o4);
	Obstaculo_A* o5 = new Obstaculo_A(sf::Vector2f(300.f, 20.f), 200.f, 440.f);
	o5->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o5);
	Obstaculo_A* o6 = new Obstaculo_A(sf::Vector2f(400.f, 20.f), 550.f, 380.f);
	o6->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o6);
	Obstaculo_A* o7 = new Obstaculo_A(sf::Vector2f(350.f, 20.f), 550.f, 310.f);
	o7->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o7);
	Obstaculo_A* o8 = new Obstaculo_A(sf::Vector2f(170.f, 20.f), 300.f, 240.f);
	o8->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o8);
	Obstaculo_A* o9 = new Obstaculo_A(sf::Vector2f(50.f, 20.f), 0.f, 190.f);
	o9->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(o9);
	//Criar chão
	chao = new Obstaculo(sf::Vector2f(2000.0f, 200.0f), 0, 700.f);
	chao->getSprite()->setFillColor(sf::Color::Green);
	chao->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(chao);
	//criar final da fase
	end = new Obstaculo(sf::Vector2f(20.0f, 20.0f), 0.f, 170.f);
	end->getSprite()->setFillColor(laranja);
	end->setGerenciador(gerenciador);
	listaEntidades->LEs.Add(end);
	//Criar inimigos
	int num_Inim = (rand() % 7) + 3;
	for (int i = 0; i < num_Inim; i++)
	{
		Inimigo_A* i1 = new Inimigo_A(j1, j2,(rand() % 500) + 400, (rand() % 400) + 100);
		i1->setGerenciador(gerenciador);
		listaEntidades->LEs.Add(i1);
	}

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
