#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Inimigo_A.h"
#include "Obstaculo.h"
#include "Gerenciador_Colisões.h"
#include "Ente.h"
#include "Projétil.h"
#include "Inimigo_B.h"
#include "Obstaculo_A.h"
#include "Obstaculo_B.h"
#include "Inimigo_C.h"
#include "Obstaculo_C.h"
class Fase :
	public Ente
{
protected:
	ListaEntidades *listaEntidades;
	Jogador* j1;
	Jogador* j2;
	Gerenciador_Colisões* gerenciador_Colid;
	Obstaculo* chao;
	Obstaculo* end;
	Obstaculo_C* anti_visao;
	int numInimigosToWin;
	sf::Color laranja;
	int* pontuacao;
	float internalPont;
public:
	
	Fase();
	~Fase();
	void Imprimir_se();
	void Executar();
	ListaEntidades* getListaEntidades() { return listaEntidades; }
};

