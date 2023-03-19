
#include <stdio.h>
void main(void)
{
	 float a[2][2];
	    float b[2][2];
	    int i;
	    int j;
	    float sum[2][2];
	    printf("enter the element of 1st matrix\n");
	    fflush(stdin); fflush(stdout);
	    for (i=0;i<2;i++)
	        {
	        for (j=0;j<2;j++)
	        {
	            printf("enter a%d%d:",i+1,j+1);
	            fflush(stdin); fflush(stdout);
	            scanf("%f",&a[i][j]);

	        }
	        }
	printf("enter the element of 2nd matrix\n");
	 fflush(stdin); fflush(stdout);
	for (i=0;i<2;i++)
	        {
	        for (j=0;j<2;j++)
	        {
	            printf("enter b%d%d:",i+1,j+1);
	            fflush(stdin); fflush(stdout);
	            scanf("%f",&b[i][j]);

	        }
	        }

	printf("sum of matrix\n");
	 fflush(stdin); fflush(stdout);
	            for (i=0;i<2;i++)
	            {
	               for (j=0;j<2;j++)
	                 sum[i][j]=a[i][j]+b[i][j];
	            }

	               for (i=0;i<2;i++)
	            {
	               for (j=0;j<2;j++)
	               {
	                   printf("%.1f\t",sum[i][j]);
	               }

	               printf("\n");
	            }
}

