#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes_e_metodos.h"
using namespace sf;

constexpr int N_casas = 8;              // Tamanho do tabuleiro (8x8)
constexpr int Tamanho_celula = 135;     // Tamanho de cada célula em pixels (ajustado para 1080px de altura total)
VideoMode desktopMode = VideoMode::getDesktopMode();

int Tabuleiro::Chess() {
    // Criação da janela em fullscreen com a resolução atual da tela
    RenderWindow window(desktopMode, "Tabuleiro de Xadrez - Fullscreen", Style::Fullscreen);

    // Carregar fonte para as peças
    Font font;
    if (!font.loadFromFile("FreeSerif.otf")) {
        std::cerr << "Erro ao carregar a fonte Arial!" << std::endl;
        return -1;
    }

    int marginX = static_cast<int>(desktopMode.width - N_casas * Tamanho_celula) / 2; // Calcula a margem para centralizar o tabuleiro
    bool Origem = true;
    bool Temos2posicoes = false;
    bool VezBrancaouPreta = true;
    int xorigem, yorigem, xdestino, ydestino;

    Color green(119, 149, 86);
    Color offwhite(245, 245, 245);

    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // Fechar a janela ao pressionar a tecla Escape
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();

            // Detecta clique do mouse
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                int x = event.mouseButton.x - marginX;  // Ajuste para margem
                int y = event.mouseButton.y;

                // Verifica se o clique está dentro do tabuleiro
                if (x >= 0 && x < N_casas * Tamanho_celula && y >= 0 && y < N_casas * Tamanho_celula) {
                    if (Origem) {
                        xorigem = y/Tamanho_celula;
                        yorigem = x/Tamanho_celula;
                        Origem = false;
                    }
                    else {
                        xdestino = y/Tamanho_celula;
                        ydestino = x/Tamanho_celula;
                        Origem = true;
                        Temos2posicoes = true;
                    }
                }
            }
            if (Temos2posicoes) {
                if(this->jogada(xorigem, yorigem, xdestino, ydestino, VezBrancaouPreta)) {
                    VezBrancaouPreta = !VezBrancaouPreta;
                }
                Temos2posicoes = false;
            }
        }

        window.clear();

        for (int i = 0; i < N_casas; ++i) {
            for (int j = 0; j < N_casas; ++j) {
                RectangleShape cell(Vector2f(static_cast<float>(Tamanho_celula), static_cast<float>(Tamanho_celula)));
                cell.setPosition(static_cast<float>(marginX + i * Tamanho_celula), static_cast<float>(j * Tamanho_celula));

                // Alterna as cores para criar o padrão do tabuleiro de xadrez
                if ((i + j) % 2 == 0)
                    cell.setFillColor(green);
                else
                    cell.setFillColor(offwhite);

                window.draw(cell);

                Text piece;
                piece.setFont(font);
                auto p = this->descobre_tipo(j, i);

                if (p->_simbolo!=L'\u3000') {
                    piece.setString(p->_simbolo);
                    piece.setCharacterSize(Tamanho_celula - 20);  // Ajuste de tamanho para peças

                    // Ajuste de cor para contraste com o fundo
                    piece.setFillColor(sf::Color::Black);

                    // Obter os limites da peça para centralizá-la
                    FloatRect textBounds = piece.getLocalBounds();

                    // Calcular a posição centralizada
                    int xPosition = marginX + i * Tamanho_celula + (Tamanho_celula - textBounds.width) / 2 - textBounds.left;
                    int yPosition = j * Tamanho_celula + (Tamanho_celula - textBounds.height) / 2 - textBounds.top;

                    piece.setPosition(static_cast<float>(xPosition), static_cast<float>(yPosition));
                    window.draw(piece);
                }
            }
        }
        window.display();
    }
    return 0;
}