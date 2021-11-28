#pragma once
#include "Obstaculo.h"
class Obstaculo_C :
    public Obstaculo
{
private:
    time_t ultimaMuldanca;
public:
    Obstaculo_C(sf::Vector2f size,float x, float y);
    ~Obstaculo_C();
    void Executar();
};

