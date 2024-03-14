typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista );
int apaga_lista(Lista *);
int insere_elem(Lista *, double );
int remove_elem(Lista *, double );
int esvazia_lista(Lista *);
int get_elem_pos(Lista , int , double *);
void imprime_lista(Lista );
int insere_pos(Lista , int *, double *);
int tamanho_lista(Lista* );
int remove_menor(Lista *, double *);
int remove_todos(Lista *, double *);
int inverter_lista(Lista *, Lista *);