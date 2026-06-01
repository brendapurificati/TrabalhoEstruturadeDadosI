#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

int opcao;
char palavra[50];

void menu() {
    
    limparTerminal();
    printf("---------------------[ MENU ]---------------------\n");
    printf("| 1 - Adicionar nova noticia\n");
    printf("| 2 - Remover noticia pendente por ID\n");
    printf("| 3 - Remover noticia verificada por palavra-chave\n");
    printf("| 4 - Buscar noticia pendente por palavra-chave\n");
    printf("| 5 - Imprimir noticias\n");
    printf("| 6 - Classificar noticia\n");
    printf("| 7 - Imprimir quantidade de noticias por categoria\n");
    printf("| 8 - Sair\n");
    printf("|-------------------------------------------------\n");
    printf("| Digite a opcao desejada: ");
}

void pausa() {
    printf("| Pressione enter para continuar...");
    while (getchar() != '\n');
    getchar();       
}

int main() {

    // criação das duas listas
    ListaCabCau listaCabCau1;
    criarListaCabCau(&listaCabCau1);
    NoListaEncadeada *listaEncadeada1;
    criarListaEncadeada(&listaEncadeada1);

    do {
    menu();
    scanf("%d", &opcao);
    getchar(); 
    limparTerminal();

    switch (opcao) {
        case 1:
            Noticia* novaNoticia = criarNoticia();
            inserirInicioCabCau(&listaCabCau1, *novaNoticia);
            printf("| Noticia criada com ID: %d\n", novaNoticia->id);
            imprimirNoticia(novaNoticia);
            pausa();
            break;
        case 2:
            imprimirListaCabCau(&listaCabCau1);
            printf("| Digite o ID da noticia que deseja remover: \n");
            int id;
            scanf("%d", &id);
            removerPorIdCabCau(&listaCabCau1, id);
            printf("| Noticia removida com sucesso!\n");
            pausa();
            break;
        case 3:
            imprimirListaEncadeada(listaEncadeada1);
            printf("| Digite a palavra-chave para remover noticia verificada: \n");
            scanf("%s", palavra);
            removerPorPalavraChaveEncadeada(&listaEncadeada1, palavra);
            printf("| Noticia removida com sucesso!\n");
            pausa();
            break;
        case 4:
            printf("| Digite a palavra-chave para buscar noticia pendente: \n");
            scanf("%s", palavra);
            buscarPalavraChaveCabCau(&listaCabCau1, palavra);
            pausa();
            break;
        case 5:
            printf("| Digite 1 para imprimir noticias pendentes, 2 para imprimir noticias verificadas e 3 para ambas: \n");
            int tipo;
            scanf("%d", &tipo);
            if (tipo == 1) {
                printf("| Noticias pendentes:\n");
                imprimirListaCabCau(&listaCabCau1);
                pausa();
            }
            else if (tipo == 2) {
                printf("| Noticias verificadas:\n");
                imprimirListaEncadeada(listaEncadeada1);
                pausa();
            }
            else if (tipo == 3) {
                printf("| Todas as noticias:\n");
                printf("| Noticias pendentes:\n");
                imprimirListaCabCau(&listaCabCau1);
                printf("| Noticias verificadas:\n");
                imprimirListaEncadeada(listaEncadeada1);
                pausa();
            }
            else {
                printf("| Opcao invalida. Tente novamente.\n");
                pausa();
            }
            break;
        case 6:
            ClassificarNoticia(&listaCabCau1, &listaEncadeada1);
            pausa();
            break;
        case 7:
            retornarQuantidadeNoticiasCabCau(&listaCabCau1);
            retornarQuantidadeSuspeitas(listaEncadeada1);
            retornarQuantidadeConfiaveis(listaEncadeada1);
            pausa();
            break;
        case 8:
            printf("| Saindo do programa. . .\n");
            break;
        default:
            printf("| Opcao invalida. Tente novamente.\n");
            pausa();
    }

    } while (opcao != 8);

    return 0;
}