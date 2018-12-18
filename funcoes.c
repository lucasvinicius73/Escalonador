
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

struct lista {		
	int info;
	int id;
	int est;
	struct lista* prox;
};

Lista* lst_cria() {
	return NULL;	
}

Lista* lst_insere(Lista* l, int i,int id) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	if( novo == NULL ) {							
		printf("Memoria insuficiente!\n");			
		exit(1);
	}
	novo->info = i;									
	novo->prox = l;
	novo->est = 0;
	novo->id = id;									
	return novo;								
}

void lst_imprime(Lista* l) {
	Lista* aux;	
	int i =1;								
	for(aux = l; aux != NULL; aux = aux->prox) {
		printf("Prog %2.d | %2.d ---- %d\n",i,aux->info,aux->id);
		i++;
	}
	printf("\n");
}

void lst_imprime_mem(Lista* l) {
	Lista* aux;	
	   	printf("  Memoria \n");								
	for(aux = l; aux != NULL; aux = aux->prox) {	
		printf("%2.d ", aux->info);	
		if(aux->est == 0){
			printf(" | Livre ---- %d\n",aux->id);	
		}
	    else{
	    		printf(" | ocupado ---- %d\n",aux->id);
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

void alocar_best(Lista* progs,Lista* mem){
	Lista* auxp;
	Lista* auxm;
	int i, best, resto, aux, en,ids,n=1;
	for(auxp = progs; auxp!=NULL; auxp = auxp->prox){
		best = 16;
		en = 0;
		ids=0;
		for(auxm = mem; auxm!=NULL; auxm = auxm->prox){
			if((auxm->info<best)&&(auxm->est==0)&&(auxm->info>=auxp->info)){
				best = auxm->info;
				aux = auxm->id;
				en = 1;
			}
			ids++;
		}
		if(en == 1){
			for(auxm = mem; auxm!=NULL;auxm = auxm->prox){
				if(auxm->id == aux){
					resto = auxm->info - auxp->info;
					if(resto>0){
						Lista* novo = (Lista*) malloc(sizeof(Lista));
						novo->prox = auxm->prox;
						novo->info = resto;
						novo->est = 0;
						novo->id = ids+1;
						auxm->prox = novo;
					}
					auxm->info = auxp->info;
					auxm->est = 1;
					break;
				}
			}
		}else{
			printf("\nMemória não disponível para o programa %d!!\n\n",n);
		}
		n++;
	}
}

void alocar_best_average(Lista* progs,Lista* mem){
	Lista* auxp;
	Lista* auxm;
	int i, best, resto, aux, en,ids,n=1,soma,media,q;
	for(auxp = progs; auxp!=NULL; auxp = auxp->prox){
		best = 16;
		en = 0;
		ids=0;
		for(auxm = mem; auxm!=NULL; auxm = auxm->prox){
			if((auxm->info<best)&&(auxm->est==0)&&(auxm->info>=auxp->info)){
				best = auxm->info;
				aux = auxm->id;
				en = 1;
			}
			ids++;
		}
		if(en == 1){
			for(auxm = mem; auxm!=NULL;auxm = auxm->prox){
				if(auxm->id == aux){
					resto = auxm->info - auxp->info;
					if(resto > 1 || resto == 0){
						if(resto>0){
							Lista* novo = (Lista*) malloc(sizeof(Lista));
							novo->prox = auxm->prox;
							novo->info = resto;
							novo->est = 0;
							novo->id = ids+1;
							auxm->prox = novo;
						}
						auxm->info = auxp->info;
						auxm->est = 1;
						break;
					}else{
						break;
					}
				}
			}
			printf("arroto\n\n");
			if(resto<1&&resto!=0){
				soma = 0;
				media = 0;
				q = 0;
				aux = 1;
				best = 0;
				for(auxm = mem; auxm!=NULL;auxm=auxm->prox){
					if((auxm->info <= auxp->info) && (auxm->est == 0)){
						soma += auxm->info;
						q++;
					}
				}
				printf("boboca\n\n");
				media = soma/q;
				for(auxm = mem; auxm!=NULL;auxm=auxm->prox){
					if((auxm->info <= auxp->info) && (auxm->est ==0)&&(auxm->info >= auxp->info)){
						if(aux == 1){
							best = abs(media - auxm->info);
							q = auxm->id;
						}else{
							if(abs(media - auxm->info)<best){
								best = abs(media - auxm->info);
								q = auxm->id;
							}
						}
					}else{
						printf("\nNão tem!!!\n");
					}
					aux++;
				}
				for(auxm = mem; auxm != NULL; auxm = auxm->prox){
					if(q == auxm->id){
						resto = auxm->info - auxp->info;
						if(resto>0){
						Lista* novo = (Lista*) malloc(sizeof(Lista));
						novo->prox = auxm->prox;
						novo->info = resto;
						novo->est = 0;
						novo->id = ids+1;
						auxm->prox = novo;
					}
					auxm->info = auxp->info;
					auxm->est = 1;
					break;
					}
				}
			}
		}else{
			printf("\nMemória não disponível para o programa %d!!\n\n",n);
		}
		n++;
	}
}
