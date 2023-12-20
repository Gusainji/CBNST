#include <stdio.h> 
void backward(int n, float x[n], float y[n][n])
{
    int i, j;
    float a; // interpolation point 
    printf("Enter Interpolation Point: "); 
    scanf("%f", &a); 
    float h, u, sum, temp; 
    for (j = 1; j < n; j++) 
    for (i = n - 1; i >= j; i--) 
    y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
    printf("\nThe backward difference table is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= i; j++)
            printf("%f\t", y[i][j]);
    }
    h = x[1] - x[0];
    sum = y[n - 1][0];
    u = (a - x[n - 1]) / h;
    temp = 1.0;
    for (j = 1; j < n; j++)
    {
        temp = temp * (u + j - 1) / j;
        sum = sum + temp * y[n - 1][j];
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
    backward(n, x, y);
    return 0;
}
