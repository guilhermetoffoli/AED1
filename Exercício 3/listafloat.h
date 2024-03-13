typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista );
int insere_ord (Lista *, float );
int remove_ord (Lista *, float );
int esvazia_lista(Lista *);
int apaga_lista(Lista *);
int get_elem_pos(Lista , int , float *);
void imprime_lista(Lista L);
int comparar_lista(Lista *, Lista *);
int remover_pos(Lista *, int *, float *);
int tamanho_lista(Lista *);
int intercalar_lista(Lista , Lista , Lista );
int insere_inter(Lista *, float );