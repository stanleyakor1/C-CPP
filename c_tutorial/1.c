#include<stdio.h>
#include<stdlib.h>

/* swap two variables*/

void swaping(double *a,double *b){
    double temp = *a;
    *a=*b;
    *b=temp;
}

int main()
{
 double a = 1.0, b=5.0;
 double *A =&a;
 double *B=&b;
 swaping(A,B);
 printf(" A is %g\n",*A);
 printf(" B is %g\n",*B);

}