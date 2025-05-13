#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3  // Valor que representa o navio no tabuleiro

//  Funções de posicionamento 

// Posição Horizontal: linha fixa, coluna aumenta
void posicionarHorizontal(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int col_inicio) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha][col_inicio + i] = NAVIO;
    }
}

// Posição Vertical: coluna fixa, linha aumenta
void posicionarVertical(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int coluna) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_inicio + i][coluna] = NAVIO;
    }
}

// Diagonal para a direita  (linha e coluna aumentam)
void posicionarDiagonalDireita(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int col_inicio) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_inicio + i][col_inicio + i] = NAVIO;
    }
}

// Diagonal para a esquerda  (linha aumenta, coluna diminui)
void posicionarDiagonalEsquerda(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicio, int col_inicio) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_inicio + i][col_inicio - i] = NAVIO;
    }
}

//  Função principal 
int main() {
    int tabuleiro[TABULEIRO][TABULEIRO];

    // Inicializar com água (0)
    for (int i = 0; i < TABULEIRO; i++)
        for (int j = 0; j < TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    //  Coordenadas dos navios 

    // Horizontal em D5, D6, D7 → linha 3, coluna 4
    posicionarHorizontal(tabuleiro, 3, 4);

    // Vertical em G9, H9, I9 → linha 6, coluna 8
    posicionarVertical(tabuleiro, 6, 8);

    // Diagonal esquerda
    posicionarDiagonalEsquerda(tabuleiro, 1, 3);

    // Diagonal direita
    posicionarDiagonalDireita(tabuleiro, 5, 0);

    //  Exibir Cabeçalho de colunas 
    printf("  ");
    for (int col = 1; col <= TABULEIRO; col++)
        printf("%2d ", col);
    printf("\n");

    //  Exibir o Tabuleiro 
    for (int i = 0; i < TABULEIRO; i++) {
        printf("%c  ", 'A' + i);  // Letras das linhas

        for (int j = 0; j < TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0  ");  // Água
            else
                printf("3  ");  // Parte do navio
        }
        printf("\n");
    }

    return 0;
}
