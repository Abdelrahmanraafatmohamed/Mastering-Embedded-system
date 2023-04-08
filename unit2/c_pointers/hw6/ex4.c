#include <stdio.h>
#include <string.h>
void main()
{  int i,n,j;
  int a[100],b[100];
  int *p=a;
  int *revp=b;
  printf("enter number of element:");
  fflush(stdout); fflush(stdin);
  scanf("%d",&n);
 for (i=0;i<n;i++)
 {
         printf("element(%d)=",i+1);
         fflush(stdout); fflush(stdin);
         scanf("%d",p+i);
 }
for (i=0;i<n;i++)
    p++;
for (i=n-1;i>=0;i--)
{
     p--;
    *revp=*p;
     revp++;

}

for (i=0;i<n;i++)
printf("element(%d)=%d\n",n-i,b[i]);
}





