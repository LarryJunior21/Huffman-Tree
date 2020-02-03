#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nofolha
{
    int freq;
    char simb;
};typedef struct nofolha Folha;

struct no
{
    int freq;
    struct nofolha *esq, *dir;
};typedef struct no No;

struct lista
{
    struct no * n;
    struct lista * prox;
};typedef struct lista Lista;

void init_lista(Lista ** l)
{
    *l = NULL;
}

void insereLista(Lista ** l, No * info)
{
    int passou = 0;
    Lista *aux, * ant, * novo;
    novo = (Lista*)malloc(sizeof(Lista));
    aux = (Lista*)malloc(sizeof(Lista));
    aux = *l;
    if(*l == NULL)
    {
        aux = (Lista*)malloc(sizeof(Lista));
        aux->n = info;
        aux->prox = NULL;
        *l = aux;
    }
    else
    {
        novo->n = info;
        ant = aux;
        while(aux != NULL && aux->n->freq < info->freq)
        {
            passou = 1;
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL)
        {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        else
        {
            novo->prox = aux;
            if(passou == 1)
                ant->prox = novo;
            else
                *l = novo;
        }
    }
}

Folha * criaFolha(char simbe, int freqe)
{
    Folha * novo = (Folha*)malloc(sizeof(Folha));
    novo->freq = freqe;
    novo->simb = simbe;
    return novo;
}

No * criaNofolha(Folha * a, int freqe)
{
    No * novo = (No*)malloc(sizeof(No));
    novo->esq = a;
    novo->freq = freqe;
    return novo;
}

No * criaNo(Folha * esq,Folha * dir)
{

}

char * remv(char frase[], int i)
{
    int x;
    char * s = (char*)malloc(sizeof(char*));
    for(x = i; x<strlen(frase); x++)
    {
        frase[x] = frase[x+1];
    }
    strcpy(s,frase);
    return s;
}

void geraLista(char frase[])
{
    Lista * l = (Lista*)malloc(sizeof(Lista));
    init_lista(&l);
    int i,x, cont = 0;
    char simbo;
    while(strlen(frase) > 1)
    {
        simbo = frase[0];
        for(i = 0; i<strlen(frase); i++)
        {
            if(simbo == frase[i])
            {
                cont++;
                for(x = 0; x<strlen(frase); x++)
                {
                    frase[x] = frase[x+1];
                }
                printf("%s |",frase);
            }
        }
        cont = 0;
        insereLista(&l, criaNofolha(criaFolha(simbo,cont),cont));
    }
    exibeLista(l);
}

void exibeLista(Lista * l)
{
    while(l != NULL)
    {
        printf("%c",l->n->esq->simb);
        l = l->prox;
    }
}

#endif // LIB_H_INCLUDED
