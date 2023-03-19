
#include <stdio.h>
void main(void)
{
    int i,j;
    int a[100][100];
    int b[100][100];
    int r,c;
    printf("enter rows and colum of matrix:");
    fflush(stdin);  fflush(stdout);
    scanf("%d %d",&r,&c);
    while ((r>100 || r<=0)  || (c>100 ||c<=0))
    {
        printf("!!!!erorr the range from (1 to 100)\n");
        printf("enter rows and colum of matrix again:");
        fflush(stdin);  fflush(stdout);
        scanf("%d %d",&r,&c);
    }
  printf("enter elements of matrix:\n");
for(i=0;i<r;i++)
{
       for(j=0;j<c;j++)
{
    printf("enter elements a%d%d:",i+1,j+1);
    fflush(stdin);  fflush(stdout);
    scanf("%d",&a[i][j]);
}
}

printf("entered matrix\n");
for(i=0;i<r;i++)
{
    for(j=0;j<c;j++)
    {
        printf("%d\t",a[i][j]);
    }
       printf("\n");
}
printf("transpose of matrix\n");
for(i=0;i<c;i++)
{
   for(j=0;j<r;j++)
    {
      b[i][j]=a[j][i];
    }
}

   for(i=0;i<c;i++)
   {
       for(j=0;j<r;j++)
    {
      printf("%d\t",b[i][j]);
    }
    printf("\n");
   }

}

