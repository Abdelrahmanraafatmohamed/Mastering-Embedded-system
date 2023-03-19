
#include <stdio.h>
int main()
{
    int n,i;
    int a[100];
    int element,location;
    printf("\nenter no. of elements:");
    fflush(stdin); fflush(stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
    }

  printf("\nenter the number to be inserted:");
  fflush(stdin); fflush(stdout);
  scanf("%d",&element);
     printf("\nenter the location:");
     fflush(stdin); fflush(stdout);
     scanf("%d",&location);
     for (i=n;i>=location;i--)
     {
         a[i]=a[i-1];
     }
     a[location-1]=element;
     n++;
for (i=0;i<n;i++)
{
    printf("%d",a[i]);
}
return(0);
}
