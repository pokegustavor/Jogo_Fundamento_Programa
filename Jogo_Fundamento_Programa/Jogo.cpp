#include "Jogo.h"

Jogo::Jogo()
{
    Level = -1;
    doisJogadores = false;
    pontuacao = 0;
    gerenciador_graf = new Gerenciador_Grafico();
    jogador1 = new Jogador(true,0,0);
    jogador1->setGerenciador(gerenciador_graf);
    jogador2 = new Jogador(false,0,0);
    jogador2->setGerenciador(gerenciador_graf);
    fase = nullptr;
    menu = new Menu(gerenciador_graf, &Level, &doisJogadores);
    ifstream records = ifstream("records.txt");
    if(!records.is_open())
    {
        ofstream newRecords = ofstream("records.txt");
        newRecords.close();
    }
    else
    {
        records.close();
    }
    Executar();
}

Jogo::~Jogo()
{
}


bool Jogo::VerificarPontuacao()
{
    ifstream records = ifstream("records.txt");
    int rank[5];
    string names[5];
    for(int i = 0; i < 5; i++)
    {
        rank[i] = -1;
    }
    int count = 0;
    bool novoRecord = false;
    string line;
    while(!records.eof() && count < 5)
    {
        if(getline(records,line))
        {
            names[count] = line.substr(0, line.find(','));
            rank[count] = stoi(line.substr(line.find(',') + 1, line.size()));
            count++;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        if(rank[i] == -1 || pontuacao > rank[i])
        {
            novoRecord = true;
            break;
        }
    }
    records.close();
    sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1600.0f, 800.0f));
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text = sf::Text("text", font, 50);
    string name;
    sf::Event event;
    while(novoRecord && gerenciador_graf->window->isOpen())
    {
        gerenciador_graf->window->clear();
        background.setFillColor(sf::Color::Green);
        gerenciador_graf->window->draw(background);
        text.setString("You Win");
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(150);
        text.setPosition(450.f, 250.f);
        gerenciador_graf->window->draw(text);
        text.setString("Points: " + std::to_string(pontuacao));
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(100);
        text.setPosition(460.f, 450.f);
        gerenciador_graf->window->draw(text);
        text.setString("Select your name: ");
        text.setPosition(110.f, 540.f);
        gerenciador_graf->window->draw(text);
        text.setString("");
        while (gerenciador_graf->window->pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                //name = text.getString();
                name += event.text.unicode;
            }
            
            if (event.type == sf::Event::Closed)
                gerenciador_graf->window->close();
        }
        if ((name.length() > 3 || sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) && name.length() > 0)
        {
            name.pop_back();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && name.length() > 0)
        {
            novoRecord = false;
            ofstream writer = ofstream("records.txt");
            count = 0;
            while(count < 4 && rank[count] >= pontuacao)
            {
                writer << names[count] << ',' << rank[count] << '\n';
                count++;
            }
            writer << name << ',' << pontuacao << '\n';
            while (count < 4 && rank[count] != -1)
            {
                writer << names[count] << ',' << rank[count] << '\n';
                count++;
            }
            writer.close();
            return true;
        }
        text.setString(name);
        text.setPosition(920.f, 540.f);
        gerenciador_graf->window->draw(text);
        gerenciador_graf->window->display();
    }
    return false;
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
            text.setCharacterSize(150);
            text.setPosition(450.f, 250.f);
            gerenciador_graf->window->draw(text);
            text.setString("Points: " + std::to_string(pontuacao));
            text.setFillColor(sf::Color::White);
            text.setCharacterSize(100);
            text.setPosition(460.f, 450.f);
            gerenciador_graf->window->draw(text);
            gerenciador_graf->window->display();
            if ((double)(now - timer) > 3.f || VerificarPontuacao())
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
            text.setCharacterSize(150);
            text.setPosition(400.f, 250.f);
            gerenciador_graf->window->draw(text);
            gerenciador_graf->window->display();
            if((double)(now - timer) > 3.f || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Level = -1;
            }
            break;
        case -1:
            menu->Executar();
            break;
        case 0:
            if(fase == nullptr)
            {
                fase = new Fase_1(jogador1, doisJogadores ? jogador2 : nullptr, gerenciador_graf,&pontuacao);
            }
            fase->Executar();
            break;
        case 1:
            if (fase == nullptr)
            {
                fase = new Fase_2(jogador1, doisJogadores ? jogador2 : nullptr, gerenciador_graf, &pontuacao);
            }
            fase->Executar();
            break;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Level != -1)
        {
            Level = -1;
            fase = nullptr;
            jogador1 = new Jogador(true,0,0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false,0,0);
            jogador2->setGerenciador(gerenciador_graf);
        }
        if((jogador1->morto && (jogador2->morto || !doisJogadores)))
        {
            Level = -2;
            fase = nullptr;
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
            fase = nullptr;
            jogador1 = new Jogador(true, 0, 0);
            jogador1->setGerenciador(gerenciador_graf);
            jogador2 = new Jogador(false, 0, 0);
            jogador2->setGerenciador(gerenciador_graf);
            time(&timer);
        }
    }
}
