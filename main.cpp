#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "Classes_e_metodos.h"
using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    Tabuleiro t;

    t.Chess();
}
