
#include <stdio.h>
struct data
{
    char name[50];
    int roll;
    float marks;

}x[10];
void main()
{
    int i;
    printf("enter information of students:");
    for (i=0;i<10;i++)
    {
       x[i].roll=i+1;
      printf("\nenter roll number:%d",x[i].roll);
      printf("\nenter name:");
      fflush(stdout);
      scanf("%s",x[i].name);
      printf("enter marks:");
      fflush(stdout);
      scanf("%f",&x[i].marks);
    }

    printf("displaying information");
    for (i=0;i<10;i++)
    {
        printf("\nroll number:%d",x[i].roll);
        printf("\nname:%s",x[i].name);
        printf("\nmarks:%.1f",x[i].marks);
    }
}
