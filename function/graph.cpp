#include <iostream>
#include "../header/kamus.h"

using namespace std;

void createGraph(graph &G) 
{
    G.firstVertex = nullptr;
}
void addVertex(graph &G, adrVertex v) 
{
    if (G.firstVertex == nullptr)
    {
        G.firstVertex = v;
    } else
    {
        adrVertex p = G.firstVertex;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = v;
    }
}
void addEdge(graph &G, adrVertex v, adrEdge e) 
{
    if (v->firstEdge == nullptr)
    {
        v->firstEdge = e;
    } else
    {
        adrEdge p = v->firstEdge;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = e;
    }
}
adrVertex createVertex(char id) 
{
    adrVertex v = new vertex;
    v->id = id;
    v->firstEdge = nullptr;
    v->next = nullptr;
    return v;
}
adrEdge createEdge(char id, int cost) 
{
    adrEdge e = new edge;
    e->vertexID = id;
    e->cost = cost;
    e->next = nullptr;
    return e;
}
void buildGraph(graph &G, int level)
{
    if (level == 1)
    {
        addVertex(G, createVertex('A'));
        addVertex(G, createVertex('B'));
        addVertex(G, createVertex('C'));
        addVertex(G, createVertex('D'));
        addVertex(G, createVertex('E'));
        addVertex(G, createVertex('F'));
        
        // A (Start)
        addEdge(G, searchVertex(G, 'A'), createEdge('C', 2));
        addEdge(G, searchVertex(G, 'A'), createEdge('B', 2));
        
        // B
        addEdge(G, searchVertex(G, 'B'), createEdge('A', 2));
        addEdge(G, searchVertex(G, 'B'), createEdge('C', 2));
        addEdge(G, searchVertex(G, 'B'), createEdge('D', 2));
        addEdge(G, searchVertex(G, 'B'), createEdge('E', 2));
        
        // C
        addEdge(G, searchVertex(G, 'C'), createEdge('A', 2));
        addEdge(G, searchVertex(G, 'C'), createEdge('B', 2));
        addEdge(G, searchVertex(G, 'C'), createEdge('D', 2));
        addEdge(G, searchVertex(G, 'C'), createEdge('E', 2));
        
        // D
        addEdge(G, searchVertex(G, 'D'), createEdge('B', 2));
        addEdge(G, searchVertex(G, 'D'), createEdge('C', 2));
        addEdge(G, searchVertex(G, 'D'), createEdge('E', 2));
        addEdge(G, searchVertex(G, 'D'), createEdge('F', 5)); // Ke Finish
        
        // E
        addEdge(G, searchVertex(G, 'E'), createEdge('B', 2));
        addEdge(G, searchVertex(G, 'E'), createEdge('C', 2));
        addEdge(G, searchVertex(G, 'E'), createEdge('D', 2));
        addEdge(G, searchVertex(G, 'E'), createEdge('F', 5)); // Ke Finish
        
        // F (Finish) - Bisa balik kalau mau iseng
        addEdge(G, searchVertex(G, 'F'), createEdge('D', 5));
        addEdge(G, searchVertex(G, 'F'), createEdge('E', 5));
    }

    // ==========================================
    // LEVEL 2: REMAJA (MAP CABANG)
    // Energy 50. Ada jalan buntu yang menghabiskan energi.
    // Jalur: A -> C -> E -> F (Ideal)
    // ==========================================
    else if (level == 2)
    {
        addVertex(G, createVertex('A'));
        addVertex(G, createVertex('B')); // Buntu
        addVertex(G, createVertex('C')); 
        addVertex(G, createVertex('D')); // Buntu Jauh
        addVertex(G, createVertex('E')); 
        addVertex(G, createVertex('F')); // Finish

        // A
        addEdge(G, searchVertex(G, 'A'), createEdge('B', 10)); // Salah jalan
        addEdge(G, searchVertex(G, 'A'), createEdge('C', 10)); // Jalan benar

        // B (Jalan Buntu, buang 20 energi total kalau bolak-balik)
        addEdge(G, searchVertex(G, 'B'), createEdge('A', 10));

        // C
        addEdge(G, searchVertex(G, 'C'), createEdge('D', 10)); // Jebakan
        addEdge(G, searchVertex(G, 'C'), createEdge('E', 15)); // Jalan benar

        // D (Jalan Buntu Jauh)
        addEdge(G, searchVertex(G, 'D'), createEdge('C', 10));

        // E
        addEdge(G, searchVertex(G, 'E'), createEdge('A', 25)); // Hati-hati balik ke start
        addEdge(G, searchVertex(G, 'E'), createEdge('F', 15)); // FINISH
    }

    // ==========================================
    // LEVEL 3: SEPUH (MAP LABIRIN)
    // Energy 30. Vertex A-J. Cost 'Nipu'.
    // Harus hafal jalan: A -> D -> H -> I -> F
    // ==========================================
    else if (level == 3)
    {
        addVertex(G, createVertex('A')); // Start
        addVertex(G, createVertex('B'));
        addVertex(G, createVertex('C'));
        addVertex(G, createVertex('D')); 
        addVertex(G, createVertex('E'));
        addVertex(G, createVertex('G'));
        addVertex(G, createVertex('H'));
        addVertex(G, createVertex('I'));
        addVertex(G, createVertex('J')); // Dead end parah
        addVertex(G, createVertex('F')); // Finish

        // A (Start)
        addEdge(G, searchVertex(G, 'A'), createEdge('B', 5)); // Jebakan
        addEdge(G, searchVertex(G, 'A'), createEdge('C', 20)); // Mahal
        addEdge(G, searchVertex(G, 'A'), createEdge('D', 5)); // Jalan Benar

        // Jalur Jebakan B-E-G (Kuru-kuru)
        addEdge(G, searchVertex(G, 'B'), createEdge('E', 5));
        addEdge(G, searchVertex(G, 'E'), createEdge('G', 5));
        addEdge(G, searchVertex(G, 'G'), createEdge('B', 10)); // Loop setan

        // Jalur Benar D -> H -> I -> F
        addEdge(G, searchVertex(G, 'D'), createEdge('H', 5)); 
        addEdge(G, searchVertex(G, 'H'), createEdge('I', 10)); 
        addEdge(G, searchVertex(G, 'I'), createEdge('F', 5)); // FINISH (Total cost 25, sisa 5)

        // Jebakan C & J
        addEdge(G, searchVertex(G, 'C'), createEdge('J', 5));
        addEdge(G, searchVertex(G, 'J'), createEdge('A', 30)); // Reset game (mati)
    }
}
adrVertex searchVertex(graph G, char vertexID)
{
    if (G.firstVertex == nullptr) // Graph kosong
    {
        return nullptr;
    } else
    { 
        adrVertex p = G.firstVertex;
        while (p != nullptr && p->id != vertexID) // Telusuri sampai ketemu atau habis
        {
            p = p->next;
        }
        return p;
    }
}
adrEdge searchEdge(adrVertex v, char vertexID)
{
    if (v->firstEdge == nullptr)
    {
        return nullptr;
    } else
    {
        adrEdge p = v->firstEdge;
        while (p != nullptr && p->vertexID != vertexID)
        {
            p = p->next;
        }
        return p;
    }
}
