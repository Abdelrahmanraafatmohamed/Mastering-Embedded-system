#include <stdio.h>
#include <string.h>
struct sempolyee
{
    char *name;
    int id;
}empolyee_1={"Alex",1002},empolyee_2={"Abdo",20},empolyee_3={"raafat",10},empolyee_4={"mohamed",50};
void main()
{    int i;
    struct sempolyee *p[]={&empolyee_1,&empolyee_2,&empolyee_3,&empolyee_4};
    struct sempolyee* (*pp)[4]=&p;
 for(i=0;i<4;i++)
 {
     printf("employee name: %s\n",(*(*(pp)+i))->name);
     printf("employee ID: %d\n",(*(*(pp)+i))->id);
     printf("...............................\n");
 }

}



