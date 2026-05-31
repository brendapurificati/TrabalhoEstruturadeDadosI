#ifndef LISTACABCAU_H
#define LISTACABCAU_H
#include "Noticia.h"

typedef struct noticia Noticia;

typedef struct NoCabCau {
    Noticia info;
    struct NoCabCau *prox;
} NoCabCau;

typedef struct listacabcau {
    NoCabCau *cab, *cau;
} ListaCabCau;

int estaVaziaCabCau(ListaCabCau *l);

void criarListaCabCau(ListaCabCau *l);

void inserirInicioCabCau(ListaCabCau *l, Noticia v);

void imprimirListaCabCau(ListaCabCau *l);

Noticia* buscarPalavraChaveCabCau(ListaCabCau *l, char palavra[]);

void removerPorPalavraChaveCabCau(ListaCabCau *l, char palavra[]);

void removerPorIdCabCau(ListaCabCau *l, int id);

void retornarQuantidadeNoticiasCabCau(ListaCabCau *l);


#endif