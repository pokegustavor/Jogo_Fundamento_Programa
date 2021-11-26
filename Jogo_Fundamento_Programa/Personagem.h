#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
protected:
    int num_vidas;
public:
    Personagem(float x, float y);
    ~Personagem();
    void Executar();
    int getVidas() { return num_vidas; }
    int setVidas(int vida) { num_vidas = vida; }
};

