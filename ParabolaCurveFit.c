#include <stdio.h> 

int main()
{
    float a[3][4], x[10], y[10], sx = 0, sy = 0, sx2 = 0, sx3 = 0, sx4 = 0, sxy = 0, sx2y = 0, a0, a1, a2;
    int i, j, k, t, n;
    printf("\nEnter the number of observations: ");
    scanf("%d", &n);
    printf("\nEnter the values of X: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\nEnter the values of Y: \n");
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
        sx += x[i];
        sy += y[i];
        sxy += (x[i] * y[i]);
        sx2 += (x[i] * x[i]);
        sx3 += (x[i] * x[i] * x[i]);
        sx4 +=
            (x[i] * x[i] * x[i] * x[i]);
        sx2y += (x[i] * x[i] * y[i]);
    }
    a[0][0] = n;
    a[0][1] = sx;
    a[0][2] = sx2;
    a[0][3] = sy;
    a[1][0] = sx;
    a[1][1] = sx2;
    a[1][2] = sx3;
    a[1][3] = sxy;
    a[2][0] = sx2;
    a[2][1] = sx3;
    a[2][2] = sx4;
    a[2][3] = sx2y;
    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            t = a[j][i] / a[i][i];
            for (k = 0; k < 4; k++)
            {
                a[j][k] = a[j][k] - a[i][k] * t;
            }
        }
    }
    printf("\n\nUpper triangle matrix is...\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf(" %.3f", a[i][j]);
        }
    }
    a2 = a[2][3] / a[2][2];
    a1 = (a[1][3] - a[1][2] * a2) / a[1][1];
    a0 = (a[0][3] - a[0][2] * a2 - a[0][1] * a1) / a[0][0];
    printf("\n\nThe parabolic curve is... Y = %.3f + %.3fX + %.3fX^2", a0, a1,
           a2);
    return 0;
}
