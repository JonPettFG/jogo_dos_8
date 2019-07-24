#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "grafo.h"
no* primeiro_no(Estado * estado_atual){
	no * primeiro_no = (no*) malloc(sizeof(no));
	primeiro_no->profundidade = 0;
	primeiro_no->distancia_manhattan = DistanciaManhattan(estado_atual);
	primeiro_no->pai = NULL;
	primeiro_no->filho = NULL;
	return primeiro_no;
}
no* a_star(no * no_atual){
	if(no_atual->distancia_manhattan == 0){
		return no_atual;
	}
	else{
		no* novo = (no*) malloc(sizeof(no));
		//Criar estados, avaliar custos, novo nó com o estado com menor distancia de manhattan e chamar novamente o A_star com o novo nó
		Estado* temp[4];
		Estado* estado_otimizado;
		temp = (Estado *) malloc(4*sizeof(Estado));
		estado_otimizado = (Estado *) malloc(sizeof(Estado));
		temp[0] = CriarEstado(1, no_atual->estado_atual->game);
		temp[1] = CriarEstado(2, no_atual->estado_atual->game);
		temp[2] = CriarEstado(3, no_atual->estado_atual->game);
		temp[3] = CriarEstado(4, no_atual->estado_atual->game);
		//DistManhattan a seguir
		int distancias[4], min, pos;
		pos = 0;
		min = distancias[0];
		for(int g=0; g<4; g++){
			distancias[g] = DistanciaManhattan(temp[g]);
		}
		for(int i=0; i<4; i++){
			if(distancias[i]<min){
				pos++;
			}
		}
		estado_otimizado = temp[pos];
		//A Star com o nó com menor DistManhattan
		no_atual->filho = novo;
		novo->estado_atual = estado_otimizado;
		novo->distancia_manhattan = DistanciaManhattan(estado_otimizado);
		novo->profundidade = no_atual->profundidade +1;
		//Limpeza de memória
		free(temp);
		free(estado_otimizado);
		novo->filho = a_star(novo);
	}
}
