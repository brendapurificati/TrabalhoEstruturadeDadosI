#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum classificacao {
    EmAnalise, 
    Suspeita, 
    Confiavel
} Classificacao;

typedef struct noticia {
    int id;
    char data[20];
    char titulo[50];
    char conteudo[150];
    char fonte[70];
    Classificacao classificacao;
    // 1- EmAnalise, 2-Suspeita, 3-Confiavel
} Noticia;

typedef struct Nolista {
    Noticia noticia;
    struct Nolista *prox;
} NoLista;

typedef struct lista {
    NoLista *cab, *cau;
} Lista;

int estaVazia(Lista *l) {
    if (l == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int criarID() {
    static int id = 0;
    return ++id;
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

void imprimirNoticia(Noticia *not) {
    printf("Id: %d\n", not->id);
    printf("Classificacao: %d\n", not->classificacao);
    printf("Data: %s\n", not->data);
    printf("Titulo: %s\n", not->titulo);
    printf("Conteudo: %s\n", not->conteudo);
    printf("Fonte: %s\n", not->fonte);
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

Noticia* criarNoticia() {

    Noticia* Not1 = (Noticia*)malloc(sizeof(Noticia*));
    printf("Digite a data de publicacao da noticia: ");
    scanf("%s", Not1->data);
    getchar();
    printf("Digite o titulo da publicacao: ");
    scanf("%s", Not1->titulo);
    getchar();
    printf("Digite o conteudo da publicacao: ");
    scanf("%s", Not1->conteudo);
    getchar();
    printf("Digite a fonte da publicacao: ");
    scanf("%s", Not1->fonte);
    getchar();
    Not1->classificacao = EmAnalise;
    Not1->id = criarID();

    return Not1;
}

void liberarNoticia(Noticia *not) {
    free(not);
}

int main() {

    Noticia* Noticia1 = criarNoticia();
    imprimirNoticia(Noticia1);
    Noticia* Noticia2 = criarNoticia();
    printf("-------------------------------------- \n\n");
    Lista Lista1;
    criarLista(&Lista1);
    inserirElementoInicio(&Lista1, *Noticia1);
    inserirElementoInicio(&Lista1, *Noticia2);
    imprimirListaNoticia(&Lista1);

    return 0;
}