#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define max 20

typedef struct no *Fila;

struct pessoa{
    char nome[max];
    int idade;
    float peso;
    float altura;
    char doenca;
    int gravidade;
};

typedef struct pessoa Pessoa;

Fila cria_fila ();
int fila_vazia (Fila);
int insere_fim (Fila *, Pessoa);
int remove_ord (Fila *, Pessoa *);
int esvazia_fila (Fila *);
int apaga_fila (Fila *);
int get_elem_pos (Fila, int, Pessoa *);

#endif 