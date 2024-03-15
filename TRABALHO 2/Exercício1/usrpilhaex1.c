#include <stdio.h>
#include "pilhaex1.h"

int
main()
{
    int op, n = 0, aux;
    char r;
    Pilha P = cria_pilha();

    do{

        printf("\n------------------------\n");
        printf("\nDigite um número inteiro: ");
        scanf("%d", &op);
        getchar();

        if (op < 0){
            break;
        }     

        printf("\n[B]Binário");
        printf("\n[O]Octal");
        printf("\n[H]Hexadecimal");
        printf("\n\nDigite sua conversão: ");
        scanf("%c", &r);       

        switch (r){
            case 'B':{

                printf("\nO numero %d em binario é: ", op);
                while(op != 0){
                    aux = op % 2;
                    push(&P, aux);
                    op = op / 2;
                }

                while(pilha_vazia(P) == 0){
                    pop(&P, &n);
                    printf("%d", n);
                }
                printf("\n");
                break;
            }
            case 'O':{
                printf("\nO numero %d em octal é: ", op);

                while ((op/8)!= 0){
                    aux = op%8;
                    push(&P,aux);
                    op = op/8;
                }             

                push(&P,op);

                while (pilha_vazia(P) == 0){
                    pop(&P,&n);
                    printf("%d",n);
                }
                printf("\n");
                break;
            }
            case 'H':{
                printf("\nO numero %d em hexadecimal é: ", op);
                
                while ((op/16)!= 0){
                    aux = op % 16;
                    push(&P, aux);
                    op = op/16;
                }

                push(&P, op);

                while (pilha_vazia(P) == 0){
                    pop(&P,&n);
                    switch (n){
                    case 10:
                        printf("A");
                        break;
                    case 11:
                        printf("B");
                        break;
                    case 12:
                        printf("C");
                        break;
                    case 13:
                        printf("D");
                        break;
                    case 14:
                        printf("E");
                        break;
                    case 15:
                        printf("F");
                        break;
                    default:
                        printf("%d",n);
                        break;
                    }
                }
                printf("\n");
                break;
            }    
        }
        aux = 0;
    }while(op >= 0);

    printf("\nVolte sempre!\n");
    
    apaga_pilha(&P);

	return 0;
}
