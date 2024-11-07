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

void troca_posicao(unique_ptr<Peca> &p1, unique_ptr<Peca> &p2) {

    int x_aux = p1->_x;
    int y_aux = p1->_y;
    p1->_x = p2->_x;
    p1->_y = p2->_y;
    p2->_x = x_aux;
    p2->_y = y_aux;
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
                setColor(7, 0);
            } else {
                setColor(0, 8);
            }

            visit([](const auto& p) { p.imprimirSimbolo(); }, y);

            j++;
        }
        i++;
        setColor(0, 7);
        wcout << endl;
    }
}

unique_ptr<Peca> Tabuleiro::descobre_tipo(int x, int y) const {
    if (std::holds_alternative<Peca>(tabuleiro[x][y])) {
        auto p = std::get<Peca>(tabuleiro[x][y]);
        return make_unique<Peca>(p._simbolo, x, y);
    }
    if (std::holds_alternative<Peao>(tabuleiro[x][y])) {
        auto p = std::get<Peao>(tabuleiro[x][y]);
        return make_unique<Peao>(p._simbolo,x,y);
    }
    if (std::holds_alternative<Torre>(tabuleiro[x][y])) {
        auto p = std::get<Torre>(tabuleiro[x][y]);
        return make_unique<Torre>(p._simbolo,x,y);
    }
    if (std::holds_alternative<Cavalo>(tabuleiro[x][y])) {
        auto p = std::get<Cavalo>(tabuleiro[x][y]);
        return make_unique<Cavalo>(p._simbolo,x,y);
    }
    if (std::holds_alternative<Bispo>(tabuleiro[x][y])) {
        auto p = std::get<Bispo>(tabuleiro[x][y]);
        return make_unique<Bispo>(p._simbolo,x,y);
    }
    if (std::holds_alternative<Rainha>(tabuleiro[x][y])) {
        auto p = std::get<Rainha>(tabuleiro[x][y]);
        return make_unique<Rainha>(p._simbolo,x,y);
    }
    if (std::holds_alternative<Rei>(tabuleiro[x][y])) {
        auto p = std::get<Rei>(tabuleiro[x][y]);
        return make_unique<Rei>(p._simbolo,x,y);
    }
    return make_unique<Peca>();
}

void Peao::movimento(wchar_t coluna, int x, Tabuleiro &t)  {
    const int y = static_cast<int>(coluna) - 65;
    x = 8-x;

    //Checa se a jogada desejada esta dentro do tabuleiro
    if((y>7 or x>7)or(y<0 or x<0)) {
        wcout << "Jogada invalida1" << endl;
        return;
    }

    auto p_atual = t.descobre_tipo(_x, _y);
    auto p_nova = t.descobre_tipo(x, y);

    //Peça preta
    if(!(p_atual->_simbolo >= L'\u2654' and p_atual->_simbolo <= L'\u2659')) {
        if(_x==1) {
            if(y==_y and (x==_x+1 or x==_x+2)) {
                troca_posicao(p_atual, p_nova); //Inverte o indice das peças
                swap(t.tabuleiro[_x][_y], t.tabuleiro[x][y]); //Inverte a posição das peças no tabuleiro
            }
            else {
                wcout << "Jogada invalida" << endl;
                return;
            }
        }
        else {
            if(y==_y and x==_x+1) {
                troca_posicao(p_atual, p_nova); //Inverte o indice das peças
                swap(t.tabuleiro[_x][_y], t.tabuleiro[x][y]); //Inverte a posição das peças no tabuleiro
            }
            else {
                wcout << "Jogada invalida" << endl;
            }
        }
    }

    //Peça branca
    else {
        if(_x==6) {
            if(y==_y and (x==_x-1 or x==_x-2)) {
                troca_posicao(p_atual, p_nova); //Inverte o indice das peças
                swap(t.tabuleiro[_x][_y], t.tabuleiro[x][y]); //Inverte a posição das peças no tabuleiro
            }
            else {
                wcout << "Jogada invalida2" << endl;
            }
        }
        else {
            if(y==_y and x==_x-1) {
                troca_posicao(p_atual, p_nova); //Inverte o indice das peças
                swap(t.tabuleiro[_x][_y], t.tabuleiro[x][y]); //Inverte a posição das peças no tabuleiro
            }
            else {
                wcout << "Jogada invalida3" << endl;
            }
        }
    }
    _x = p_atual->_x;
    _y = p_atual->_y;
}

bool Tabuleiro::jogada(wchar_t y_o, int x_o, wchar_t y_d, int x_d, const bool vez) {
    const int y1_o = static_cast<int>(y_o) - 65;
    x_o = 8-x_o;

    if (vez) {
        auto p_origem = this->descobre_tipo(x_o, y1_o);
        if(p_origem->_simbolo >= L'\u2654' and p_origem->_simbolo <= L'\u2659') {
            p_origem->movimento(y_d, x_d, *this);
        }
        else {
            wcout << "Jogada invalida" << endl;
            return false;
        }
    }
    else {
        auto p_origem = this->descobre_tipo(x_o, y1_o);
        if(!(p_origem->_simbolo >= L'\u2654' and p_origem->_simbolo <= L'\u2659')) {
            p_origem->movimento(y_d, x_d, *this);
        }
        else {
            wcout << "Jogada invalida" << endl;
            return false;
        }
    }
    return true;
}






