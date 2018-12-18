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
	Lista* mem2;
	int i;
    srand(time(NULL));
    
    mem = lst_cria();
    mem2 = lst_cria();
    progs = lst_cria();
    
	mem =  lst_insere(mem, 3,1);
  	mem =  lst_insere(mem, 5,2);
  	mem =  lst_insere(mem, 10,3);
  	mem =  lst_insere(mem, 8,4);
  	mem =  lst_insere(mem, 15,5);
  	mem =  lst_insere(mem, 13,6);
    
    mem2 =  lst_insere(mem2, 3,1);
  	mem2 =  lst_insere(mem2, 5,2);
  	mem2 =  lst_insere(mem2, 10,3);
  	mem2 =  lst_insere(mem2, 8,4);
  	mem2 =  lst_insere(mem2, 15,5);
  	mem2 =  lst_insere(mem2, 13,6);
    
    
	lst_imprime_mem(mem);
    
   	printf("Insira quantidades de Programas: ");
  	scanf("%d",&prog);
    
    for(i=0; i < prog; i++){
    	int v = (rand()%14)+1;
    	progs = lst_insere(progs,v,i+1);
	}
	
	lst_imprime(progs);	
	
	alocar_best(progs,mem);
	alocar_best_average(progs,mem2);
	lst_imprime_mem(mem);
	printf("\n\n");
	lst_imprime_mem(mem2);


	return 0;
}
