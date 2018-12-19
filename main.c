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
	int i,op,op2,v;
    srand(time(NULL));
    
    mem = lst_cria();
    progs = lst_cria();
    
	mem =  lst_insere(mem, 3,1);
  	mem =  lst_insere(mem, 5,2);
  	mem =  lst_insere(mem, 10,3);
  	mem =  lst_insere(mem, 8,4);
  	mem =  lst_insere(mem, 15,5);
  	mem =  lst_insere(mem, 13,6);
 	
	lst_imprime_mem(mem);
  	printf("\nEscolha uma opção:\n1- Best\n2- Best-Average\n");
   	scanf("%d",&op);
   		
   	printf("\nEscolha uma opção:\n1- Definir tamanho dos programas\n2- Tamanho aleatório dos programas\n");
   	scanf("%d",&op2);
   		
	if(op!=3){
		switch(op2){
			case 1: printf("\nQuantos programas? ");
					scanf("%d",&prog);
					for(i=0;i<prog;i++){
						printf("\nValor programa %d: ",i+1);
						scanf("%d",&v);
						progs = lst_insere(progs,v,i+1);
					}
					printf("\nProgramas:\n");
					lst_imprime(progs);
					break;
			
			case 2: printf("\nQuantos programas? ");
					scanf("%d",&prog);
					for(i=0;i<prog;i++){
						v = (rand()%14)+1;
						progs = lst_insere(progs,v,i+1);
					}	
					printf("\nProgramas:\n");
					lst_imprime(progs);
					break;
		}
	}
	switch(op){
		case 1: alocar_best(progs,mem);break;
			
		case 2: alocar_best_average(progs,mem);break;
			
		default: printf("Opção inválida!\n");
	}
	free(mem);
	free(progs);
	return 0;
}
