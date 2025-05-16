#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 10  // Tamanho do tabuleiro
#define H 5   // Tamanho da matriz de habilidade

// Inicializa o tabuleiro com água (0) e navios aleatórios (3)
void initTab(int tab[T][T]) {
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            tab[i][j] = rand() % 5 ? 0 : 3;
}

// Cria matriz de habilidade do tipo especificado
void criarHabilidade(int hab[H][H], char tipo) {
    int c = H/2; // Centro
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            bool cond;
            switch(tipo) {
                case 'C': cond = (j >= c-i/2 && j <= c+i/2 && i <= c+1); break; // Cone
                case 'X': cond = (i == c || j == c); break; // Cruz
                case 'O': cond = (abs(i-c) + abs(j-c) <= c); break; // Octaedro
                default: cond = false;
            }
            hab[i][j] = cond ? 1 : 0;
        }
    }
}

// Aplica habilidade no tabuleiro
void aplicarHab(int tab[T][T], int hab[H][H], int x, int y) {
    int o = H/2; // Offset
    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            if (hab[i][j] && x-o+i >= 0 && x-o+i < T && y-o+j >= 0 && y-o+j < T)
                tab[x-o+i][y-o+j] = 5;
}

// Exibe o tabuleiro
void showTab(int tab[T][T]) {
    printf("\n");
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++)
            printf("%c ", "~N*?"[tab[i][j]]);
        printf("\n");
    }
}

int main() {
    int tab[T][T], hab[H][H];
    
    initTab(tab);
    printf("Tabuleiro inicial:");
    showTab(tab);
    
    criarHabilidade(hab, 'C');
    aplicarHab(tab, hab, 2, 2);
    printf("\nCom Habilidade Cone (2,2):");
    showTab(tab);
    
    criarHabilidade(hab, 'X');
    aplicarHab(tab, hab, 5, 5);
    printf("\nCom Habilidade Cruz (5,5):");
    showTab(tab);
    
    criarHabilidade(hab, 'O');
    aplicarHab(tab, hab, 7, 7);
    printf("\nCom Habilidade Octaedro (7,7):");
    showTab(tab);
    
    return 0;
}