#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>




int main(int argc, char **argv) {
  FILE *fout = fopen(argv[argc-1],"a");
  if(!fout)
    {
      perror("eroare");
      exit(-1);
    }
  for(int i = 1;i < argc - 1;i++)
    {
      FILE *fin = fopen(argv[i],"rt");
      if(!fin){
	perror("eroare");
	exit(-1);
      }
      int c = 0;
      while((c=fgetc(fin))!=EOF){
	fputc(c,fout);
      }
      if(fclose(fin))
	{
	  perror("eroare");
	  exit(-1);
	}
    }
  if(fclose(fout))
    {
      perror("eroare");
      exit(-1);
    }
  return 0;
}
