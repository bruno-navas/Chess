#ifndef CLASSES_E_METODOS_H
#define CLASSES_E_METODOS_H

#include <iostream>
#include <vector>
#include <variant>
#include <memory>
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
    [[nodiscard]] unique_ptr<Peca> descobre_tipo(int x, int y) const;
    bool jogada(wchar_t y_o, int x_o, wchar_t y_d, int x_d, bool vez);
};

class Peca {
protected:
    wchar_t _simbolo;
    int _x, _y;

public:
    virtual ~Peca() = default;

    explicit Peca(wchar_t simbolo=L'\u3000', int x=0, int y=0);

    virtual void imprimirSimbolo() const {
        wcout << L" " << _simbolo << L" ";
    }

    virtual void movimento(wchar_t coluna, int linha, Tabuleiro &t) {};
    friend void troca_posicao(unique_ptr<Peca> &p1, unique_ptr<Peca> &p2);

    friend class Tabuleiro;
    friend class Peao;
};

class Peao : public Peca {
public:
    Peao(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y){}

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }

    void movimento(wchar_t coluna, int linha, Tabuleiro &t) override;
};

class Torre : public Peca {
public:
    Torre(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
};

class Cavalo : public Peca {
public:
    Cavalo(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y) {};

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }
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
