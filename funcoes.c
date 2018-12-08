
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

struct lista {		
	int info;
	int id;
	struct lista* prox;
};

Lista* lst_cria() {
	return NULL;	
}

Lista* lst_insere(Lista* l, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	if( novo == NULL ) {							
		printf("Memoria insuficiente!\n");			
		exit(1);
	}
	novo->info = i;									
	novo->prox = l;
	novo->id = 0;									
	return novo;								
}

void lst_imprime(Lista* l) {
	Lista* aux;	
	int i =1;								
	for(aux = l; aux != NULL; aux = aux->prox) {
		printf("Prog %2.d | %2.d\n",i,aux->info);
		i++;
	}
	printf("\n");
}

void lst_imprime_mem(Lista* l) {
	Lista* aux;	
	   	printf("  Memoria \n");								
	for(aux = l; aux != NULL; aux = aux->prox) {	
		printf("%2.d ", aux->info);	
		if(l->id == 0){
			printf(" | Livre \n");	
		}
	    else{
	    		printf(" | Prog %d\n",aux->info);
		}
	}
	printf("\n");
}

int lst_vazia(Lista* l) {
	if( l == NULL )									
		return 1;									
	else
		return 0;									
}

Lista* lst_busca(Lista* l, int valor) {
	Lista* p;										
	for(p = l; p != NULL; p = p->prox)				
		if( p->info == valor )					
			return p;								
	return NULL;							
}

Lista* lst_retira(Lista* l, int valor) {
	Lista* ant = NULL;							
	Lista* p = l;								
	
	while(p != NULL && p->info != valor) {			
		ant = p;									
		p = p->prox;							
	}
	
	if( p == NULL )								
		return l;									
		
	if( ant == NULL )							
		l = p->prox;								 
	else											
		ant->prox = p->prox;						
		
	free(p);										
	return l;									
}

void lst_libera(Lista* l) {
	Lista* p = l;								
	while( p!=NULL ) {							
		Lista* t = p->prox;							
		free(p);										
		p = t;											
	}
}

void alocar(Lista* progs,Lista* mem, int prog){
	Lista* auxp;
	Lista* auxm;
	int i = 1,best=15,resto,aux,en=0;
	for(auxp = progs;progs != NULL; auxp=auxp->prox){
		printf("Alocando programa %2.d:\n",i);
		for(auxm = mem; auxm!=NULL; auxm = auxm->prox){
			aux = auxm->info - auxp->info;
			if(aux <=best&& aux >=0){
				resto = aux;
				best = auxm->info;
				en = 1;
			}
		}
		for(auxm = mem;auxm!=NULL;auxm=auxm->prox){
			if(auxm->info == best && en==1){
				auxm->info = auxp->info;
				auxm->id = 1;
				Lista* novo = (Lista*) malloc(sizeof(Lista));
				novo->info = resto;
				novo->prox = auxm->prox;
				auxm->prox = novo;
				novo->id = 0;
				break;
			}
		}
		lst_imprime_mem(auxm);
		i++;
	}
}

