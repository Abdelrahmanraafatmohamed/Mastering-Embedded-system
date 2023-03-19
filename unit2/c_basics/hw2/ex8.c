
#include <stdio.h>
void main(void)
{
	char op;
	float n1, n2 , sum , sub, div, mult;
	printf("enter the operator either + or - or * or /:");
	fflush(stdout);
	scanf("%c",&op);
	printf("enter two operands:");
	fflush(stdout);
	scanf("%f %f",&n1,&n2);
	switch(op)
	{

	case '+':
	    sum=n1+n2;
	    printf("%.1f %c %.1f=%.1f",n1,op,n2,sum);  break;
	    case '-':
	    sub=n1-n2;
	    printf("%.1f %c %.1f=%.1f",n1,op,n2,sub); break;
	    case '*':
	    mult=n1*n2;
	    printf("%.1f %c %.1f =%.1f",n1,op,n2,mult);  break;
	    case '/':
	    div=n1/n2;
	    printf("%.1f %c %.1f=%.1f",n1,op,n2,div);

	}

}

