#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    uint16_t cod: 13;
    uint8_t nrlocuri: 4;
    uint16_t puterea: 9;
    uint16_t anfabricatie: 11;
    char marca[10];
    char culoarea[10];
}Masina;

typedef struct{
    uint16_t pret: 9;  
    uint16_t nrpagini: 10;
    uint16_t greutate: 13;
    uint8_t sw: 1;
    int nrexemplare;
    char nume[20];
    char autor[20];
    union{
        char ibsn[14];
        int anaparitie;
    }uniune; 
}Biblioteca;

int compare(const void *elem1, const void *elem2)
{
    return (*(Masina *)elem1).anfabricatie - (*(Masina *)elem2).anfabricatie;
}

void problema1()//examen 1
{
    Masina *masina = NULL;
    int nr = 0;
    int aux = 0;
    for(;;)
    {
        printf("Introdu o optiune: ");
        scanf("%d",&aux);
        switch (aux)
        {
        case 1:
        {
            masina = realloc(masina,sizeof(Masina)*(nr + 1));
            if(!masina)
            {
                perror("eroare");
                exit(-1);
            }
            printf("se va introduce un automobil nou:\nintrodu codul: ");
            scanf("%d",&aux);
            masina[nr].cod = aux ;
            printf("introdu nr de locuri : ");
            scanf("%d",&aux);
            masina[nr].nrlocuri = aux ;
            printf("introdu puterea: ");
            scanf("%d",&aux);
            masina[nr].puterea = aux ;
            printf("introdu anfabricatie: ");
            scanf("%d", &aux);
            masina[nr].anfabricatie = aux ;
            printf("introdu marca: ");
            scanf("%9s",masina[nr].marca);
            printf("introdu culoarea: ");
            scanf("%9s",masina[nr].culoarea);
            nr++;
            break;
        }
        case 2:
        {
            int ok = 0;
            printf("introdu codul : ");
            scanf("%d",&ok);
            for(int i=0;i<nr;i++)
            {
                if(masina[i].cod == ok)
                {
                    for(int j=i+1;j<nr;j++)
                    {
                        masina[i-1] = masina[i];
                    }
                }
                nr--;
                i--;
                ok = 0;
                break;
            }
            if(!ok)
            {
                printf("codul masinii nu exista\n");
            }
            break;
        }
        case 3:
        {
            for(int i=0;i<nr;i++)
            {
                printf("autmobilul de pe pozitia %d are:\ncodul : %d\nnr de locuri : %d\nputerea : %d\nanfabricatie : %d \nmarca : %s\nculoarea : %s\n",i,masina[i].cod,masina[i].nrlocuri,masina[i].puterea,masina[i].anfabricatie,masina[i].marca,masina[i].culoarea);
            }
            break;
        }
        case 4:
        {
            int ok = 0;
            printf("introdu nr de locuri: ");
            scanf("%d", &ok);
            for(int i=0;i<nr;i++)
            {
                if(masina[i].nrlocuri == ok)
                {
                    printf("autmobilul de pe pozitia %d are:\ncodul : %d\nnr de locuri : %d\nputerea : %d\nanfabricatie : %d \nmarca : %s\nculoarea : %s\n",i,masina[i].cod,masina[i].nrlocuri,masina[i].puterea,masina[i].anfabricatie,masina[i].marca,masina[i].culoarea);
                }
            }
            break;
        }
        case 5:
        {
            qsort(masina,nr,sizeof(Masina),compare);
            break;
        }
        default:
        {
        free(masina);
            exit(-1);
        }
        }
    }
}

void problema2()//examen 2
{
    int aux = 0;
    Biblioteca *biblioteca = NULL;
    int nr = 0;
    for(;;)
    {
        printf("alege o optiune: ");
        scanf("%d",&aux);
        switch (aux)
        {
        case 1:
        {
            biblioteca = realloc(biblioteca,sizeof(Biblioteca)*(nr+1));
            if(!biblioteca)
            {
                perror("eroare");
                exit(-1);
            }
            printf("introdu numele: ");
            scanf("%19s",biblioteca[nr].nume);
            printf("introdu autorul: ");
            scanf("%19s",biblioteca[nr].autor);
            printf("introdu nrexemplare: ");
            scanf("%d",&biblioteca[nr].nrexemplare);
            printf("introdu pretul: ");
            scanf("%d",&aux);
            biblioteca[nr].pret = aux;
            printf("introdu nrpagini: ");
            scanf("%d",&aux);
            biblioteca[nr].nrpagini = aux;
            printf("introdu greutatea: ");
            scanf("%d",&aux);
            biblioteca[nr].greutate = aux;
            printf("introdu daca vrei sa fie carte sau revista(0 pt carte sau 1 pentru revista): ");
            scanf("%d",&aux);
            biblioteca[nr].sw = aux;
            if(biblioteca[nr].sw == 0)
            {
                printf("introdu ibsn: ");
                scanf("%13s",biblioteca[nr].uniune.ibsn);
            }
            else
            {
                printf("introdu anaparitie: ");
                scanf("%d",&aux);
                biblioteca[nr].uniune.anaparitie = aux;
            }
            nr++;
            break;
        }
        case 2:
        {
            for(int i=0;i<nr;i++)
            {
                if(biblioteca[nr].sw == 0 && biblioteca[nr].pret > 100)
                {
                    printf("cartea de pe pozitia %d are numele : %s\n",i,biblioteca[i].nume);
                }
            }
            break;
        }
        case 3:
        {
            for(int i=0;i<nr;i++)
            {
                if(biblioteca[nr].sw == 0)
                {
                    printf("cartea de pe pozitia %d are numele : %s\nautorul: %s\npretul: %d\nnrpagini: %d\ngreutate: %d\nnrexemplare: %d si ibsnul: %s\n",i,biblioteca[i].nume,biblioteca[i].autor,biblioteca[i].pret,biblioteca[i].nrpagini,biblioteca[i].greutate,biblioteca[i].nrexemplare,biblioteca[i].uniune.ibsn);
                }
                else
                {
                    printf("revista de pe pozitia %d are numele : %s\nautorul: %s\npretul: %d\nnrpagini: %d\ngreutate: %d\nnrexemplare: %d si anaparitie: %d\n",i,biblioteca[i].nume,biblioteca[i].autor,biblioteca[i].pret,biblioteca[i].nrpagini,biblioteca[i].greutate,biblioteca[i].nrexemplare,biblioteca[i].uniune.anaparitie);
                }
            }
            break;
        }
        case 4:
        {
            FILE *f = fopen("biblioteca.bin","wb");
            if(!f)
            {
                perror("eroare");
                exit(-1);
            }
            fwrite(biblioteca,sizeof(Biblioteca),nr,f);
            if(fclose(f))
            {
                perror("eroare");
                exit(-1);
            }
        }
        default:{
        free(biblioteca);
        exit(-1);
        }
        }
    }
}

int main(void)
{
    problema2();
    return 0;
}
