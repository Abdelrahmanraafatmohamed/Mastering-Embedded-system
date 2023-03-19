
#include <stdio.h>
int main()
{
	 char a[100];
	 char ch;
	 int i,count=0;
	 printf("Enter a string:");
	 fflush(stdin);  fflush(stdout);
	 gets(a);
	 printf("Enter a character to find frequency:");
	 fflush(stdin);  fflush(stdout);
	 scanf("%c",&ch);
	 for (i=0;a[i]!='\0';i++)
	    {
	      if(a[i]==ch)
	        count++;
	    }

	        printf("frequency of %c = %d",ch,count);
return(0);
}
