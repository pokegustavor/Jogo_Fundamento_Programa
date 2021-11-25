#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colis�es.h"
#include <SFML/Audio.hpp>
class Jogo
{
private:
	Jogador* jogador1;
	Jogador* jogador2;
	Gerenciador_Grafico* gerenciador_graf;
	Gerenciador_Colis�es* gerenciador_colid;
	Fase* fase1;
public:
	Jogo();
	~Jogo();

	void Executar();
};

