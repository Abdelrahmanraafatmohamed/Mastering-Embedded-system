
#include <stdio.h>
int primenumber(int n);
void main()
{
    int a1,a2,i,x;
    printf("Enter two numbers(intervals):");
    fflush(stdin);   fflush(stdout);
    scanf("%d %d",&a1,&a2);
    printf("prime number between %d and %d are:",a1,a2);
    fflush(stdin);   fflush(stdout);
    for (i=a1+1;i<a2;i++)
    {
        x=primenumber(i);
        if (x==0)
            printf("%d\t",i);
    }

}
int primenumber(int n)
{   int j,x=0;

    for (j=2;j<=n/2;j++)
    {
        if(n%j==0)
        {
           x=1;
           break;
        }
    }
    return x;
}

