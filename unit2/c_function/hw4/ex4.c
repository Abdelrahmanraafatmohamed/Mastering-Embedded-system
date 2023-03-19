
#include <stdio.h>
void main ()
{
  int n,x;
  printf("Enter base number:");
  fflush(stdin);  fflush(stdout);
  scanf("%d",&x);
  printf("enter power number(positive integer):");
  fflush(stdin);  fflush(stdout);
  scanf("%d",&n);
  printf("%d^%d=%d",x,n,numpo(x,n));

}
int numpo(int x , int n)
{
    if (n!=0)
        return (x*numpo(x,n-1));
     else
    return 1 ;
}
