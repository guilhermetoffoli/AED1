typedef struct pilha * Pilhachar;

Pilhachar cria_pilha_char();
int pilha_vazia_char(Pilhachar );
int pilha_cheia_char(Pilhachar );
int esvazia_lista_char(Pilhachar );
int apaga_lista_char(Pilhachar *);
int push_char(Pilhachar , char );
int pop_char(Pilhachar , char *);
int le_topo_char (Pilhachar , char *);
void imprime_pilha(Pilhachar );

typedef struct no * Pilhareal;

Pilhareal cria_pilha_real ();
int pilha_vazia_real (Pilhareal );
int esvazia_pilha_real(Pilhareal *);
int apaga_pilha_real(Pilhareal *);
int push_real (Pilhareal *, float );
int pop_real (Pilhareal *, float *);
int le_topo_real (Pilhareal *, float *);