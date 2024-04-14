#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
    struct elem *prev;
}elem;

typedef struct{
    elem *prim;
    elem *ultim;
}Lista;

void init(Lista *lista)
{
    lista->prim = NULL;
    lista->ultim = NULL;
}

elem *nou(int nr)
{
    elem *aux = malloc(sizeof(elem));
    if(!aux)
    {
        return NULL;
    }
    aux->n = nr;
    aux->urm = NULL;
    aux->prev = NULL;
    return aux;
}

void adaugaFinal(Lista *lista,elem *aux)
{
    aux->prev = lista->ultim;
    if(lista->ultim)
    {
        lista->ultim->urm = aux;
    }
    else
    {
        lista->prim = aux;
    }
    lista->ultim = aux;
    aux->urm = NULL;
}

void afisare(Lista *lista)
{
    elem *crt = lista->prim;
    for(;crt;crt=crt->urm)
    {
        printf("%d ",crt->n);
    }
    putchar('\n');
}

void eliberare(Lista *lista)
{
    elem *crt = lista->prim;
    while(crt->urm)
    {
        elem *aux = crt->urm;
        free(crt);
        crt=aux;
    }
    free(crt);
}

void reverse(Lista *lista)
{
    elem *prev = NULL;
    elem *crt = lista->prim;
    elem *next = NULL;
    while(crt)
    {
        next = crt->urm;
        crt->urm = prev;
        prev = crt;
        crt = next;
    }
    lista->prim = prev;
}

void stergere(Lista *lista,int tinta)
{
    if(!lista)
    {
        printf("lista e goala\n");
        return;
    }
    elem *crt = lista->prim;
    while(crt->n != tinta)
    {
        crt = crt->urm;
        if(!crt)
        {
            printf("nu exista in lista\n");
            return;
        }
    }
    crt->prev->urm = crt->urm;
    crt->urm->prev = crt->prev;
    free(crt);
}

void inserare(Lista *lista,int tinta,elem *elementnou)
{
    if(!lista)
    {
        printf("lista e goala\n");
        return;
    }
    elem *crt = lista->prim;
    while(crt->n != tinta)
    {
        crt = crt->urm;
    }
    crt->prev->urm = elementnou;
    elementnou->prev = crt->prev;
    crt->prev = elementnou;
    elementnou->urm = crt;
}

int lungime(Lista *lista)
{
    int l = 0;
    elem *crt = lista->prim;
    for(;crt;crt=crt->urm)
    {
        l++;
    }
    return l;
}



int main(void)
{
    Lista lista1;
    init(&lista1);
    adaugaFinal(&lista1,nou(1));
    adaugaFinal(&lista1,nou(23));
    adaugaFinal(&lista1,nou(10));
    adaugaFinal(&lista1,nou(53));
    adaugaFinal(&lista1,nou(40));
    afisare(&lista1);
    sortare(&lista1,lungime(&lista1));
    afisare(&lista1);
    eliberare(&lista1);
    return 0;
}
