#ifndef NOTICIA_H
#define NOTICIA_H

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

int criarID();

void imprimirNoticia(Noticia *not);

Noticia* criarNoticia();

void liberarNoticia(Noticia *not);

#endif