#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3

// Tipos de habilidades (cada número representa uma bomba diferente)

#define BOMBA_CONE 1
#define BOMBA_CRUZ 2
#define BOMBA_OCTAEDRO 3

void posicionarHorizontal(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int col_inicio) {
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linha][col_inicio + i] = NAVIO;
}

void posicionarVertical(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int coluna) {
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linha_inicio + i][coluna] = NAVIO;
}

void posicionarDiagonalDireita(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int col_inicio) {
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linha_inicio + i][col_inicio + i] = NAVIO;
}

void posicionarDiagonalEsquerda(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int col_inicio) {
    for (int i = 0; i < NAVIO; i++)
        tabuleiro[linha_inicio + i][col_inicio - i] = NAVIO;
}

// Função para aplicar uma habilidade no tabuleiro de bombas

void aplicarHabilidade(int tabuleiro_bombas[TABULEIRO][TABULEIRO], int forma[5][5], int linha_centro, int coluna_centro, int tipo_bomba) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (forma[i][j] == 1) {
                int linha = linha_centro - 2 + i;
                int coluna = coluna_centro - 2 + j;
                if (linha >= 0 && linha < TABULEIRO && coluna >= 0 && coluna < TABULEIRO) {
                    tabuleiro_bombas[linha][coluna] = tipo_bomba;
                }
            }
        }
    }
}

int main() {
    int tabuleiro_navios[TABULEIRO][TABULEIRO] = {0};
    int tabuleiro_bombas[TABULEIRO][TABULEIRO] = {0};

    // Posicionar navios

    posicionarHorizontal(tabuleiro_navios, 0, 3);
    posicionarVertical(tabuleiro_navios, 6, 8);
    posicionarDiagonalEsquerda(tabuleiro_navios, 1, 3);
    posicionarDiagonalDireita(tabuleiro_navios, 5, 0);

    // Formas das habilidades
    
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar habilidades (em posições diferentes)
    
    aplicarHabilidade(tabuleiro_bombas, cone, 2, 7, BOMBA_CONE);
    aplicarHabilidade(tabuleiro_bombas, cruz, 5, 5, BOMBA_CRUZ);
    aplicarHabilidade(tabuleiro_bombas, octaedro, 8, 2, BOMBA_OCTAEDRO);

    // Cabeçalho
    
    printf("  ");
    for (int col = 1; col <= TABULEIRO; col++)
        printf("%2d ", col);
    printf("\n");

    // Impressão do tabuleiro
    for (int i = 0; i < TABULEIRO; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TABULEIRO; j++) {
            if (tabuleiro_navios[i][j] == NAVIO && tabuleiro_bombas[i][j] != 0) {
                printf("X  "); // Navio atingido (visual, mas sem efeito real)
            } else if (tabuleiro_navios[i][j] == NAVIO) {
                printf("3  "); // Navio
            } else if (tabuleiro_bombas[i][j] == BOMBA_CONE) {
                printf("C  "); // Cone
            } else if (tabuleiro_bombas[i][j] == BOMBA_CRUZ) {
                printf("+  "); // Cruz
            } else if (tabuleiro_bombas[i][j] == BOMBA_OCTAEDRO) {
                printf("O  "); // Octaedro
            } else {
                printf("0  "); // Água
            }
        }
        printf("\n");
    }

    return 0;
}
