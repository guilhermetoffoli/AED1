typedef struct lista *Lista; 

#define MAX 20
#define STR 10

struct lista{
    char no[MAX][STR];
    int fim;
};

struct bebida{
    char nome[MAX];
    int volume;
    float preco;
};


Lista cria_lista();
int lista_vazia(Lista );
int lista_cheia(Lista );
int insere_ord(Lista , char str[]);
int remove_ord(Lista , char str[]);
int apaga_lista(Lista * );
int esvazia_lista(Lista );
int get_elem_pos(Lista , int , char *str[]);
int imprime_lista(Lista );