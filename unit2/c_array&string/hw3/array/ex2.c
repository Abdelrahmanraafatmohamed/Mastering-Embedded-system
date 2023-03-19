
#include <stdio.h>
void main(void)
{
	int n;
	    float a[100],average,sum=0.0;
	    int i;
	    printf("enter the numbers of data:");
	    fflush(stdin); fflush(stdout);
	    scanf("%d",&n);
	    while (n>100 || n<=0)
	    {
	        printf("!!!erorr no. should be from (1 to 100)\n");
	        printf("enter number again:");
	        fflush(stdin); fflush(stdout);
	        scanf("%d",&n);
	    }
	    for (i=0;i<n;i++)
	        {
	        printf("%d.enter number:",i+1);
	        fflush(stdin); fflush(stdout);
	        scanf("%f",&a[i]);
	        sum=sum+a[i];
	        }

	   average=sum/n;
	   printf("average=%.2f",average);
}

