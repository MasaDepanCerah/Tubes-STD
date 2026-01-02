#ifndef KAMUS_H
#define KAMUS_H

// Graph data declaration
typedef struct vertex   *adrVertex;
typedef struct edge     *adrEdge;

struct vertex
{
    char        id;
    adrVertex   next;
    adrEdge     firstEdge;
};

struct edge
{
    char        vertexID;
    int         cost;
    adrEdge     next;
};

struct graph
{
    adrVertex   firstVertex;
};

//==================================================================================================================================

// Player data declaration

typedef struct player   *adrUser;

struct player
{
    adrVertex   lokasi;
    int         energi;
};

//==================================================================================================================================

// Interface procedure declaration

/*
Procedure pilihLevel
IS: -
FS: Menampilkan pilihan level yang dapat dipilih oleh user
*/
void pilihLevel();

/*
procedure exitGame
IS: -
FS: Menampilkan pesan keluar dari game
*/
void exitGame();

/*
Procedure gameOver
IS: -
FS: Menampilkan pesan game over
*/
void gameOver();

/*
Procedure finish
IS: -
FS: Menampilkan pesan selamat telah menyelesaikan game
*/
void finish();

/*
Procedure running
IS: Terdefinisi vertex tempat lokasi user berada dan energi dengan tipe integer
FS: Menampilkan opsi gerak user
*/
void running(adrUser player);

/*
Procedure errorInput
IS: -
FS: Menampilkan pesar input user tidak sesuai
*/
void errorInput();

//==================================================================================================================================


// Graph function declaration

/*
Procedure createGraph
IS: -
FS: Terdefinisi sebuah graph dimana G.firstVertex bernilai NULL
*/
void createGraph(graph &G);

/*
Procedure addVertex
IS: Terdefinisi graph G dan vertex v
FS: Vertex v ditambahkan dalam graf G pada urutan paling terakhir
*/
void addVertex(graph &G, adrVertex v);

/*
Procedure addEdge
IS: Terdefinisi graph G, egde e, dan vertex v
FS: Edge e ditambahkan dalam vertex v pada urutan paling terakhir
*/
void addEdge(graph &G, adrVertex v, adrEdge e);

/*
Function createVertex
IS: Terdefinisi vertexID dengan tipe character
FS: Mengembalikan vertex dengan id yang terisi serta next dan firstEdge yang bernilai NULL
*/
adrVertex createVertex(char id);

/*
Function createEdge
IS: Terdefinisi vertexID dengan tipe character dan cost dengan tipe integer
FS: Mengembalikan edge dengan id dan cost yang terisi serta next yang bernilai NULL
*/
adrEdge createEdge(char id, int cost);

/*
Procedure buildGraph
IS: Terdefinisi graph G
FS: Sebuah graf dibuat
*/
void buildGraph(graph &G);

/*
Function searchVertex
IS: Terdefinisi graph G dan vertexID dengan tipe character
FS: Mengembalikan vertex yang memiliki id sesuai dengan vertexID
*/
adrVertex searchVertex(graph G, char vertexID);

/*
Function searchEdge
IS: Terdefinisi 
FS: Mengembalikan edge yang memiliki vertxID yang sesuai dengan vertexID
*/
adrEdge searchEdge(adrVertex v, char vertexID);


//==================================================================================================================================

// Playe function declaration

/*
Procedure startGame
IS: Terdefinisi graph G dan player p
FS: Player p->lokasi bernilai G.firstVertex dan p->energi bernilai sesuai input kesulitan yang dipilih user
*/
void startGame(graph &G, adrUser &p);

/*
Procedure playerMovement
IS: Terdefinisi
FS:
*/
void playerMovement(graph G, adrUser &p);

#endif // KAMUS_H