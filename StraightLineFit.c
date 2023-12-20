#include <stdio.h> 
int main()
{
    float a[2][3], x[10], y[10], sx = 0, sy = 0, sx2 = 0, sxy, a1, b;
    int i, j, k, t, n;
    printf("\nEnter the no. of observations...");
    scanf("%d", &n);
    printf("\nEnter the values of X \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\nEnter the values of Y \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    printf("\n X \tY\n");
    for (i = 0; i < n; i++)
    {
        printf("\n %.3f %.3f", x[i], y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sx = sx + x[i];
        sy = sy + y[i];
        sxy = sxy + (x[i] * y[i]);
        sx2 = sx2 + (x[i] * x[i]);
    }
    a[0][0] = n;
    a[0][1] = sx;
    a[0][2] = sy;
    a[1][0] = sx;
    a[1][1] = sx2;
    a[1][2] = sxy;
    for (i = 0; i < 1; i++)
    {
        for (j = i + 1; j < 2; j++)
        {
            t = a[j][i] / a[i][i];
            for (k = 0; k < 3; k++)
            {
                a[j][k] = a[j][k] - a[i][k] * t;
            }
        }
    }
    printf("\n\nUpper triangle matrix is...\n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf(" %.3f", a[i][j]);
        }
    }
    b = a[1][2] / a[1][1];
    a1 = (a[0][2] - a[0][1] * b) / a[0][0];
    printf("\n\nThe line is...Y = %.3f + %.3fX", a1, b);
    return 0;
}
