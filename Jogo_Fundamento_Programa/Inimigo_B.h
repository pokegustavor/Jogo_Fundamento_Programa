#pragma once
#include "Inimigo.h"
#include "Projétil.h"
#include <chrono>
#include <iostream>
using namespace std::chrono;
class Inimigo_B :
    public Inimigo
{
private:
    time_t ultimoTiro;
    void Atirar();
public:
    Inimigo_B(Jogador* jogador1, Jogador* jogador2);
    ~Inimigo_B();
    void Executar();
    void Imprimir_se();
    void AtualizarAlvo();
};

