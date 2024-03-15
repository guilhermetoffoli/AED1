#include <time.h>

typedef struct fila *Fila;

#define MAX 5
#define BOX 3
#define STR 9

struct carro{
    char placa[STR], servico;
    time_t hora;
};

typedef struct carro Carro;

Fila cria_fila();
int fila_vazia(Fila );
int fila_cheia(Fila );
int esvazia_fila(Fila );
int apaga_fila(Fila *);
int insere_fim(Fila , Carro );
int remove_ini(Fila , Carro *);
int tamanho_fila(Fila );