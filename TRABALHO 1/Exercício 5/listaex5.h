typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista );
int apaga_lista(Lista *);
int insere_final(Lista *, int );
int insere_inicio(Lista *, int *);
int insere_pos(Lista *, int *, int *);
int remove_inicio(Lista *, int *);
int remove_final(Lista *, int *);
int remove_par(Lista *, int *);
int esvazia_lista(Lista *);
int get_elem_pos(Lista , int , int *);
void imprime_lista(Lista );
int tamanho_lista(Lista* );