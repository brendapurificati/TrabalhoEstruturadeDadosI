#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

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
        printf("| Nao foi possivel alocar memoria para a nova noticia.\n");
        return;
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
        printf("| Lista de notícias vazia!\n");
    }
}

// função para buscar uma notícia por palavra chave no título ou conteúdo
void buscarPalavraChaveCabCau(ListaCabCau *l, char palavra[]) {
    NoCabCau *p;
    for (p = l->cab; p != NULL; p = p->prox) {
        if (strstr(p->info.titulo, palavra) != NULL || strstr(p->info.conteudo, palavra) != NULL) {
            imprimirNoticia(&p->info);
            return;
        }
    }
    printf("| Noticia não encontrada!\n");
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
    printf("| Quantidade de notícias pendentes: %d\n", qntd);
}

void ClassificarNoticia(ListaCabCau *pendentes, NoListaEncadeada **verificadas) {
    NoCabCau *p;
    for (p = pendentes->cab; p != NULL; p = p->prox) {
        if (p->info.classificacao == EmAnalise) {
            printf("| Noticia ID: %d\n", p->info.id);
            imprimirNoticia(&p->info);
            printf("| Classificar noticia como:\n| 0 - Em Analise\n| 1 - Suspeita\n| 2 - Confiavel\n");
            int classificacao;
            scanf("%d", &classificacao);
            if (classificacao == 0) {
                p->info.classificacao = EmAnalise;
                printf("| Noticia mantida como Em Analise.\n");
            }
            else if (classificacao == 1) {
                p->info.classificacao = Suspeita;
                removerPorIdCabCau(pendentes, p->info.id);
                insereInicioEncadeada(verificadas, &p->info);
                printf("| Noticia classificada como Suspeita.\n");
            }
            else if (classificacao == 2) {
                p->info.classificacao = Confiavel;
                removerPorIdCabCau(pendentes, p->info.id);
                insereInicioEncadeada(verificadas, &p->info);
                printf("| Noticia classificada como Confiavel.\n");
            }
            else {
                printf("| Opcao invalida! Noticia mantida como Em Analise.\n");
            }
        }
        limparTerminal();
    }
}