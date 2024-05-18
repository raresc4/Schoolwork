#include <stdio.h>

char v[100];

typedef struct{
    int nr;
    char text;
}Paranteze;

Paranteze paranteze[6] = {{0,'('},{1,')'},{2,'{'},{3,'}'},{4,'['},{5,']'}};

void afisare(int k)
{
    for(int i = 0;i <= k;i++)
    {
        printf("%c ",v[i]);
    }
    putchar('\n');
}

int valid(int k,int n)
{
    if(k != (n-1))
    {
        return 0;
    }
    for(int i = 0; i < n;i++)
    {
        if(v[i] == '(')
        {
            for(int j = i+1;j < n;j++)
            {
                if(v[j] == ')')
                {
                    break;
                }
                if(j == (n-1))
                {
                    return 0;
                }
            }
        }
        if(v[i] == '[')
        {
            for(int j = i+1;j < n;j++)
            {
                if(v[j] == ']')
                {
                    break;
                }
                if(j == (n-1))
                {
                    return 0;
                }
            }
        }
        if(v[i] == '{')
        {
            for(int j = i+1;j < n;j++)
            {
                if(v[j] == '}')
                {
                    break;
                }
                if(j == (n-1))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void Back(int k,int n)
{
    for(int i = 0;i < 5;i++)
    {
        v[k] = paranteze[i].text;
        if(k <= n)
        {
            if(valid(k,n))
            {
                afisare(k);
            }
            else
            {
                Back(k+1,n);
            }
        }
    }
}

int main(void)
{
    Back(0,3);
    return 0;
}