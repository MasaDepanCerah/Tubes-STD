#include <iostream>
#include <string>
#include "../header/kamus.h"

using namespace std;

void startGame(graph &G, adrUser &p)
{
    int     level;
    bool    valid = false;
    do
    {
        pilihLevel();
        cin >> level;
        switch (level)
        {
        case 0:
            exitGame();
            exit(0);
        case 1:
            p->energi = 100;
            valid = true;
            break;
        case 2:
            p->energi = 50;
            valid = true;
            break;
        case 3:
            p->energi = 30;
            valid = true;
            break;
        default:
            errorInput();
        }
    } while (!valid);
    buildGraph(G);
    p->lokasi = G.firstVertex;
}
void playerMovement(graph G, adrUser &p)
{
    char pergi;
    running(p);
    cin >> pergi;
    adrEdge e = searchEdge(p->lokasi, pergi);
    if (e == nullptr)
    {
        errorInput();
    } else
    {
        p->lokasi = searchVertex(G, e->vertexID);
        p->energi -= e->cost;
    }
}

