#include <stdio.h> 
void forward(int n, float x[n], float y[n][n])
{
    int i, j;
    float a; // interpolation point     
    printf("Enter Interpolation Point: ");     
    scanf("%f", &a);     float h, u, sum, temp;     
    for (j = 1; j < n; j++)         
    for (i = 0; i < n - j; i++)             
    y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
    printf("\nThe forward difference table is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n - i; j++)
            printf("%f\t", y[i][j]);
    }
    h = x[1] - x[0];
    sum = y[0][0];
    u = (a - x[0]) / h;
    temp = 1.0;
    for (j = 1; j < n; j++)
    {
        temp = temp * (u - j + 1) / j;
        sum = sum + temp * y[0][j];
    }
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}
int main()
{
    int i, j, n;
    printf("Enter number of arguments: ");
    scanf("%d", &n);
    float x[n];
    printf("Enter values of x: ");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);
    float y[n][n];
    printf("Enter values of y: ");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);
    forward(n, x, y);
    return 0;
}
