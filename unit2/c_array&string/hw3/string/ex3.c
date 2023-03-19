
#include <stdio.h>
int main()
{
	char a[1000],temp;
	int i,j;
	printf("enter the string");
	fflush(stdin); fflush(stdout);
	gets(a);
	i=0;
	j=strlen(a)-1;
	while (i<j)
	{
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	i++;
	j--;
	}
	printf("the reverse string is %s",a);
return(0);
}
