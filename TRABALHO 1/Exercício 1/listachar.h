typedef struct lista *Lista; 

#define MAX 10

Lista cria_lista();
int lista_vazia(Lista );
int lista_cheia(Lista );
int insere_ord(Lista , char );
int remove_ord(Lista , char );
int apaga_lista(Lista *);
int esvazia_lista(Lista );
int get_elem_pos(Lista , int , char *);
void imprime_lista(Lista );
int tamanho_lista(Lista , int *);
int remover_pos(Lista , int );
int remove_vogal(Lista );
int intercalar_lista (Lista L, Lista L2, Lista L3);
int get_elem_pos_inter(Lista , int , char *);