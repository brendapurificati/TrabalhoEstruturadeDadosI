#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

// função que verifica se a lista está vazia
int estaVazia(Lista *l) {
    if (l->cab == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// cria a lista inicializando os ponteiros de cabeça e cauda como NULL
void criarLista(Lista *l) {
    l->cab = NULL;
    l->cau = NULL;
}

// função para inserir um elemento no início da lista
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

// função para imprimir a lista de notícias
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

// função para buscar uma notícia por palavra chave no título ou conteúdo
Noticia* buscarPalavraChave(Lista *l, char palavra[]) {
    NoLista *p;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (strstr(p->noticia.titulo, palavra) || strstr(p->noticia.conteudo, palavra)) {
            return &p->noticia;
        }
    }
    return NULL;
}

// função para remover uma notícia por palavra chave no título ou conteúdo
void removerPorPalavraChave(Lista *l, char palavra[]) {
    NoLista *p = l->cab;
    NoLista *aux = NULL;

    while (p != NULL) {
        if (strstr(p->noticia.titulo, palavra) || strstr(p->noticia.conteudo, palavra)) {
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
void removerPorId(Lista *l, int id) {
    NoLista *p = l->cab;
    NoLista *aux = NULL;

    while (p != NULL) {
        if (id == p->noticia.id) {
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