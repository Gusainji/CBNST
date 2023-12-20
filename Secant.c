#include<stdio.h>
#include <math.h> 
#define EPSILON 1e-6 
double function(double x) 
{     return cos(x) - x * exp(x); 
} 
double secant(double x0, double x1) 
{ 
    double x2; 
    int i = 0;     do 
    { 
        x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));         
        x0 = x1;         
        x1 = x2;         
        i++;         
        printf("Iteration %d: x = %lf, function(x) = %lf\n", i, x2, function(x2)); 
    } while (fabs(function(x2)) > EPSILON && i < 100);     
    return x2; 
} 
int main() 
{ 
    double x0 = 0.0;     
    double x1 = 1.0;     
    double root = secant(x0, x1);     
    printf("Approximate root: %lf\n", root);     
    return 0; 
} 	 
