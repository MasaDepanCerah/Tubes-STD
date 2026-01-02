#include <iostream>
#include <string>
#include "../header/kamus.h"

using namespace std;

void pilihLevel()
{
    string text = R"(
+=== PILIH TINGKAT KESULITAN ===+
| [1] BAYI   (Start 100 Energy) |
| [2] REMAJA (Start  50 Energy) |
| [3] SEPUH  (Start  30 Energy) |
| [0] MALAS MENANGGAPI          |
+===============================+
Pilihanmu: )";

    printf("%s", text.c_str());
}
void exitGame()
{
    string text = R"(
Yah gagal nolep
)";
    printf("%s", text.c_str());
}
void gameOver()
{
    string text = R"(
+===============================+
|    GAME OVER - ENERGI HABIS   |
|    Kamu pingsan dijalan....   |
+===============================+
)";
    printf("%s", text.c_str());
}
void finish()
{
    string text = R"(
+===============================+
|    SAMPAI DI TUJUAN (F)!      |
+===============================+
)";
    printf("%s", text.c_str());
}
void running(adrUser player)
{
    adrEdge p = player->lokasi->firstEdge;
    string text;
    while (p != nullptr)
    {
        text += "Pergi ke ";
        text += p->vertexID;
        text += "\n";
        p = p->next;
    }
    
    printf(
    "Posisi\t: %c\n"
    "Energi\t: %d\n"
    "Pilihan Jalan\n%s"
    "Pilihanmu: ",
    player->lokasi->id,
    player->energi,
    text.c_str()
    );
}
void errorInput()
{
    string text = R"(
+===============================+
|       INPUT TIDAK SESUAI      |
+===============================+
)";
    printf("%s", text.c_str());
}