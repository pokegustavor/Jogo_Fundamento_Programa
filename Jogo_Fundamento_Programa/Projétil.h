#pragma once
#include "Entidade.h"
class Projétil :
    public Entidade
{
private:
    bool esquerda;
public:
    Projétil(bool esquerda, float x, float y);
    ~Projétil();
    void Executar();
    void Imprimir_se();
};

