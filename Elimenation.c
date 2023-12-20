#include <stdio.h> 
#define n 3 
void gaussianElimination(float mat[n][n + 1])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        int max_row = i;
        for (j = i + 1; j < n; j++)
        {
            if (mat[j][i] > mat[max_row][i])
                max_row = j;
        }
        for (k = i; k <= n; k++)
        {
            float temp = mat[i][k];
            mat[i][k] = mat[max_row][k];
            mat[max_row][k] = temp;
        }
        for (j = i + 1; j < n; j++)
        {
            float factor = mat[j][i] / mat[i][i];
            for (k = i; k <= n; k++)
            {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }
    float x[n];
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = mat[i][n];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }
    printf("Solution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }
}
void printMatrix(float mat[n][n + 1])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    float mat[n][n + 1];
    printf("Enter the coefficients and constants of the linear equations:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("Enter the value for mat[%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    printf("Original Augmented Matrix:\n");
    printMatrix(mat);
    gaussianElimination(mat);
    return 0;
}
