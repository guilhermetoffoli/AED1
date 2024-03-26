typedef struct complexo nmro;

nmro * cria_nro();
int get_nro(nmro *n, int *, int *);
void libera_nro(nmro **);
nmro * mult(nmro *, nmro *);
int set_nro(nmro *, int , int);
nmro * soma(nmro *, nmro *);
nmro * sub(nmro *, nmro *);
