#include <iostream>
#include <string>
#include "../header/kamus.h"

using namespace std;

void startGame(graph &G, adrUser &p) // Meminta input level dari user dan menginisialisasi player
{
    int     level;
    bool    valid = false;
    do
    {
        pilihLevel(); // Menampilkan pilihan level
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
    buildGraph(G, level); // Kirim level ke buildGraph
    p->lokasi = G.firstVertex;
}
void playerMovement(graph G, adrUser &p) // Menangani pergerakan player
{
    char pergi;
    running(p); // Menampilkan opsi gerak user
    cin >> pergi;
    adrEdge e = searchEdge(p->lokasi, pergi); // Mencari edge sesuai input user
    if (e == nullptr)
    {
        errorInput();
    } else
    {
        p->lokasi = searchVertex(G, e->vertexID);
        p->energi -= e->cost;
    }
}

