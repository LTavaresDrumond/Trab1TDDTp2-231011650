
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa velha", "[single-file]") {
    int teste1[3][3] = {
        {2, 0, 1},
        {2, 0, 1},
        {0, 2, 1}
    };
    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Testa vitoria do O", "[single-file]") {
    int teste2[3][3] = {
        {1, 2, 0},
        {1, 2, 0},
        {0, 2, 1}
    };
    REQUIRE(VerificaVelha(teste2) == 2);
}

TEST_CASE("Testa empate", "[single-file]") {
    int teste3[3][3] = {
        {1, 2, 1},
        {2, 1, 2},
        {2, 1, 2}
    };
    REQUIRE(VerificaVelha(teste3) == 0);
}

TEST_CASE("Testa partida indefinida", "[single-file]") {
    int teste4[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(VerificaVelha(teste4) == -1);
}


