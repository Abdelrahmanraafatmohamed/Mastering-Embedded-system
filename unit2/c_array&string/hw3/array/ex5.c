
#include <stdio.h>
int main()
{ int n,i;
int a[100];
int search,location;
printf("\nenter no. of elements:");
fflush(stdin);  fflush(stdout);
scanf("%d",&n);
for (i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
printf("enter the number to be searched:");
fflush(stdin);  fflush(stdout);
scanf("%d",&search);
location=-1;
for(i=0;i<n;i++)
if(a[i]==search)
{
    location=i;
    break;
}
if(location==-1)
    printf("the number to be searched not found");
else
    printf("number found at location=%d",location+1);
return(0);
}
