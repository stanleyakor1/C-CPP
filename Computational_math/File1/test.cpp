#include "main.h"
int main()
{
    float a = 0.0, b =1.0;
    int N = 100;
    vector<double> x ;
    
   
    x = linspace(a,b,N);
 
    for (int i = 0; i<x.size(); i++)
        printf("x = %f\n", x[i]);

    
    return (0);
}
