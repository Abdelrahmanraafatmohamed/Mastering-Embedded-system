
#include <stdio.h>
struct scomplex
{
    float real;
    float imaginary;

}x,y,sum;
struct scomplex add_cmplexno( struct scomplex x ,struct scomplex y)
{
    printf("for 1st complex:");
    printf("\nenter real and imaginary respectively:");
    fflush(stdout);
    scanf("%f %f",&x.real,&x.imaginary);
    printf("for 2st complex:");
     printf("\nenter real and imaginary respectively:");
     fflush(stdout);
    scanf("%f %f",&y.real,&y.imaginary);
    sum.real=x.real+y.real;
    sum.imaginary=x.imaginary+y.imaginary;
    printf("sum=%.1f+%.1fi",sum.real,sum.imaginary);
};
void main()
{
   add_cmplexno(x,y);
}
