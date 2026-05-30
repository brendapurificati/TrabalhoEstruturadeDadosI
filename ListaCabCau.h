#ifndef LISTACABCAU_H
#define LISTACABCAU_H
#include "Noticia.h"

typedef struct noticia Noticia;

typedef struct Nolista {
    Noticia noticia;
    struct Nolista *prox;
} NoLista;

typedef struct lista {
    NoLista *cab, *cau;
} Lista;

int estaVazia(Lista *l);

void criarLista(Lista *l);

void inserirElementoInicio(Lista *l, Noticia v);

void imprimirListaNoticia(Lista *l);

Noticia* buscarPalavraChave(Lista *l, char palavra[]);

void removerPorPalavraChave(Lista *l, char palavra[]);

void removerPorId(Lista *l, int id);

#endif