#include "Jogo.h"

Jogo::Jogo()
{
    Level = -1;
    doisJogadores = false;
    gerenciador_graf = new Gerenciador_Grafico();
    jogador1 = new Jogador(true,0,0);
    jogador1->setGerenciador(gerenciador_graf);
    jogador2 = new Jogador(false,0,0);
    jogador2->setGerenciador(gerenciador_graf);
    fase1 = nullptr;
    menu = new Menu(gerenciador_graf, &Level, &doisJogadores);
    Executar();
}

Jogo::~Jogo()
{
}


void Jogo::Executar()
{
    while (gerenciador_graf->window->isOpen())
    {
        
        sf::Event event;
        while (gerenciador_graf->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gerenciador_graf->window->close();
        }
        //fase1->Executar();
        switch (Level)
        {
        default:
        case -1:
            menu->Executar();
            break;
        case 0:
            if(fase1 == nullptr)
            {
                fase1 = new Fase_1(jogador1, doisJogadores ? jogador2 : nullptr, gerenciador_graf);
            }
            fase1->Executar();
            break;
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Level != -1) || (jogador1->morto && (jogador2->morto || !doisJogadores)))
        {
            Level = -1;
            fase1 = nullptr;
            jogador1 = new Jogador(true,0,0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false,0,0);
            jogador2->setGerenciador(gerenciador_graf);
        }
        if(jogador1->finalizado)
        {
            jogador1->finalizado = false;
            Level = -1;
            fase1 = nullptr;
            jogador1 = new Jogador(true, 0, 0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false, 0, 0);
            jogador2->setGerenciador(gerenciador_graf);
        }
    }
}
