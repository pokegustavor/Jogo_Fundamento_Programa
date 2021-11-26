#pragma once
#include "Entidade.h"
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:
    bool Jogador1;
public:
    bool finalizado;
    float cargaPoder;
    bool poderAtivo;
    Entidade* alvo;
    Jogador(bool jogador1, float x, float y);
    ~Jogador();
    void Move();
    void Executar();
};

