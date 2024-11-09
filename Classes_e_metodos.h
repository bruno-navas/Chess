#ifndef CLASSES_E_METODOS_H
#define CLASSES_E_METODOS_H

#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <cmath>
#include <windows.h>
using namespace std;

class Peca;
class Peao;
class Torre;
class Cavalo;
class Bispo;
class Rei;
class Rainha;
class Tabuleiro;

using Variants = variant<Peca, Peao, Torre, Cavalo, Bispo, Rei, Rainha>;

class Tabuleiro {
public:
    vector<vector<Variants>> tabuleiro;

    Tabuleiro();

    void imprimir_Tabuleiro() const;
    int Chess();
    bool jogada(int x_o, int y_o, int x_d, int y_d, bool vez);

    [[nodiscard]] unique_ptr<Peca> descobre_tipo(int x, int y) const;
};

class Peca {
public:
    wchar_t _simbolo;
    int _x, _y;

    virtual ~Peca() = default;

    explicit Peca(wchar_t simbolo=L'\u3000', int x=0, int y=0);

    virtual void imprimirSimbolo() const {
        wcout << L" " << _simbolo << L" ";
    }
    [[nodiscard]] bool eh_branco() const {
        if(_simbolo >= L'\u2654' and _simbolo <= L'\u2659') {
            return true;
        }
        if(_simbolo>=L'\u265A' and _simbolo<=L'\u265F') {
            return false;
        }
        return false;
    }

    virtual bool movimento(int x, int y, Tabuleiro &t) {return false;}
    friend void troca_posicao(unique_ptr<Peca> &p1, unique_ptr<Peca> &p2);
};

class Peao : public Peca {
public:
    Peao(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y){}

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }

    bool movimento(int x, int y, Tabuleiro &t) override;
};

class Torre : public Peca {
public:
    Torre(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
    bool movimento(int x, int y, Tabuleiro &t) override;
};

class Cavalo : public Peca {
public:
    Cavalo(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
    bool movimento(int x, int y, Tabuleiro &t) override;
};

class Bispo : public Peca {
public:
    Bispo(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
};

class Rei : public Peca {
public:
    Rei(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
};

class Rainha : public Peca {
public:
    Rainha(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
};


#endif //CLASSES_E_METODOS_H
