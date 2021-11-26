#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
class Obstaculo :
    public Entidade
{
private:
public:
    Obstaculo(sf::Vector2f size, float x, float y);
    ~Obstaculo();
};

