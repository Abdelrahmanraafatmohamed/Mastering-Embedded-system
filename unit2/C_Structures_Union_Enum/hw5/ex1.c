
#include <stdio.h>
struct data
{
    char name[50];
    int roll;
    float marks;

}s;
void main()
{
    printf("enter information of students:");
    printf("\nenter name:");
    fflush(stdout);
    scanf("%s",s.name);
    printf("enter roll number:");
    fflush(stdout);
    scanf("%d",&s.roll);
    printf("enter marks:");
    fflush(stdout);
    scanf("%f",&s.marks);
    printf("displaying information");
    printf("\nname:%s\nroll:%d\nmarks:%.2f",s.name,s.roll,s.marks);
}






