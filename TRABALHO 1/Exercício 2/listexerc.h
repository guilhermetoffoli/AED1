typedef struct lista *Lista; 

#define MAX 10
#define STR 15

struct lista{
    char no[MAX][STR];
    int fim;
};

Lista cria_lista();
int lista_vazia(Lista );
int lista_cheia(Lista );
int insere_elem(Lista , char str[]);
int remove_elem(Lista , char str[]);
int apaga_lista(Lista *);
int esvazia_lista(Lista );
int get_elem_pos(Lista , int , char str[]);
void imprime_lista(Lista );
int insere_pos(Lista , int , char str[]);
int concatenar_lista (Lista , Lista , Lista );
int tamanho_lista(Lista , int *);
int remove_menor(Lista , char menor[]);