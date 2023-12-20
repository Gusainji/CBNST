#include <stdio.h> 
float y(float x) 
{     return 1 / (1 + x * x); 
} 
float trapezoidal(float a, float b, float n) 
{ 
    float h = (b - a) / n;     
    float s = y(a) + y(b);     
    for (int i = 1; i < n; i++)         
    s += 2 * y(a + i * h);     
    return (h / 2) * s; 
} 
int main() 
{     float a, b;     
      int n; 
    printf("Enter the lower limit of integration (a): ");     
    scanf("%f", &a);     
    printf("Enter the upper limit of integration (b): ");     
    scanf("%f", &b);     
    printf("Enter the number of subintervals (n): ");     
    scanf("%d", &n);    
     printf("Value of integral is %6.4f\n",            
     trapezoidal(a, b, n));    
      return 0; 
} 
