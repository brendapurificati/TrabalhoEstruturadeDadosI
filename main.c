#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

int main() {

    Noticia* Noticia1 = criarNoticia();
    imprimirNoticia(Noticia1);
    Noticia* Noticia2 = criarNoticia();
    Lista Lista1;
    criarLista(&Lista1);
    inserirElementoInicio(&Lista1, *Noticia1);
    inserirElementoInicio(&Lista1, *Noticia2);
    imprimirListaNoticia(&Lista1);
    printf("-------------------------------------- \n\n");
    Noticia aux = *buscarPalavraChave(&Lista1, "abelhas");
    imprimirNoticia(&aux);
    int a;
    scanf("%d", &a);
    limparTerminal();
    removerPorPalavraChave(&Lista1, "abelhas");
    Noticia aux2 = *buscarPalavraChave(&Lista1, "abelhas");
    imprimirNoticia(&aux2);
    printf("Removido com sucesso");
    scanf("%d", &a);

    return 0;
}