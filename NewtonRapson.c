#include <stdio.h> 
#include <math.h> 
double f(double x)
{
    return x * x * x - 5 * x + 1;
}
double df(double x)
{
    return 3 * x * x - 5;
}
double newtonRaphson(double x0, double epsilon, int maxIterations)
{
    int i = 1;
    double x = x0;
    while (i < maxIterations)
    {
        double fx = f(x);
        double dfx = df(x);
        if (fabs(dfx) < epsilon)
        {
            printf("Derivative is close to zero. Exiting...\n");
            return NAN;
        }
        double deltaX = -fx / dfx;
        x = x + deltaX;
        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x, fx);
        if (fabs(deltaX) < epsilon)
        {
            printf("Root found after %d iterations: %lf\n", i, x);
            return x;
        }
        i++;
    }
    printf("Max iterations reached without convergence.\n");
    return NAN;
}
int main()
{
    double initialGuess = 0.5;
    double epsilon = 1e-6;
    int maxIterations = 100;
    double root = newtonRaphson(initialGuess, epsilon, maxIterations);
    if (!isnan(root))
    {
        printf("Approximate root: %lf\n", root);
    }
    else
    {
        printf("Newton-Raphson method did not converge.\n");
    }
    return 0;
}
