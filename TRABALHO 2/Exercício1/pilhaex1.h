typedef struct no * Pilha;

Pilha cria_pilha ();
int pilha_vazia (Pilha );
int esvazia_pilha(Pilha *);
int apaga_pilha(Pilha *);
int push (Pilha *, int );
int pop (Pilha *, int *);
int le_topo (Pilha *, int *);
void imprime_pilha(Pilha );