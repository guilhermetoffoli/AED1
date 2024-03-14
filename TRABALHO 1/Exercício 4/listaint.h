typedef struct no * Lista;

Lista cria_lista();
int insere_elem (Lista *, int );
int remove_elem (Lista *, int );
int lista_vazia(Lista );
int esvazia_lista(Lista *);
int apaga_lista(Lista *);
int get_elem_pos(Lista , int , int *);
void imprime_lista(Lista );
int tamanho_lista(Lista* );
int remover_maior(Lista *, int *);
int inverter_lista(Lista *, Lista *);
int intercalar_lista(Lista *, Lista *, Lista *);