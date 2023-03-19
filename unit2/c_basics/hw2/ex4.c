
#include <stdio.h>
void main(void)
{

	float n;
	printf(" enter the  number:");
	fflush(stdout);
	scanf("%f",&n);
	if (n>0)
	    printf("%.1f is a positive",n);
	else if (n==0)
	     printf("you enter zero");
	else
	    printf("%.1f is a negative",n);
	}


