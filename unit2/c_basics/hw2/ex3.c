
#include <stdio.h>
void main(void)
{
	float n,m,x;
	printf("please enter the three number=");
	fflush(stdout);
	scanf("%f %f %f",&n,&m,&x);
	if (n>=m && n>=x)
	    printf("the largest number=%.2f",n);
	else if (m>=n && m>=x)
	   printf("the largest number=%.2f",m);
	    else
	    printf("the largest number=%.2f",x);

	}


