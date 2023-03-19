
#include <stdio.h>
void main(void)
{
	float a,b , temp;

		printf("Enter value of a:");
		fflush(stdout);
	    scanf("%f",&a);
	    printf("Enter value of b:");
	    fflush(stdout);
	    scanf("%f",&b);
	    temp=a;
	    a=b;
	    b=temp;

	    printf("After swapping, value of a=%8.1f\n",a);
	    printf("After swapping, value of b=%8.2f",b);
	}


