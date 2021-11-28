#pragma once
#include "Ente.h"
#include "Fase.h"
#include "Fase_1.h"
#include <iostream>
#include <fstream>
using namespace std;
class Menu :
    public Ente
{
private:
    int atual;
    bool holdingMouse;
    int* level;
    bool* twoPlayers;
    string nomeRank[5];
    int valorRank[5];
public:
    Menu(Gerenciador_Grafico* gerenciador, int* level, bool* twoPlayers);
    ~Menu();
    void Executar();
    void Imprimir_se();
};

