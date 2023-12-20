#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float p, sum = 0.0;
    printf("\nEnter the no. of DATA: ");
    scanf("%d", &n);
    float xn[n], fn[n];
    printf("\nEnter the values:\n");
    for (int i = 0; i < n; i++) {
        printf("xn[%d]: ", i + 1);
        scanf("%f", &xn[i]);
        printf("fn[%d]: ", i + 1);
        scanf("%f", &fn[i]);
    }
    float x; // interpolation point
    printf("\nEnter interpolation point: ");
    scanf("%f", &x); // Change %d to %f
    for (int i = 0; i < n; i++) {
        p = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p = p * (x - xn[j]) / (xn[i] - xn[j]);
            }
        }
        sum = sum + p * fn[i];
    }
    printf("Interpolated value at %.3f is %.3f.\n", x, sum); // Added \n at the end
    return 0;
}
