#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCabCau.h"
#include "Noticia.h"

int criarID() {
    static int id = 0;
    return ++id;
}

void imprimirNoticia(Noticia *not) {
    printf("Id: %d\n", not->id);
    printf("Classificacao: %d\n", not->classificacao);
    printf("Data: %s\n", not->data);
    printf("Titulo: %s\n", not->titulo);
    printf("Conteudo: %s\n", not->conteudo);
    printf("Fonte: %s\n", not->fonte);
}

Noticia* criarNoticia() {

    Noticia* Not1 = (Noticia*)malloc(sizeof(Noticia));
    printf("Digite a data de publicacao da noticia: ");
    scanf("%s", Not1->data);
    getchar();
    printf("Digite o titulo da publicacao: ");
    scanf("%s", Not1->titulo);
    getchar();
    printf("Digite o conteudo da publicacao: ");
    scanf("%s", Not1->conteudo);
    getchar();
    printf("Digite a fonte da publicacao: ");
    scanf("%s", Not1->fonte);
    getchar();
    Not1->classificacao = EmAnalise;
    Not1->id = criarID();

    return Not1;
}

void liberarNoticia(Noticia *not) {
    free(not);
}