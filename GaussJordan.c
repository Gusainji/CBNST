#include <stdio.h>
#include <math.h> 
#define n 3 
void gaussJordanMetod(float mat[n][n + 1])
{
    int i, j, k;
    float c, x[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c = mat[j][i] / mat[i][i];
            if (j != i)
            {
                for (k = 0; k <= n; k++)
                {
                    mat[j][k] -= c * mat[i][k];
                }
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        x[i] = mat[i][n] / mat[i][i];
    }
    printf("\nSolution: \n");
    for (i = 0; i < n; i++)
    {
        printf("\nx%d = %.2f", i + 1, x[i]);
    }
}
int main()
{
    float mat[n][n + 1];
    printf("\nEnter the cofficient and constants from liner equations: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("mat[%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    printf("Original Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
    gaussJordanMetod(mat);
    return 0;
}
