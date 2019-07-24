#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "movimentos.h"
Estado* CriarEstado(int mov, int game[3][3]){
    Estado * state;
    state = (Estado *) malloc(sizeof(Estado));
    state->movimento = mov;
  switch(mov){
    case 1:
    KEY_UP(game);
    break;
 
    case 2:
    KEY_LEFT(game);
    break;
 
    case 3:
    KEY_DOWN(game);
    break;
 
    case 4:
    KEY_RIGHT(game);
    break;
  }
  for(int i = 0; i<3; i++){
    for(int j=0; j<3; j++){
        state->game[i][j] = game[i][j];
    }
  }
  return state;
}
 
int DistanciaManhattan(Estado *estado_atual){
  //retorna a soma de todas as distâncias de cada posiçao pro tabuleiro
  int lin, col, auxrandomcol, auxrandomlin, manhattan[3][3], distanciafinal=0, aux[3][3]={
    {1,2,3},
    {4,5,6},
    {7,8,0}
  };
  //calculo da distancia de manhattan
  for(lin=0; lin<3; lin++){
      for(col=0; col<3; col++){
          for(auxrandomlin=0; auxrandomlin<3; auxrandomlin++){
              for (auxrandomcol=0;auxrandomcol<3;auxrandomcol++){
                  if (estado_atual->game[lin][col]==aux[auxrandomlin][auxrandomcol]){ //|x1-x2| + |y1-y2|
                      manhattan[lin][col]= abs((lin-auxrandomlin)) + abs((col-auxrandomcol));
                      printf("posatual[%d][%d]=posaux[%d][%d] --> manhattan=%d (distancia de manhattan)\n",lin,col,auxrandomlin,auxrandomcol,manhattan[lin][col]);
                    }
                }
            }
        }
    }
  for (lin=0;lin<3;lin++){
      for (col=0;col<3;col++){
          distanciafinal+=manhattan[lin][col];
        }
    }
  return distanciafinal;
}
 
int CompararEstados(Estado *estado1, Estado *estado2){
  //Retorna 0 se as matrizes não forem iguais, 1 caso contrário
  int lin, col;
    for(lin=0; lin<3; lin++){
        for(col=0; col<3; col++){
            if(estado1->game[lin][col] != estado2->game[lin][col]){
                return 0;
            }
        }
    }
  return 1;
}
 
int Ganhou_QuestionMark(matriz[3][3]){ //retorna 1 se o usuario ganhou e 0 se nao
    int aux=1, i, j, comp[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            comp[i][j]=aux;
            aux++;
            if(i==2&j==2){
                comp[i][j]=0;
            }
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(matriz[i][j]!=comp[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
