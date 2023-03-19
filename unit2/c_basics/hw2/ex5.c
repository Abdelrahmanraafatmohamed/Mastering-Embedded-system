
#include <stdio.h>
void main(void)
{
	char ch;
	printf(" enter a character:");
	fflush(stdout);
	scanf("%c",&ch);
	if ((ch>='a' && ch<='z')  || (ch>='A' && ch<='Z'))
	    printf("%c is an alphabet",ch);
	else
	   printf("%c is not an alphabet",ch);

	}


