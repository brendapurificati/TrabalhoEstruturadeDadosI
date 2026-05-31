#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

int main() {

    Noticia* Not1 = criarNoticia();
    Noticia* Not2 = criarNoticia();
    // Noticia* Not3 = criarNoticia();
    ListaCabCau lista1;
    criarListaCabCau(&lista1);
    inserirInicioCabCau(&lista1, *Not1);
    inserirInicioCabCau(&lista1, *Not2);
    // inserirInicioCabCau(&lista1, *Not3);
    // ----------------------------------------------------
    imprimirListaCabCau(&lista1);
    // ----------------------------------------------------
    int a;
    scanf("%d", &a);
    limparTerminal();
    //-----------------------------------------------------
    printf("Teste1");
    NoListaEncadeada* listaencadeada1;
    criarListaEncadeada(&listaencadeada1);
    printf("Teste2");
    insereInicioEncadeada(&listaencadeada1, Not1);
    printf("Teste3");
    insereInicioEncadeada(&listaencadeada1, Not2);
    printf("Teste4");
    // insereInicioEncadeada(&listaencadeada1, Not3);
    // printf("Teste5");
    imprimirListaEncadeada(&listaencadeada1);
    printf("Teste6");
    int b;
    scanf("%d", &b);
    limparTerminal();
    //-----------------------------------------------------
    removerPorPalavraChaveEncadeada(&listaencadeada1, "abelhas");
    imprimirListaEncadeada(&listaencadeada1);

    return 0;
}