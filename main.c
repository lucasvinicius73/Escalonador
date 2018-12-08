#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"
#include <conio.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int prog;
	Lista* mem;
	Lista* progs;
	int i=0;
    srand(time(NULL));
    
    mem = lst_cria();
    progs = lst_cria();
    
  mem =  lst_insere(mem, 3);
  mem =  lst_insere(mem, 5);
  mem =  lst_insere(mem, 10);
  mem =  lst_insere(mem, 10);
  mem =  lst_insere(mem, 15);
  mem =  lst_insere(mem, 15);
    
    lst_imprime_mem(mem);
    
  printf("Insira quantidades de Programas: ");
  scanf("%d",&prog);
    
    for(i; i < prog; i++){
    	int v = (rand()%14)+1;
    	progs = lst_insere(progs,v);
	}
	
	lst_imprime(progs);	
	
	alocar(progs,mem,prog);
	
	/*for(i=0;i<prog;i++){
		int best = 15;
		int aux1, resto;
		printf("Alocando programa %2.d: ",i+1);
		Lista* aux;
		for(aux=mem;aux!=NULL;aux=aux->prox){
			aux1 = aux->info - progs->info;
			if(aux1 < best && aux1 >= 0){
			  resto = aux1;
			  best = aux->info;
			 
			}
		}
		
	}*/

	return 0;
}
