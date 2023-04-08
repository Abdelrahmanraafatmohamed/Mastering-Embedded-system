#include <stdio.h>
#include <string.h>
void main()
{
   char a[27];
   char *p;
   int i;
   p=a;
  for (i=0;i<26;i++)
  {
      *p=i+'A';
       p++;
  }
  p=a;
  for (i=0;i<26;i++)
  {
      printf("%c",*p);
      p++;
  }

}


