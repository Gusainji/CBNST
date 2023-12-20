#include <stdio.h>
#include <math.h>
#define e 0.0001
#define f(x)cos(x) - x *exp(x) 
    int main()
{
    float f0, f1, f2, x0, x1, x2;
    printf("Enter the initial gusses x0 & x1:");
    scanf("%f%f", &x0, &x1);
    int i = 0;
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        if (f2 < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }
        i++;
        printf("\nNo. of Itration : %d", i);
        printf("\nRoot :  %f", x2);
        printf("\nvalue of function :  %f", f2);
    } while (fabs(f2) > e);
    return 0;
}
