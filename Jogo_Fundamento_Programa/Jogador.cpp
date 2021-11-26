#include "Jogador.h"

Jogador::Jogador(bool jogador1, float x, float y):Personagem(x,y)
{
    finalizado = false;
    num_vidas = 3;
    this->Jogador1 = jogador1;
    if (jogador1)
    {
        x = 400;
        y = 150;
        sprite.setFillColor(sf::Color::Magenta);
    }
    else
    {
        x = 400;
        y = 450;
        sprite.setFillColor(sf::Color::Yellow);
    }
    velocidadeMax = 0.08f;
    alvo = nullptr;
}

Jogador::~Jogador()
{
}

void Jogador::Move()
{
    if (Jogador1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            velocidadeHorizontal += 0.08f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            velocidadeHorizontal -= 0.08f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao)
        {
            velocidadeVertical = -0.1f;
        }
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            velocidadeHorizontal += 0.08f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            velocidadeHorizontal -= 0.08f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && noChao)
        {
            velocidadeVertical = -0.1f;
        }
    }
    if(velocidadeHorizontal > velocidadeMax)
    {
        velocidadeHorizontal = velocidadeMax;
    }
    else if(velocidadeHorizontal < -velocidadeMax)
    {
        velocidadeHorizontal = -velocidadeMax;
    }
}

void Jogador::Executar()
{
    Move();
    Personagem::Executar();
}


