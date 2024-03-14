#include <stdio.h>
#include "listaex6.h"

int
main()
{
    int op, flag = 0, cont = 0;
    Lista L, L2, L4, L5;

    do{
        do{
            printf("\n------------------------\n");
            printf("[1]Criar uma lista\n");
            printf("[2]Esvaziar lista\n");
            printf("[3]Apagar lista\n");
            printf("[4]Inserir elemento\n");
            printf("[5]Inserir posição\n");
            printf("[6]Remover elemento\n");
            printf("[7]Remover menor\n");
            printf("[8]Remover ocorrência\n");
            printf("[9]Inverter lista\n");
            printf("[10]Imprimir\n");
            printf("[11]Sair\n");
            printf("\nDigite sua opção: ");
            scanf("%d", &op);
            getchar();

            if(op < 1 || op > 11)
                printf("Opção não válida\n");
        }while(op < 1 || op > 11);

        if(op == 11)
            break;
        else if(op != 1 && flag < 0){
            printf("\nA lista precisa ser criada!\n");
            continue;
        }
        switch (op){
            case 1: {      
                if(flag == 0){
                    if((L = cria_lista()) != NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else{
                        printf("\nLista criada 1 com sucesso\n");
                    }
                }
                if(flag == 1){
                    if((L2 = cria_lista()) == NULL){
                        printf("\nFalha na alocação\n");
                        return -1;
                    }
                    else
                        printf("\nLista criada 2 com sucesso\n");
                    cont = 0;
                }
                flag == 1;
                break;
            }
            case 2: {
                if(cont == 0){
                    if (esvazia_lista(&L) == 0){
                        printf("\nLista inexistente\n");
                    }
                    else{
                        printf("\n\nA lista %d foi esvaziada com sucesso\n", cont+1);
                    }
                }
                else{
                    if (esvazia_lista(&L2) == 0){
                        printf("\nLista inexistente\n");
                    }
                    else{
                        printf("\n\nA lista %d foi esvaziada com sucesso\n", cont+1);
                    }
                }
                break;
            }
            case 3: {
                if(cont == 0){
                    if (apaga_lista(&L) == 0) {
                        printf("\n\nLista não existe para ser apagada\n");
                    }
                    else{
                        printf("\n\nLista 1 apagada com sucesso\n");
                    }
                }
                else{
                    if (apaga_lista(&L2) == 0) {
                        printf("\n\nLista não existe para ser apagada\n");
                    }
                    else{
                        printf("\n\nLista 1 apagada com sucesso\n");
                        flag = 1;
                        cont = 0;
                    }
                }
                break;
            }
            case 4: {
                double elem;
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%lf", &elem);

                if(cont == 0){
                    if(insere_elem(&L, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %lf \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%lf<- foi incluido com sucesso\n", elem);
                    }
                }
                else{
                    if(insere_elem(&L2, elem) == 0) {
                        printf("\nA lista já está cheia\n");
                        printf("\nNão foi possivel incluir o elemento %lf \n", elem);
                    }
                    else{
                        printf("\nO elemento ->%lf<- foi incluido com sucesso\n", elem);
                    }
                }
                break;
            }
            case 5: {
                int pos;
                double elem;
                printf("\nDigite a posição desejada: ");
                scanf("%d", &pos);
                printf("\nDigite o elemento: ");
                scanf("%lf", &elem);

                if(cont == 0){
                    if(insere_pos(L, &pos, &elem) == 0)
                        printf("\nLista ou posição inexistente\n");
                    
                    else
                        printf("\nElemento ->%lf<- inserido na posição %d", elem, pos);
                }
                else{
                    if(insere_pos(L2, &pos, &elem) == 0)
                        printf("\nLista ou posição inexistente\n");
                    
                    else
                        printf("\nElemento ->%lf<- inserido na posição %d", elem, pos);
                }
                break;
            }
            case 6: {
                double elem;
                printf("\nDigite o elemento a ser removido: ");
                scanf("%lf", &elem);

                if(cont == 0){
                    if(remove_elem(&L, elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else
                        printf("\nElemento ->%lf<- retirado\n", elem);
                }
                else{
                    if(remove_elem(&L2, elem) == 0){
                        printf("\nLista vazia!\n");
                    }
                    else
                        printf("\nElemento ->%lf<- retirado\n", elem);
                }
                break;
            }
            case 7: {
                double elem;
                if(cont == 0){
                    if(remove_menor(&L, &elem) == 0)
                        printf("\nLista vazia!\n");
                    else
                        printf("\nO menor elemento é ->%lf<-\n", elem);
                }
                else{
                    if(remove_menor(&L2, &elem) == 0)
                        printf("\nLista vazia!\n");
                    else
                        printf("\nO menor elemento é ->%lf<-\n", elem);
                }
                break;
            }
            case 8: {
                double elem;
                printf("\nDigite a ocorrência a ser retirada: ");
                scanf("%lf", &elem);

                if(cont == 0){
                    if(remove_todos(&L, &elem) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\nLista vazia!\n");
                        else
                            printf("\nElemento ->%lf<- inexistente\n", elem);
                    }
                    else
                        printf("\nO(s) elemento(s) removido(s) foi (são) ->%lf<-", elem);
                }
                else{
                    if(remove_todos(&L2, &elem) == 0){
                        if(lista_vazia(L) == 1)
                            printf("\nLista vazia!\n");
                        else
                            printf("\nElemento ->%lf<- inexistente\n", elem);
                    }
                    else
                        printf("\nO(s) elemento(s) removido(s) foi (são) ->%lf<-", elem);
                }
                break;
            }
            case 9: {
                Lista L4 = cria_lista();
                Lista L5 = cria_lista();
                if(cont == 0){
                    if(inverter_lista(&L, &L4) == 0)
                        printf("\nLista vazia!");
                    else{
                        printf("\nLista invertida! ");
                        imprime_lista(L4);
                    }
                }
                else{
                    if(inverter_lista(&L2, &L5) == 0)
                        printf("\nLista vazia!");
                    else
                        imprime_lista(L5);
                }
                break;
            }
            case 10: {
                if(cont == 0){
                    imprime_lista(L);
                    printf("%d", tamanho_lista(&L));
                }
                else
                    imprime_lista(L2);
                break;
            }
        }
    }while(op != 11);

    printf("\nVolte sempre!\n");

	return 0;
}

/*
Operação: imprime_lista
    -Entrada: Uma lista.
    -Pré-condição: Lista existir
    -Processo: Imprime a lista.
    -Saída: nenhuma.
    -Pós-condição: nenhuma.
*/

void imprime_lista(Lista L){
    if(lista_vazia(L) == 1){
            printf("\n===LISTA VAZIA===\n");
    }
    else{
        printf("\nLista:");
        for (int i = 1; ; i++){
            double elem;
            if(get_elem_pos(L, i, &elem) == 0){
                break;
            }
            printf(" %lf ", elem);
        }
        printf("\n");
    }
}