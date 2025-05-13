#include <stdio.h>

int main(){

    char linha[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10]={0};

    tabuleiro[2][3]= 3; //D3
    tabuleiro[2][4]= 3; //E3
    tabuleiro[2][5]= 3; //F3

    //Cabeçalho de 'A' á 'J'.
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]);
    }
        printf("\n");
     
        //Coluna de '1' á '10'.
    for ( int i = 0; i < 10; i++)
    
    {  printf("%d ", i+1); //Návio.
        for (int j = 0; j < 10; j++)
    {
        printf("%d ", tabuleiro[i][j]); //Água
    }
    
        printf("\n");
    }
    
    return 0;
}
