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
        printf("Erro ao alocar memoria!\n");
    }
}

// função para imprimir a lista 
void imprimirListaEncadeada(NoListaEncadeada **l) {
    NoListaEncadeada *p;
    if (!estaVaziaEncadeada(l)) {
        for (p = *l; p != NULL; p = p->prox) {
            printf("ID: %d\n", p->info->id);
            printf("Titulo: %s", p->info->titulo);
            printf("Conteudo: %s", p->info->conteudo);
            printf("Data de Publicacao: %s", p->info->data);
            printf("Classificacao: %d\n", p->info->classificacao);
        }
    }
    else {
        printf("A lista estáa vazia.\n");
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
        printf("A lista esta vazia.\n");
    }
}

// RetornarNoticiasConfiaveis
// RetornarNoticiasSuspeitas
// Classificar noticias

