#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

int main() {

    Noticia* Not1 = criarNoticia();
    Noticia* Not2 = criarNoticia();
    Noticia* Not3 = criarNoticia();
    Lista* lista1;
    criarLista(lista1);
    inserirElementoInicio(lista1, *Not1);
    inserirElementoInicio(lista1, *Not2);
    inserirElementoInicio(lista1, *Not3);
    // ----------------------------------------------------
    imprimirListaNoticia(lista1);
    // ----------------------------------------------------
    printf("Teste1");
    limparTerminal();
    removerPorId(lista1, 2);
    imprimirListaNoticia(lista1);

    return 0;
}