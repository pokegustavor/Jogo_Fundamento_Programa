#pragma once
#include "Fase.h"
class Fase_2 :
    public Fase
{
private:
public:
    Fase_2(Jogador* j1, Jogador* j2, Gerenciador_Grafico* gerenciador, int* pontuacao);
    ~Fase_2();
    void Executar();
};

