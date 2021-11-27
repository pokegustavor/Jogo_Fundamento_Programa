#pragma once
#include "Fase.h"
class Fase_1 :
    public Fase
{
private:
public:
    Fase_1(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador, int* pontuacao);
    ~Fase_1();
    void Executar();
};

