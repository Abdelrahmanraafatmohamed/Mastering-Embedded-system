
#include <stdio.h>
void main ()
{
  printf("Enter a sentence:");
  fflush(stdin);  fflush(stdout);
   revsten();

}

void revsten()
{
    char c;
    scanf("%c",&c);
    if(c!='\n')
    {
        revsten();
        printf("%c",c);
    }

}
