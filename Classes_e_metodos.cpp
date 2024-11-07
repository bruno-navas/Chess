#include "Classes_e_metodos.h"

void setColor(int background, int text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background << 4) | text);
}

Peca::Peca(wchar_t simbolo, int x, int y) {
    _simbolo = simbolo;
    _x = x;
    _y = y;
}

Tabuleiro::Tabuleiro() {

    tabuleiro = {
        {Torre(L'\u265C', 0, 0), Cavalo(L'\u265E', 0, 1), Bispo(L'\u265D', 0, 2), Rei(L'\u265B', 0, 3), Rainha(L'\u265A', 0, 4), Bispo(L'\u265D', 0, 5), Cavalo(L'\u265E', 0, 6), Torre(L'\u265D', 0, 5)},
        {Peao(L'\u265F', 1, 0), Peao(L'\u265F', 1,1), Peao(L'\u265F', 1, 2), Peao(L'\u265F', 1, 3), Peao(L'\u265F', 1, 4), Peao(L'\u265F', 1, 5), Peao(L'\u265F', 1, 6), Peao(L'\u265F', 1, 7)},
        {Peca(L'\u3000', 2, 0), Peca(L'\u3000', 2, 1), Peca(L'\u3000', 2, 2), Peca(L'\u3000', 2, 3), Peca(L'\u3000', 2, 4), Peca(L'\u3000', 2, 5), Peca(L'\u3000', 2, 6), Peca(L'\u3000', 2, 7)},
        {Peca(L'\u3000', 3, 0), Peca(L'\u3000', 3, 1), Peca(L'\u3000', 3, 2), Peca(L'\u3000', 3, 3), Peca(L'\u3000', 3, 4), Peca(L'\u3000', 3, 5), Peca(L'\u3000', 3, 6), Peca(L'\u3000', 3, 7)},
        {Peca(L'\u3000', 4, 0), Peca(L'\u3000', 4, 1), Peca(L'\u3000', 4, 2), Peca(L'\u3000', 4, 3), Peca(L'\u3000', 4, 4), Peca(L'\u3000', 4, 5), Peca(L'\u3000', 4, 6), Peca(L'\u3000', 4, 7)},
        {Peca(L'\u3000', 5, 0), Peca(L'\u3000', 5, 1), Peca(L'\u3000', 5, 2), Peca(L'\u3000', 5, 3), Peca(L'\u3000', 5, 4), Peca(L'\u3000', 5, 5), Peca(L'\u3000', 5, 6), Peca(L'\u3000', 5, 7)},
        {Peao(L'\u2659', 6, 0), Peao(L'\u2659', 6, 1), Peao(L'\u2659', 6, 2), Peao(L'\u2659', 6, 3), Peao(L'\u2659', 6, 4), Peao(L'\u2659', 6, 5), Peao(L'\u2659', 6, 6), Peao(L'\u2659', 6, 7)},
        {Torre(L'\u2656', 7, 0), Cavalo(L'\u2658', 7, 1), Bispo(L'\u2657', 7, 2), Rei(L'\u2655', 7, 3), Rainha(L'\u2654', 7, 4), Bispo(L'\u2657', 7, 5), Cavalo(L'\u2658', 7, 6),Torre(L'\u2656', 7, 7)}
    };
}

void Tabuleiro::imprimir_Tabuleiro() const{
    int i, j;
    i = j = 0;

    wcout << L"   Ａ  Ｂ  Ｃ  Ｄ  Ｅ  Ｆ  Ｇ  Ｈ " << endl;

    for (const auto& x:tabuleiro) {
        wcout << 8-i << L' ';
        for (auto y:x) {
            bool peca_preta = (i + j) % 2 == 1;
            bool peca_branca = !peca_preta;

            if (peca_branca) {
                setColor(7, peca_branca ? 0 : 0);
            } else {
                setColor(0, peca_branca ? 15 : 8);
            }

            visit([](const auto& p) { p.imprimirSimbolo(); }, y);

            j++;
        }
        i++;
        setColor(0, 7);
        wcout << endl;
    }
}

bool Peao::checa_movimento(char coluna, int linha, vector<vector<Variants>> tabuleiro) const {
    int col = static_cast<int>(coluna) - 65;
    linha = linha--;

    auto p = get<Peao>(tabuleiro[_x][_y]);

    //(piece >= L'\u2654' && piece <= L'\u2659')

    /*bool flag;

    if(col>7 or linha>7) {
        return false;
    }

    if(_x==1 or _x==6) {
        if(col = _y and (linha==_x))
    }*/

    return false;

}





