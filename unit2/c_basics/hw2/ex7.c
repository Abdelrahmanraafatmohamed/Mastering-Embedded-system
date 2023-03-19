
#include <stdio.h>
void main(void)
{
	int x ,i, fact;
	printf("enter a integer:");
	fflush(stdout);
	scanf("%d",&x);
	 fact=1;
	  if (x<0)

	         printf("ERROR!!! factorial of negative number not exist");


	        else
	        {
	            for (i=1;i<=x;i++)
	            fact=fact*i;
	            printf("factorial=%d",fact);
	        }



}

