#include <iostream>
#include "header/kamus.h"

using namespace std;

int main()
{
    graph G;
    createGraph(G);

    adrUser p = new player;
    startGame(G, p);

    while (p->lokasi->id != 'F' && p->energi > 0)
    {
        playerMovement(G, p);
    }
    
    if (p->energi > 0)
    {
        finish();
    } else
    {
        gameOver();
    }
    

    return 0;
}
