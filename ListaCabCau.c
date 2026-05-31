#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

// função que verifica se a lista está vazia
int estaVaziaCabCau(ListaCabCau *l) {
    if (l->cab == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// cria a lista inicializando os ponteiros de cabeça e cauda como NULL
void criarListaCabCau(ListaCabCau *l) {
    l->cab = NULL;
    l->cau = NULL;
}

// função para inserir um elemento no início da lista
void inserirInicioCabCau(ListaCabCau *l, Noticia v) {
    NoCabCau* novo = (NoCabCau*)malloc(sizeof(NoCabCau));
    if (novo == NULL) {
        printf("testealalala");
    }
    novo->info = v;
    novo->prox = l->cab;
    l->cab = novo;
    if (l->cau == NULL) {
        l->cau = novo;
    }
}

// função para imprimir a lista de notícias
void imprimirListaCabCau(ListaCabCau *l) {
    if (!estaVaziaCabCau(l)) {
        NoCabCau *p;
        for (p = l->cab; p != NULL; p = p->prox) {
            imprimirNoticia(&p->info);
        }
    }
    else {
        printf("Lista de notícias vazia!");
    }
}

// função para buscar uma notícia por palavra chave no título ou conteúdo
Noticia* buscarPalavraChaveCabCau(ListaCabCau *l, char palavra[]) {
    NoCabCau *p;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (strstr(p->info.titulo, palavra) || strstr(p->info.conteudo, palavra)) {
            return &p->info;
        }
    }
    return NULL;
}

// função para remover uma notícia por palavra chave no título ou conteúdo
void removerPorPalavraChaveCabCau(ListaCabCau *l, char palavra[]) {
    NoCabCau *p = l->cab;
    NoCabCau *aux = NULL;
    while (p != NULL) {
        if (strstr(p->info.titulo, palavra) || strstr(p->info.conteudo, palavra)) {
            if (aux == NULL) {
                l->cab = p->prox;
                if (l->cab == NULL) {
                    l->cau = NULL;
                }
                free(p); 
                return;
            } 
            else {
                aux->prox = p->prox;
                if (p == l->cau) {
                    l->cau = aux;
                }
                free(p); 
                return;
            }
        } 
        else {
            aux = p;
            p = p->prox;
        }
    }
}

// função para remover uma notícia por ID 
void removerPorIdCabCau(ListaCabCau *l, int id) {
    NoCabCau *p = l->cab;
    NoCabCau *aux = NULL;

    while (p != NULL) {
        if (id == p->info.id) {
            if (aux == NULL) {
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
            }
            free(p);
            return; 
        }
        aux = p;
        p = p->prox;
    }
}

// função para retornar a quantidade de notícias na lista
void retornarQuantidadeNoticiasCabCau(ListaCabCau *l) {
    int qntd = 0;
    NoCabCau *p;
    for (p = l->cab; p != NULL; p = p->prox) {
        qntd++;
    }
    printf("Quantidade de notícias: %d\n", qntd);
}