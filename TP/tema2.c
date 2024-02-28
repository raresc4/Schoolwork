#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

void problema4(double (*functie)(double),double a,double b,int n)//2.4
{
    double salt=(b-a)/n;
    for(double i=a;i<=b;i+=salt)
    {
        printf("f(%f)=%f\n",i,functie(i));
    }
}

void examen2(int (*functie)(char*),char *cuvant)//2.2
{
  FILE *f=fopen("CUVINTE.TXT","at");
  if(!f)
    {
      perror("eroare");
      exit(-1);
    }
  printf("%s : %d\n",cuvant,functie(cuvant));
  fprintf(f,"%s : %d\n",cuvant,functie(cuvant));
  if(fclose(f)!=0)
    {
      perror("eroare");
      exit(-1);
    }
}

int vocale(char *cuvant)
{
  int c=0;
  for(int i=0;i<strlen(cuvant);i++)
    {
      if(cuvant[i]=='a' || cuvant[i]=='A' || cuvant[i]=='e' || cuvant[i]=='E' || cuvant[i]=='i' || cuvant[i]=='I' || cuvant[i]=='o' || cuvant[i]=='O' || cuvant[i]=='u' || cuvant[i]=='U')
	{
	  c++;
	}
    }
  return c;
}

int literemari(char *cuvant)
{
  int c=0;
  for(int i=0;i<strlen(cuvant);i++)
    {
      if(isupper(cuvant[i]))
	{
	  c++;
	}
    }
  return c;
}

int diferenta(char *cuvant)
{
  return (int)cuvant[strlen(cuvant)-1]-(int)cuvant[0];
}


int main(int argc,char **argv)
{
  int sw=0;
  for(int i=1;i<argc;i++)
    {
      printf("Alege o optiune:\n1-strlen\n2-nr de vocale\n3-numarul de litere mari\n4-diferenta codurilor ascii dintre primul si ultimul caracter\n");
      scanf("%d",&sw);
      switch(sw)
	{
	case 1:
	    {
	      examen2(strlen,argv[i]);
	      break;
	    }
	case 2:
	    {
	      examen2(vocale,argv[i]);
	      break;
	    }
	case 3:
	    {
	      examen2(literemari,argv[i]);
	      break;
	    }
	case 4:
	  {
	    examen2(diferenta,argv[i]);
	    break;
	  }
	}
    }
  return 0;
}
