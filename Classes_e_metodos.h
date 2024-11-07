#ifndef CLASSES_E_METODOS_H
#define CLASSES_E_METODOS_H

#include <iostream>
#include <vector>
#include <variant>
#include <windows.h>
using namespace std;

class Peca;
class Peao;
class Torre;
class Cavalo;
class Bispo;
class Rei;
class Rainha;

using Variants = variant<Peca, Peao, Torre, Cavalo, Bispo, Rei, Rainha>;

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

    [[nodiscard]] virtual bool checa_movimento(char coluna, int linha, vector<vector<Variants>> tabuleiro) const{return true;}

    friend class Tabuleiro;
};

class Peao : public Peca {
public:
    Peao(wchar_t simbolo, int x, int y) : Peca(simbolo, x, y){}

    void imprimirSimbolo() const override {
        wcout << L" " << _simbolo << L" ";
    }

    [[nodiscard]] bool checa_movimento(char coluna, int linha, vector<vector<Variants>> tabuleiro) const override;
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

class Tabuleiro {
public:
    vector<vector<Variants>> tabuleiro;

    Tabuleiro();

    void imprimir_Tabuleiro() const;
};


#endif //CLASSES_E_METODOS_H
