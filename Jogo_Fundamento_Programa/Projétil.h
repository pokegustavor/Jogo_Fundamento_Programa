#pragma once
#include "Entidade.h"
class Proj�til :
    public Entidade
{
private:
    bool esquerda;
public:
    Proj�til(bool esquerda);
    ~Proj�til();
    void Executar();
};

