#pragma once
#include "Entidade.h"
class Proj�til :
    public Entidade
{
private:
    bool esquerda;
public:
    Proj�til(bool esquerda, float x, float y);
    ~Proj�til();
    void Executar();
    void Imprimir_se();
};

