
#include <stdio.h>
struct distance
{
    int feet;
    float inch;

}x,y,sum;
void main()
{
    printf("enter information for 1st distance:");
    printf("\nenter feet:");
    fflush(stdout);
    scanf("%d",&x.feet);
    printf("enter inch:");
    fflush(stdout);
    scanf("%f",&x.inch);
    printf("\nenter information for 2st distance:");
    printf("\nenter feet:");
    fflush(stdout);
    scanf("%d",&y.feet);
    printf("enter inch:");
    fflush(stdout);
    scanf("%f",&y.inch);
    sum.feet=x.feet+y.feet;
    sum.inch=x.inch+y.inch;
    if(sum.inch>12)
    {
        sum.inch-=12;
        ++sum.feet;
    }
    printf("\nsum of distances=%d feet,,%.1f inch",sum.feet,sum.inch);
}
