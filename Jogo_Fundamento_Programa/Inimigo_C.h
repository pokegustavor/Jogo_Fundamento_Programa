#pragma once
#include "Inimigo.h"
#include "Inimigo_A.h"
class Inimigo_C :
    public Inimigo
{
private:
    time_t ultimoSpawn;
    time_t ultimoTP;
public:
    Inimigo_C(Jogador* jogador1, Jogador* jogador2, float x, float y);
    ~Inimigo_C();
    void Executar();
};

