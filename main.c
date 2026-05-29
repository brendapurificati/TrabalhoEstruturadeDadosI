#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"

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
    printf("-------------------------------------- \n\n");
    Noticia* aux = buscarPalavraChave(&Lista1, "abelha");
    printf(aux);

    return 0;
}