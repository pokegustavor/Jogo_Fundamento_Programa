#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Jogador.h"
#include "ListaEntidades.h"
class Inimigo :
    public Personagem
{
protected:
    Jogador* alvo;
    Jogador* jogador1;
    Jogador* jogador2;
    ListaEntidades* entidades;
public:
    Inimigo(float x, float y);
    ~Inimigo();
    void Executar();
    void setListEnt(ListaEntidades* lista);
};

