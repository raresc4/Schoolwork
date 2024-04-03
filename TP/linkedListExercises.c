#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct elem{
  int nr;
  struct elem *urm;
}elem;

elem *nou(int n,elem *urmator){
  elem *e = malloc(sizeof(elem));
  if(!e){
    perror("eroare");
    return NULL;
  }
  e->nr = n;
  e->urm = urmator;
  return e;
}

elem *adaugainceput(elem *cap,int nr)
{
  return nou(nr,cap);
}

elem *adaugaSfarsit(elem *cap,int nr)
{
  elem *crt = cap;
  if(!cap)
    {
      return nou(nr,NULL);
    }
  while(crt->urm)
    {
      crt = crt->urm;
    }
  crt->urm = nou(nr,NULL);
  return cap;
}

elem *inserareSpate(elem *cap,int n,int tinta)
{
  elem *crt= NULL;
  crt = cap;
  while(crt->urm->nr != tinta)
    {
      crt = crt->urm;
      if(!(crt->urm))
	{
	  printf("n nu exista in lista\n");
	  return cap;
	}
    }
  elem *aux = nou(n,crt->urm);
  crt->urm = aux;
  return cap;
}

elem *stergerePrim(elem *cap)
{
  if(!cap)
    {
      printf("Lista e goala deja\n");
      return cap;
    }
  if(!(cap->urm))
    {
      free(cap);
      return NULL;
    }
  elem *p = cap;
  cap=cap->urm;
  free(p);
  return cap;
}

elem *stergereUltim(elem *cap)
{
  elem *crt = cap;
  while(crt->urm->urm)
    {
      crt = crt->urm;
    }
  free(crt->urm);
  crt->urm = NULL;
  return cap;
}

elem *stergereInauntru(elem *cap,int tinta)
{
  elem *crt = cap;
  while(crt->urm->nr != tinta)
    {
      crt = crt->urm;
      if(!(crt->urm))
	{
	  printf("Valoarea data nu exita\n");
	  return cap;
	}
    }
  elem *p = crt->urm;
  crt->urm = crt->urm->urm;
  free(p);
  return cap;
}

elem *inserareMedie(elem *cap)
{
  elem *crt = cap;
  while(crt->urm->urm)
    {
      elem *new = nou((cap->nr + cap->urm->nr)/2,crt->urm);
      crt->urm = new;
      crt=crt->urm->urm;
    }
  return cap;
}

int identice(elem *cap1,elem *cap2)
{
  elem *crt1 = cap1;
  elem *crt2 = cap2;
  for(;crt1;crt1=crt1->urm,crt2=crt2->urm)
    {
      if(crt1->nr != crt2->nr)
	{
	  return 0;
	}
    }
  return 1;
}

int gasit(elem *cap,int tinta)
{
  if(!cap)
    {
      return 0;
    }
  elem *crt = cap;
  for(;crt;crt=crt->urm)
    {
      if(crt->nr == tinta)
	{
	  return 1;
	}
    }
  return 0;
}

elem *reuniune(elem *cap1, elem *cap2) {
  elem *capnou = NULL;
  elem *crt1 = cap1;
  elem *crt2;
  while (crt1) {
    crt2 = cap2;
    while (crt2) {
      if (crt1->nr == crt2->nr && !gasit(capnou, crt1->nr)) {
        capnou = adaugainceput(capnou, crt1->nr);
      }
      crt2 = crt2->urm;
    }
    crt1 = crt1->urm;
  }
  return capnou;
}

elem *inserareListaSortata(elem *cap,int tinta)
{
  if(!cap)
    {
      return nou(tinta,NULL);
    }
  elem *crt = cap;
  if(!(crt->urm))
	{
	  crt->urm = nou(tinta,NULL);
	  return cap;
	}
  while(crt->urm->nr < tinta)
    {
      crt = crt->urm;
      if(!(crt->urm))
	{
	  crt->urm = nou(tinta,NULL);
	  return cap;
	}
    }
  elem *new = nou(tinta,crt->urm);
      crt->urm = new;
  return cap;
}

elem *sortareLista(elem *cap)
{
  if(!cap)
    {
      printf("Lista data este goala\n");
      return NULL;
    }
  elem *crt = cap;
  elem *listanoua = NULL;
  for(;crt;crt=crt->urm)
    {
      listanoua = inserareListaSortata(listanoua,crt->nr);
    }
  return listanoua;
}

elem *reverseList(elem *cap)
{
  elem *prev,*next = NULL;
  elem *crt = cap;
  while(crt)
    {
      next = crt->urm;
      crt->urm = prev;
      prev = crt;
      crt = next;
    }
  cap = prev;
  return cap;
}

void afisare(elem *cap)
{
  for(;cap;cap=cap->urm)
    {
      printf("%d ",cap->nr);
    }
  putchar('\n');
}

void eliberare(elem *cap)
{
  elem *crt;
  while(cap)
    {
      crt = cap->urm;
      free(cap);
      cap = crt;
    }
}

int main(void) {

      return 0;
}
