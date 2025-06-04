#include <stdio.h>



// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {


    // criando o tabuleiro 10x10 e inicializando com 0 (água)
    
    
    int tabuleiro[10][10];
    int i, j;


    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // navios de tamanho 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // coordenadas iniciais dos navios
    char coluna_h = 'E'; // coluna do navio horizontal (letra)
    int linha_h = 3; // linha do navio horizontal (número)
    char coluna_v = 'B'; // coluna do navio vertical (letra)
    int linha_v = 7; // linha do navio vertical (número)

    // convertendo letra para índice
    int col_h_idx = coluna_h - 'A';
    int col_v_idx = coluna_v - 'A';
    int lin_h_idx = linha_h - 1;
    int lin_v_idx = linha_v - 1;

    // validando se os navios cabem no tabuleiro
    if(col_h_idx + 3 > 10) {
        printf("navio horizontal fora do tabuleiro\n");
        return 1;
    }
    if(lin_v_idx + 3 > 10) {
        printf("navio vertical fora do tabuleiro\n");
        return 1;
    }

    // validando sobreposição (simples)
    int sobreposicao = 0;
    for(i = 0; i < 3; i++) {
        if(lin_h_idx == lin_v_idx + i && col_h_idx <= col_v_idx && col_h_idx + 2 >= col_v_idx) {
            sobreposicao = 1;
        }
    }
    if(sobreposicao) {
        printf("navios sobrepostos\n");
        return 1;
    }

    // posicionando navio horizontal
    for(i = 0; i < 3; i++) {
        tabuleiro[lin_h_idx][col_h_idx + i] = navio_horizontal[i];
    }

    // posicionando navio vertical
    for(i = 0; i < 3; i++) {
        tabuleiro[lin_v_idx + i][col_v_idx] = navio_vertical[i];
    }

    // mostrando o tabuleiro com letras, números e uma borda ao redor da água
    // ajustando o espaçamento das letras para alinhar com as colunas
    printf("   ");
    for(j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");
    printf("   +");
    for(j = 0; j < 10; j++) {
        printf("--");
    }
    printf("+\n");
    for(i = 0; i < 10; i++) {
        printf("%2d |", i+1);
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("| %2d\n", i+1);
    }
    printf("   +");
    for(j = 0; j < 10; j++) {
        printf("--");
    }
    printf("+\n");
    printf("   ");
    for(j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n\n");

    // mostrando as coordenadas dos navios
    printf("coordenadas do navio horizontal: ");
    for(i = 0; i < 3; i++) {
        printf("%c%d ", coluna_h + i, linha_h);
    }
    printf("\n");
    printf("coordenadas do navio vertical: ");
    for(i = 0; i < 3; i++) {
        printf("%c%d ", coluna_v, linha_v + i);
    }
    printf("\n");

    return 0;
}