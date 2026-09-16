/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param velha descreve o parametro
 *
 *  Descrever o que a funcao faz
 */

static bool TemVitoria(const int velha[3][3], int jogador) {
    for (int linha = 0; linha < 3; ++linha) {
        if (velha[linha][0] == jogador &&
            velha[linha][1] == jogador &&
            velha[linha][2] == jogador) {
            return true;
        }
    }

    for (int coluna = 0; coluna < 3; ++coluna) {
        if (velha[0][coluna] == jogador &&
            velha[1][coluna] == jogador &&
            velha[2][coluna] == jogador) {
            return true;
        }
    }

    return (velha[0][0] == jogador && velha[1][1] == jogador &&
            velha[2][2] == jogador) ||
           (velha[0][2] == jogador && velha[1][1] == jogador &&
            velha[2][0] == jogador);
}

int VerificaVelha(int velha[3][3]) {
    int quantidadeX = 0;
    int quantidadeO = 0;

    for (int linha = 0; linha < 3; ++linha) {
        for (int coluna = 0; coluna < 3; ++coluna) {
            if (velha[linha][coluna] == 1) {
                ++quantidadeX;
            } else if (velha[linha][coluna] == 2) {
                ++quantidadeO;
            } else if (velha[linha][coluna] != 0) {
                return -2;
            }
        }
    }

    if ((quantidadeX == 9 && quantidadeO == 0) ||
        (quantidadeO == 9 && quantidadeX == 0)) {
        return -2;
    }

    bool vitoriaX = TemVitoria(velha, 1);
    bool vitoriaO = TemVitoria(velha, 2);

    if (vitoriaX && vitoriaO) {
        return -2;
    }
    if (vitoriaX) {
        return 1;
    }
    if (vitoriaO) {
        return 2;
    }
    if (quantidadeX + quantidadeO == 9) {
        return 0;
    }
    return -1;
}



