#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

int estaVazia(Lista *l) {
    if (l->cab == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void criarLista(Lista *l) {
    l->cab = NULL;
    l->cau = NULL;
}

void inserirElementoInicio(Lista *l, Noticia v) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo == NULL) {
        printf("testealalala");
    }
    novo->noticia = v;
    novo->prox = l->cab;
    l->cab = novo;
    if (l->cau == NULL) {
        l->cau = novo;
    }
}

void imprimirListaNoticia(Lista *l) {
    if (!estaVazia(l)) {
        NoLista *p;
        for (p = l->cab; p != NULL; p = p->prox) {
            imprimirNoticia(&p->noticia);
        }
    }
    else {
        printf("Lista de notícias vazia!");
    }
}