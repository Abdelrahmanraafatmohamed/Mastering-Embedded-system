
#include <stdio.h>
int main()
{
	 char a[100];
	 char ch;
	 int i,count=0;
	 printf("Enter a string:");
	 fflush(stdin);  fflush(stdout);
	 gets(a);
	 for(i=0;a[i]!=0;i++)
	 {
	     count++;
	 }
	 printf("lenght of string:%d",count);
return(0);
}
