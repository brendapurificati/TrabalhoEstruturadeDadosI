#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

// cria a lista simplesmente encadeada inicializando o ponteiro como NULL
void criarListaEncadeada(NoListaEncadeada **l) {
    *l = NULL;
}

// verifica se a lista está vazia
int estaVaziaEncadeada(NoListaEncadeada **l) {
    if (*l == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// função para inserir um elemento no início da lista
void insereInicioEncadeada(NoListaEncadeada** l, Noticia* v) {
    NoListaEncadeada* novo = (NoListaEncadeada*)malloc(sizeof(NoListaEncadeada));
    if (novo != NULL) {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }
    else {
        printf("| Erro ao alocar memoria!\n");
    }
}

// função para imprimir a lista 
void imprimirListaEncadeada(NoListaEncadeada *l) {
    NoListaEncadeada *p;
    if (!estaVaziaEncadeada(&l)) {
        for (p = l; p != NULL; p = p->prox) {
            imprimirNoticia(p->info);
        }
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}
    

// remove um elemento da lista simplesmente encadeada que contenha a palavra-chave no título ou conteúdo
void removerPorPalavraChaveEncadeada(NoListaEncadeada **l, char palavra[]) {
    NoListaEncadeada *p = *l;
    NoListaEncadeada *aux = NULL;
    if (!estaVaziaEncadeada(l)) {
        for (p = *l; p != NULL; p = p->prox) {
            if (strstr(p->info->titulo, palavra) != NULL || strstr(p->info->conteudo, palavra) != NULL) {
                if (aux == NULL) {
                    *l = p->prox;
                    free(p);
                }
                else {
                    aux->prox = p->prox;
                    free(p);
                }
            }
            aux = p;
        }
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}

// função para retornar as notícias classificadas como confiáveis
void retornarConfiaveis(NoListaEncadeada *l) {
    NoListaEncadeada *p;
    if (!estaVaziaEncadeada(&l)) {
        for (p = l; p != NULL; p = p->prox) {
            if (p->info->classificacao == Confiavel) {
                imprimirNoticia(p->info);
            }
        }
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}

// função para retornar as notícias classificadas como suspeitas
void retornarSuspeitas(NoListaEncadeada *l) {
    NoListaEncadeada *p;
    if (!estaVaziaEncadeada(&l)) {
        for (p = l; p != NULL; p = p->prox) {
            if (p->info->classificacao == Suspeita) {
                imprimirNoticia(p->info);
            }
        }
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}

void retornarQuantidadeSuspeitas(NoListaEncadeada *l) {
    NoListaEncadeada *p;
    int contador = 1;
    if (!estaVaziaEncadeada(&l)) {
        for (p = l; p != NULL; p = p->prox) {
            if (p->info->classificacao == Suspeita) {
                contador++;
            }
        }
        printf("| Quantidade de noticias suspeitas: %d\n", contador);
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}

void retornarQuantidadeConfiaveis(NoListaEncadeada *l) {
    NoListaEncadeada *p;
    int contador = 1;
    if (!estaVaziaEncadeada(&l)) {
        for (p = l; p != NULL; p = p->prox) {
            if (p->info->classificacao == Confiavel) {
                contador++;
            }
        }
        printf("| Quantidade de noticias confiaveis: %d\n", contador);
    }
    else {
        printf("| A lista esta vazia.\n");
    }
}

