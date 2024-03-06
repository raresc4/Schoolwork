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
  while((c = getchar()) != EOF)
    {
      if(isalpha(c))
	{
	  printf("%c",c);
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
		      printf("%c",pop());
		      if(top == -1)
			{
			  printf("forma e gresita\n");
			  return;
			}
		    }
		  pop();
		}
	      else
		{
		  if(c == '+' || c == '-' || c == '*' || c == '/')
		    {
		      while((stiva[top] == '+' || stiva[top] == '-' || stiva[top] == '*' || stiva[top] == '/') && (precedenta(c,stiva[top]) == 1) )
			{
			  printf("%c",pop());
			}
		      push(c);
		    }
		}
	    }
	}
    }
  while(top != -1)
    {
      printf("%c",pop());
    }
}


int main(void)
{
  return 0;
}
