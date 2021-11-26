#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Inimigo_A.h"
#include "Obstaculo.h"
#include "Gerenciador_Colis�es.h"
#include "Ente.h"
#include "Proj�til.h"
#include "Inimigo_B.h"
#include "Obstaculo_A.h"
#include "Obstaculo_B.h"
class Fase :
	public Ente
{
protected:
	ListaEntidades *listaEntidades;
	Jogador* j1;
	Jogador* j2;
	Gerenciador_Colis�es* gerenciador_Colid;
	Obstaculo* chao;
	Obstaculo* end;
	sf::Color laranja;
public:
	
	Fase();
	~Fase();
	void Imprimir_se();
	void Executar();
	ListaEntidades* getListaEntidades() { return listaEntidades; }
};

