#include <stdio.h>
#include <string.h>
void main()
{
   int m=29;
   int *ab;
   ab=&m;
   printf("address of m:0x%x",ab);
   printf("\nvalue of m:%d\n",*ab);
   m=34;
   printf("address of m:0x%x",ab);
   printf("\nvalue of m:%d\n",*ab);
   *ab=7;
   printf("address of m:0x%x",ab);
   printf("\nvalue of m:%d\n",*ab);

}


