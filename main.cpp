#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "Classes_e_metodos.h"

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    Tabuleiro t;
    t.imprimir_Tabuleiro();

    //Peao p(L'\u265F', 1, 0);
    //bool f = p.checa_movimento('A', 0, t.tabuleiro);
    return 0;
}
