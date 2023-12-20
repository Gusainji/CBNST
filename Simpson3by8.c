#include <stdio.h>
float f(float x)
{
    return (1 / (1 + (x * x)));
}
int main()
{
    int i, n;
    float x0, xn, h, y[20], ans;
    printf("\n Enter values of x0, xn, h: ");
    scanf("%f%f%f", &x0, &xn, &h);
    n = (xn - x0) / h;
    if (n % 3 != 0)
    {
        printf("\n Error: Number of subintervals must be a multiple of 3.\n");
        return 1;
    }
    printf("\n Y values: \n");
    for (i = 0; i <= n; i++)
    {
        y[i] = f(x0 + i * h);
        printf("\n %f\n", y[i]);
    }
    ans = y[0] + y[n];
    for (i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            ans = ans + 2 * y[i];
        }
        else
        {
            ans = ans + 3 * y[i];
        }
    }
    ans = (3 * h / 8) * ans;
    printf("\n Final integration using Simpson's 3/8 rule is %f\n", ans);
    return 0;
}
