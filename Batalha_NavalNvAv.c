#include <stdio.h>

int main(){

    char linha[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10]={0};


    tabuleiro[2][3]= 3; //D3
    tabuleiro[2][4]= 3; //E3
    tabuleiro[2][5]= 3; //F3

    tabuleiro[0][0]= 3; //A1
    tabuleiro[1][0]= 3; //A2
    tabuleiro[2][0]= 3; //A3

    tabuleiro[6][8]= 3; //I7
    tabuleiro[7][7]= 3; //H8
    tabuleiro[8][6]= 3; //G9

    tabuleiro[6][1]= 3; //B7
    tabuleiro[7][2]= 3; //C8
    tabuleiro[8][3]= 3; //D0

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
    { if (tabuleiro[i][j] ==1)
    {
        printf("3 ");
    } else {
        printf("%d ", tabuleiro[i][j]);
    }
    
    }
    
        printf("\n");
    }
    
    return 0;
}
