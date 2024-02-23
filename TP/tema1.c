#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

void problema1()
{
  int n=0;
  scanf("%d",&n);
  int **matrice=malloc(sizeof(int*)*n);
  if(!matrice)
    {
      perror("eroare");
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      *(matrice+i)=malloc(sizeof(int)*n);
      if(!(*(matrice+i)))
	{
	  perror("eroare");
	  exit(-1);
	}
    }
  int *sumalinii=calloc(n,sizeof(int)*n);
  if(!sumalinii)
    {
      perror("eroare");
      exit(-1);
    }
  int *sumacoloane=calloc(n,sizeof(int)*n);
  if(!sumacoloane)
    {
      perror("eroare");
      exit(-1);
    }
  printf("Introdu elementele matricei:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  scanf("%d",&(*(*(matrice+i)+j)));
	}
    }
  printf("Se va afisa matricea:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%d ",(*(*(matrice+i)+j)));
	}
      putchar('\n');
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  (*(sumalinii+i))+=(*(*(matrice+i)+j));
	}
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  (*(sumacoloane+i))+=(*(*(matrice+j)+i));
	}
    }
  printf("Se va afisa suma de pe fiecare linie:\n");
  for(int i=0;i<n;i++)
    {
      printf("%d\n",*(sumalinii+i));
    }
  printf("Se va afisa suma de pe fiecare coloana:\n");
  for(int i=0;i<n;i++)
    {
      printf("%d\n",*(sumacoloane+i));
    }
  for(int i=0;i<n;i++)
    {
      free(*(matrice+i));
    }
  free(matrice);
  free(sumalinii);
  free(sumacoloane);
}

void problema2()
{
  int n=0;
  scanf("%d",&n);
  char cuvant[15];
  char **linii=malloc(sizeof(char*)*n);
  if(!linii)
    {
      perror("eroare");
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      linii[i]=malloc(sizeof(char)*n);
      if(!linii[i])
	{
	  perror("eroare");
	  exit(-1);
	}
    }
  printf("Se va citi cuvantul:\n");
  scanf("%14s",cuvant);
  printf("Se va citi matricea:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  scanf(" %c",&linii[i][j]);
	}
    }
  printf("Se va afisa matricea:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%c ",linii[i][j]);
	}
      putchar('\n');
    }
  int aux=0;
  int inceput=0;
  int k;
  for(int i=0;i<n;i++)//spre dreapta
    {
      k=0;
      for(int j=0;j<n;j++)
	{
	      if(cuvant[k]==linii[i][j])
		{
		  inceput=j;
		  k++;
		  if(k==strlen(cuvant))
		    {
		      aux=1;
		      printf("De la linia %d coloana %d spre dreapta\n",i,inceput-1);
		    }
		}
	      else
		{
		  k=0;
		}
	}
      k=0;
    }
  for(int i=0;i<n;i++)//spre stanga 
    {
      k=0;
      for(int j=n-1;j>=0;j--)
	{
	  if(cuvant[k]==linii[i][j])
	    {
	      inceput=j;
	      k++;
	      if(k==strlen(cuvant))
		{
		  aux=1;
		  printf("De la linia %d coloana %ld spre stanga\n",i,inceput+strlen(cuvant)-1);
		}
	    }
	  else
	    k=0;
	}
      k=0;
    }
  for(int i=0;i<n;i++)//in jos
    {
      k=0;
      for(int j=0;j<n;j++)
	{
	  if(cuvant[k]==linii[j][i])
		{
		  inceput=i;
		  k++;
		  if(k==strlen(cuvant))
		    {
		      aux=1;
		      printf("De la linia %d coloana %ld in jos\n",j,inceput-strlen(cuvant)+1);
		    }
		}
	      else
		{
		  k=0;
		}
	}
      k=0;
    }
  for(int i=n-1;i>=0;i--)//in sus(nu merge)
    {
      k=0;
      for(int j=0;j<n;j++)
	{
	  if(cuvant[k]==linii[j][i])
	    {
	      inceput=j;
	      k++;
	      if(k==strlen(cuvant))
		{
		  aux=1;
		  printf("De la linia %d coloana %d in jos\n",j,inceput);
		}
	      else
		{
		  k=0;
		}
	    }
	}
      k=0;
    }
  if(!aux)
    {
      printf("Nu exista cuvantul\n");
    }
  for(int i=0;i<n;i++)
    {
      free(linii[i]);
    }
  free(linii);
}

int main(void)
{
  return 0;
}
