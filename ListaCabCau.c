#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

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

// função em teste
Noticia* buscarPalavraChave(Lista *l, char palavra[]) {
    NoLista *p;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (strstr(p->noticia.titulo, palavra) || strstr(p->noticia.conteudo, palavra)) {
            return &p->noticia;
        }
    }
}

// função em teste
void removerPorPalavraChave(Lista *l, char palavra[]) {
    NoLista *p;
    NoLista* aux = NULL;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (strstr(p->noticia.titulo, palavra) || strstr(p->noticia.conteudo, palavra)) {
            if (aux == NULL) {
                liberarNoticia(p->noticia);
                l->cab = p->prox;
                if (l->cab == NULL) {
                    l->cau = NULL;
                }
            }
            else {
                aux->prox = p->prox;
                if (p == l->cau) {
                    l->cau = aux;
                }
            liberarNoticia(p->noticia);
            free(p);
            }
        aux = p;
        }
    }
}

// função em teste
void removerPorId(Lista *l, int id) {
    NoLista* p; 
    NoLista* aux = NULL;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (id == p->noticia.id) {
            if (aux == NULL) {
                liberarNoticia(p->noticia);
                l->cab = p->prox;
                if (l->cab == NULL) {
                    l->cau = NULL;
                }
            }
            else {
                aux->prox = p->prox;
                if (p == l->cau) {
                    l->cau = aux;
                }
            liberarNoticia(p->noticia);
            free(p);
            }
        }
        aux = p;
    }
}