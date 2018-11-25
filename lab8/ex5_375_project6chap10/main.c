#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
  int contents[STACK_SIZE];
  int top = 0;
  char ch =' ';
  int n, m;
  printf("Enter an RPN expression: ", ch);
  while(1)
  {
      ch = getchar();
      if(ch!=' ')
      {
          if(ch=='9' || ch=='8' || ch=='7' || ch=='6' ||ch=='5' ||ch=='4' ||ch=='3' ||ch=='2' ||ch=='1' || ch=='0')
            push(ch-48);
          else if(ch=='=')
          {
              n=pop();
              printf("Value of expression: %d\n", n);
              printf("Enter an RPN Expression: ", ch);
              ch = getchar();
          }
          else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
          {
              n=pop();
              m=pop();
              switch(ch)
              {
                case '+':
                    m+=n;
                    break;
                case '-':
                    m-=n;
                    break;
                case '*':
                    m*=n;
                    break;
                case '/':
                    m/=n;
                    break;
              }
              push(m);
          }

          else
            break;
      }
  }
  return 0;
}
