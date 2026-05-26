#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Noticia* criarNoticia() {
    Noticia* Not1 = (Noticia*)malloc(sizeof(Noticia*));
}

typedef struct noticia {
    int id;
    char data[20];
    char titulo[50];
    char conteudo[150];
    char fonte[70];
    int classificacao;
} Noticia;