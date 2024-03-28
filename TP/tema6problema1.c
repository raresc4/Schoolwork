#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

int comune(int nVec,...)//am considerat ca valorile din vector pot fi pana la maxim 1000
{
  va_list va;
  va_start(va,nVec);
  int *frec = calloc(1000,sizeof(int));
  if(!frec){
    perror("eroare");
    exit(-1);
  }
  for(int i = 0;i < nVec;i++)
    {
      int *v = va_arg(va,int*);
      int nr = va_arg(va,int);
      for(int j = 0;j < nr;j++)
	{
	  frec[v[j]]++;
	}
    }
  int c =0;
  for(int i = 0;i< 1000;i++)
    {
      if(frec[i] == nVec)
	{
	  c++;
	}
    }
  free(frec);
  va_end(va);
  return c;
}


int main(void) {
  int v1[2]={5,8};
  int v2[3]={8,3,5};
  int v3[3]={5,0,8};
  printf("%d\n",comune(3,v1,2,v2,3,v3,3));
    return 0;
}
