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
void buildGraph(graph &G)
{
    addVertex(G, createVertex('A'));
    addVertex(G, createVertex('B'));
    addVertex(G, createVertex('C'));
    addVertex(G, createVertex('D'));
    addVertex(G, createVertex('E'));
    addVertex(G, createVertex('F'));
    
    // A
    addEdge(G, searchVertex(G, 'A'), createEdge('C', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'A'), createEdge('B', 1/* harus diubah */));
    
    // B
    addEdge(G, searchVertex(G, 'B'), createEdge('A', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'B'), createEdge('C', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'B'), createEdge('D', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'B'), createEdge('E', 1/* harus diubah */));
    
    // C
    addEdge(G, searchVertex(G, 'C'), createEdge('A', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'C'), createEdge('B', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'C'), createEdge('D', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'C'), createEdge('E', 1/* harus diubah */));
    
    // D
    addEdge(G, searchVertex(G, 'D'), createEdge('B', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'D'), createEdge('C', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'D'), createEdge('E', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'D'), createEdge('F', 1/* harus diubah */));
    
    // E
    addEdge(G, searchVertex(G, 'E'), createEdge('B', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'E'), createEdge('C', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'E'), createEdge('D', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'E'), createEdge('F', 1/* harus diubah */));
    
    addEdge(G, searchVertex(G, 'F'), createEdge('D', 1/* harus diubah */));
    addEdge(G, searchVertex(G, 'F'), createEdge('E', 1/* harus diubah */));
}
adrVertex searchVertex(graph G, char vertexID)
{
    if (G.firstVertex == nullptr)
    {
        return nullptr;
    } else
    {
        adrVertex p = G.firstVertex;
        while (p != nullptr && p->id != vertexID)
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
