#include "lib.h"

int main()
{
    char frase[100];
    //Folha * f = (Folha*)malloc(sizeof(Folha));
    //No * n = (No*)malloc(sizeof(No));
    //f = criaFolha('a',2);
    //n = criaNofolha(f,1);

    //printf("%c %d",f->simb,f->freq);
    //printf("%c %d",n->esq->simb, n->esq->freq);
    //insereLista(&l,n);
    printf("Digite sua frase: ");
    gets(frase);

    geraLista(frase);
    /*insereLista(&l,criaNofolha(criaFolha('a',1),3));
    while(l != NULL)
    {
        printf("%c",l->n->esq->simb);
        l = l->prox;
    }*/
    //exibeLista(&l);
    return 0;
}
