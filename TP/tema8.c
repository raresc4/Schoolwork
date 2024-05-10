#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nume[50];
    int oraStart;
    int oraFinal;
    int durata;
}Spectacol;

int compare(const void *a,const void *b)
{
    return (*(Spectacol*)a).oraFinal - (*(Spectacol*)b).oraFinal;
}

int main()
{
    int n = 0;
    printf("Introdu n: ");
    scanf("%d",&n);
    Spectacol *s = malloc(sizeof(Spectacol)*n);
    if(!s)
    {
        return -1;
    }
    for(int i = 0; i < n; i++)
    {
        printf("Introdu numele spectacolului: ");
        scanf("%49s",s[i].nume);
        printf("Introdu ora de inceput a spectacolului: ");
        scanf("%d",&s[i].oraStart);
        printf("Introdu ora de final a spectacolului: ");
        scanf("%d",&s[i].oraFinal);
        s[i].durata = s[i].oraFinal - s[i].oraStart;
    }
    putchar('\n');
    for(int i = 0 ;i<n;i++)
    {
        printf("%s %d %d\n",s[i].nume,s[i].oraStart,s[i].oraFinal);
    }
    putchar('\n');
    qsort(s,n,sizeof(Spectacol),compare);
    int oraFinal = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i].oraStart >= oraFinal)
        {
            printf("Spectacolul %s de la ora %d, la ora %d\n",s[i].nume,s[i].oraStart,s[i].oraFinal);
            oraFinal = s[i].oraFinal;
        }
    }
    free(s);
    return 0;
}