
#include <stdio.h>
#define pl 3.14
#define area(r)(pl*(r)*(r))
void main()
{
    int radius;
    float area;
    printf("enter the radius:");
    fflush(stdout);
    scanf("%d",&radius);
    area=area(radius);
    printf("area=%0.2f",area);

}
