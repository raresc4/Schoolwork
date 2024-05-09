#include <stdio.h>
#include <stdlib.h>

int ordonateDescrescator(int *v, int st, int dr) {
  if (st >= dr) 
  {
    return 1;
  }
  int indexMijloc = st + (dr - st) / 2;
  int stanga = ordonateDescrescator(v, st, indexMijloc);
  int dreapta = ordonateDescrescator(v, indexMijloc + 1, dr);
  return stanga && dreapta && v[indexMijloc] >= v[indexMijloc + 1];
}


int ordonateCrescator(int *v,int st,int dr)
{
    if(st > dr)
    {
        return 1;
    }
    int indexMijloc = st + (dr - st) / 2;
    if(v[indexMijloc] < v[indexMijloc + 1])
    {
        return ordonateCrescator(v, st, indexMijloc - 1) && ordonateCrescator(v, indexMijloc + 1, dr);
    }
    return 0;
}

void problema1(int *v,int st,int dr)
{
    if(ordonateCrescator(v, st, dr) == 1)
    {
        printf("Crescator\n");
        return;
    }
    if(ordonateDescrescator(v, st, dr) == 1)
    {
        printf("Descrescator\n");
        return;
    }
    printf("Neordonat\n");
}

int problema2(int **matrix, int linieStart, int linieEnd, int colStart, int colEnd) {
    if (linieStart > linieEnd || colStart > colEnd) {
        return 0;
    }
    
    if (linieStart == linieEnd && colStart == colEnd) 
    {
        if(matrix[linieStart][colStart] % 2 == 0)
        {
            return matrix[linieStart][colStart];
        }
        return 0;
    }
    
    int linieMijloc = linieStart + (linieEnd - linieStart) / 2;
    int colMijloc = colStart + (colEnd - colStart) / 2;
    
    int sumSusStanga = problema2(matrix, linieStart, linieMijloc, colStart, colMijloc);
    int sumSusDreapta = problema2(matrix, linieStart, linieMijloc, colMijloc + 1, colEnd);
    int sumJosStanga = problema2(matrix, linieMijloc + 1, linieEnd, colStart, colMijloc);
    int sumJosDreapta = problema2(matrix, linieMijloc + 1, linieEnd, colMijloc + 1, colEnd);
    
    return sumSusStanga + sumSusDreapta + sumJosStanga + sumJosDreapta;
}

int main()
{
    return 0;
}