#include <stdio.h>

#define TABULEIRO 10
#define navioH 3
#define navioV 3

// Função para posicionar navio horizontal

void posicionarHorizontal(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int col_inicio) {
    for (int i = 0; i < navioH; i++) {
        tabuleiro[linha][col_inicio + i] = navioV;
    }
}

// Função para posicionar navio vertical
void posicionarVertical(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int coluna) {
    for (int i = 0; i < navioH; i++) 
    {
    tabuleiro[linha_inicio + i][coluna] = navioV;
    }
    
}

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO];

    // Inicializar com água
    for (int i = 0; i < TABULEIRO; i++)
        for (int j = 0; j < TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    // Coordenadas dos navios
    int navioHorizontal[2] = {3, 4}; // Linha 3 (D), Coluna 4 (5)
    int navioVertical[2] = {6, 8};   // Linha 6 (G), Coluna 8 (9)

    // Posicionar navios usando funções
    posicionarHorizontal(tabuleiro, navioHorizontal[0], navioHorizontal[1]);
    posicionarVertical(tabuleiro, navioVertical[0], navioVertical[1]);

    // Cabeçalho de colunas
    printf("  ");
    for (int col = 1; col <= TABULEIRO; col++)
        printf("%2d ", col);
    printf("\n");

    // Mostrar tabuleiro com letras e símbolos
    for (int i = 0; i < TABULEIRO; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0  ");
            else if (tabuleiro[i][j] == navioV)
                printf("3  ");
        }
        printf("\n");
    }

    return 0;
}
