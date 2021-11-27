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
        sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1600.0f, 800.0f));
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text = sf::Text("text", font, 50);
        time_t now;
        time(&now);
        switch (Level)
        {
        default:
        case -3:
            gerenciador_graf->window->clear();
            background.setFillColor(sf::Color::Green);
            gerenciador_graf->window->draw(background);
            text.setString("You Win");
            text.setFillColor(sf::Color::Yellow);
            text.setCharacterSize(150.f);
            text.setPosition(450.f, 250.f);
            gerenciador_graf->window->draw(text);
            gerenciador_graf->window->display();
            if ((double)(now - timer) > 3.f)
            {
                Level = -1;
            }
            break;
        case -2:
            gerenciador_graf->window->clear();
            background.setFillColor(sf::Color::Green);
            gerenciador_graf->window->draw(background);
            text.setString("Game Over");
            text.setFillColor(sf::Color::Red);
            text.setCharacterSize(150.f);
            text.setPosition(400.f, 250.f);
            gerenciador_graf->window->draw(text);
            gerenciador_graf->window->display();
            if((double)(now - timer) > 3.f)
            {
                Level = -1;
            }
            break;
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Level != -1)
        {
            Level = -1;
            fase1 = nullptr;
            jogador1 = new Jogador(true,0,0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false,0,0);
            jogador2->setGerenciador(gerenciador_graf);
        }
        if((jogador1->morto && (jogador2->morto || !doisJogadores)))
        {
            Level = -2;
            fase1 = nullptr;
            jogador1 = new Jogador(true, 0, 0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false, 0, 0);
            jogador2->setGerenciador(gerenciador_graf);
            time(&timer);
        }
        if(jogador1->finalizado)
        {
            jogador1->finalizado = false;
            Level = -3;
            fase1 = nullptr;
            jogador1 = new Jogador(true, 0, 0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false, 0, 0);
            jogador2->setGerenciador(gerenciador_graf);
            time(&timer);
        }
    }
}
