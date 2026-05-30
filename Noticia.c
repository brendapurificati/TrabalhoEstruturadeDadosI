#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCabCau.h"
#include "Noticia.h"

void limparTerminal() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

int criarID() {
    static int id = 0;
    return ++id;
}

void imprimirNoticia(Noticia *not) {
    if (not != NULL) {
        printf("Id: %d\n", not->id);
        printf("Classificacao: %d\n", not->classificacao);
        printf("Data: %s", not->data);
        printf("Titulo: %s", not->titulo);
        printf("Conteudo: %s", not->conteudo);
        printf("Fonte: %s", not->fonte);
    }
        else {
            printf("Está vazia");
        }
}

Noticia* criarNoticia() {

    Noticia* Not1 = (Noticia*)malloc(sizeof(Noticia));
    printf("Digite a data de publicacao da noticia: ");
    fgets(Not1->data, sizeof(Not1->data), stdin);
    printf("Digite o titulo da publicacao: ");
    fgets(Not1->titulo, sizeof(Not1->titulo), stdin);
    printf("Digite o conteudo da publicacao: ");
    fgets(Not1->conteudo, sizeof(Not1->conteudo), stdin);
    printf("Digite a fonte da publicacao: ");
    fgets(Not1->fonte, sizeof(Not1->fonte), stdin);
    Not1->classificacao = EmAnalise;
    Not1->id = criarID();

    return Not1;
}

void liberarNoticia(Noticia *not) {
    free(not);
}