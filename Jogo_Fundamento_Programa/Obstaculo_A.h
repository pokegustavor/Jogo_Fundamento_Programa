#pragma once
#include "Obstaculo.h"
class Obstaculo_A :
    public Obstaculo
{
private:
public:
    Obstaculo_A(sf::Vector2f size, float x, float y);
    ~Obstaculo_A();
    void Executar();
};

