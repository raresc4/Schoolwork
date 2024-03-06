#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

char stiva[MAX_SIZE];
int top = -1;

void push(char c)
{
  if(top == MAX_SIZE - 1)
    {
      printf("stiva este plina\n");
      return;
    }
  stiva[++top]=c;
}

char pop(){
  if(top == -1)
    {
      printf("stiva e goala\n");
      return 'g';
    }
  return stiva[top--];
}

int precedenta(char a,char b)
{
  switch(b)
    {
    case '+':
      {
	if(a == '-' || a == '+')
	  {
	    return 1;
	  }
	else
	  {
	    return 0;
	  }
      }
    case '-':
      {
	if(a == '-' || a == '+')
	  {
	    return 1;
	  }
	else
	  {
	    return 0;
	  }
      }
    case '*':
      {
        return 1;
      }
    case '/':
      {
	return 1;
      }
    }
}

void conversie()
{
  int c=0;
  char forma[100];
  int i=0;
  while((c = getchar()) != EOF)
    {
      if(isdigit(c))
	{
	  forma[i++] = c;
	}
      else
	{
	  if(c == '(')
	    {
	      push(c);
	    }
	  else
	    {
	      if(c == ')')
		{
		  while(stiva[top] != '(')
		    {
		      if(top == -1)
			{
			  printf("forma e gresita\n");
			  return;
			}
		      forma[i++] = pop();
		    }
		  pop();
		}
	      else
		{
		  if(c == '+' || c == '-' || c == '*' || c == '/')
		    {
		      while((stiva[top] == '+' || stiva[top] == '-' || stiva[top] == '*' || stiva[top] == '/') && (precedenta(c,stiva[top]) == 1) )
			{
			  forma[i++] = pop();
			}
		      push(c);
		    }
		}
	    }
	}
    }
  while(top != -1)
    {
      forma[i++] = pop();
    }
  for(int j=0; j<i; j++)
    {
      printf("%c",forma[j]);
    }
}


int main(void)
{
  conversie();  
  return 0;
}
