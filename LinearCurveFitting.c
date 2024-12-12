//linear curve fitting
#include <stdio.h>
int main() {
    int n, i;
    double x[100], y[100];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }
    for (i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    double A[2][3] = {
        {n, sumX, sumY},       
        {sumX, sumX2, sumXY}   
    };
    for (i = 0; i < 2; i++) {
        double factor = A[i][i];
        for (int j = 0; j < 3; j++) {
            A[i][j] /= factor;
        }
        for (int k = 0; k < 2; k++) {
            if (k != i) {
                factor = A[k][i];
                for (int j = 0; j < 3; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    double b = A[0][2]; 
    double a = A[1][2]; 
    printf("\nThe linear equation that fits the given data is:\n");
    printf("y = %.5lf * x + %.5lf\n", a, b);
return 0;
}
