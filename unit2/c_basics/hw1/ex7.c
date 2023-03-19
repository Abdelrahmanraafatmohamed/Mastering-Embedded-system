
#include <stdio.h>
void main()
{    float a,b;
    printf("enter value of a:");
    fflush(stdout);
    scanf("%f",&a);
    printf("enter value of b:");
    fflush(stdout);
    scanf("%f",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("after swapping, value of a=%.2f",a);
    printf("\nafter swapping, value of b=%.2f",b);
}
