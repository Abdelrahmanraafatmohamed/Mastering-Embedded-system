#include <stdio.h>
#include <string.h>
void main()
{  int i;
  char a[100],b[100];
  char *p=a;
  char *revp=b;
  printf("enter the string:");
  fflush(stdout);
  gets(a);

  for (i=0;i<strlen(a);i++)
      p++;

  for (i=strlen(a);i>0;i--)
{
     p--;
     *revp=*p;
     revp++;
  }
  *revp='\0';
  printf("%s",b);
}




