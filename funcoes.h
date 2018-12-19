


typedef struct lista Lista;



Lista* lst_cria();


Lista* lst_insere(Lista* l, int i,int id);

void lst_imprime(Lista* l);

void lst_imprime_mem(Lista* l);


int lst_vazia(Lista* l);


Lista* lst_busca(Lista* l, int valor);


Lista* lst_retira(Lista* l, int valor);


void lst_libera(Lista* l);

void alocar_best(Lista* progs,Lista* mem);

void alocar_best_average(Lista* progs,Lista* mem);  

Lista* copia(Lista* mem);

