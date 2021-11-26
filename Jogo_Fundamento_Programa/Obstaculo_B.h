#pragma once
#include "Obstaculo.h"
class Obstaculo_B :
    public Obstaculo
{
private:
public:
    Obstaculo_B(sf::Vector2f size, float x, float y);
    ~Obstaculo_B();
    void Executar();
};

