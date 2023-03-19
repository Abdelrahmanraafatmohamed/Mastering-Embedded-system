
#include <stdio.h>
void main(void)
{
	int x , i  , sum;
	printf("enter a integer:");
	fflush(stdout);
	scanf("%d",&x);
	sum=0;
	for (i=0;i<=x;i++)
	     sum=sum+i;
	     printf("sum = %d",sum);


}

