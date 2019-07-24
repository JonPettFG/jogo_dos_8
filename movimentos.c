#include <stdio.h>
#include <stdlib.h>
#include "movimentos.h"

struct zeropos* zero_pos(int matriz[3][3]){
  struct zeropos pos_zero;
  struct zeropos *pointer=&pos_zero;
  int i, j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(matriz[i][j]==0){
        pos_zero.i=i;
        pos_zero.j=j;
      }
    }
  }
  return pointer;
}

int jogodos8resolvivel(int game[3][3]){
int i, j, k, l, naoseiseehresolvivel=0;
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(l=0;l<3;l++){
                    if(game[j][l]<game[k][i] && j>=k && game[j][l]!=0 && game[k][i]!=0){
                        naoseiseehresolvivel++;
                        if(j==k){
                            if(l<i)
                                naoseiseehresolvivel--;
                        }
                    }
                }
            }
        }
    }
    return naoseiseehresolvivel%2;
}


void KEY_DOWN(int matriz[3][3]){
  struct zeropos *zp;
  int temp, i, j;
  zp=zero_pos(matriz);
  if(zp->i==0){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    return;
  }
  temp=matriz[zp->i-1][zp->j];
  matriz[zp->i-1][zp->j]=0;
  matriz[zp->i][zp->j]=temp;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void KEY_UP(int matriz[3][3]){
  struct zeropos *zp;
  int temp, i, j;
  zp=zero_pos(matriz);
  if(zp->i==2){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    return;
  }
  temp=matriz[zp->i+1][zp->j];
  matriz[zp->i+1][zp->j]=0;
  matriz[zp->i][zp->j]=temp;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void KEY_RIGHT(int matriz[3][3]){
  struct zeropos *zp;
  int temp, i, j;
  zp=zero_pos(matriz);
  if(zp->j==0){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    return;
  }
  temp=matriz[zp->i][zp->j-1];
  matriz[zp->i][zp->j-1]=0;
  matriz[zp->i][zp->j]=temp;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void KEY_LEFT(int matriz[3][3]){
  struct zeropos *zp;
  int temp, i, j;
  zp=zero_pos(matriz);
  if(zp->j==2){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    return;
  }
  temp=matriz[zp->i][zp->j+1];
  matriz[zp->i][zp->j+1]=0;
  matriz[zp->i][zp->j]=temp;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}