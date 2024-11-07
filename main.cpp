#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "Classes_e_metodos.h"
using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    Tabuleiro t;

    bool vez = true;
    int x, x_;
    wchar_t y, y_;

    while(true) {
        t.imprimir_Tabuleiro();
        wcout << endl << L"Escolha a peca a ser movida:";
        wcin >> y >> x;
        wcout << endl << L"Escolha a jogada a ser feita:";
        wcin >> y_ >> x_;
        wcout << endl;

        if(t.jogada(y, x, y_, x_, vez)) {
            vez = !vez;
        }
    }
}
