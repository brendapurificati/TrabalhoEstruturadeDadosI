#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "Noticia.h"
#include "ListaCabCau.h"

typedef struct NoListaEncadeada {
    Noticia* info;
    struct NoListaEncadeada *prox;
} NoListaEncadeada;

int estaVaziaEncadeada(NoListaEncadeada **l);

void criarListaEncadeada(NoListaEncadeada **l);

void insereInicioEncadeada(NoListaEncadeada** l, Noticia* v);

void removerPorPalavraChaveEncadeada(NoListaEncadeada **l, char palavra[]);

void imprimirListaEncadeada(NoListaEncadeada **l);

#endif