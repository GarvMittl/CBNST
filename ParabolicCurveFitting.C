//Parabolic
#include <stdio.h>
int main() {
    int n, i;
    double x[100], y[100];
    double sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumXY = 0, sumX2Y = 0;
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
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }
    double A[3][4] = {
        {n, sumX, sumX2, sumY},       
        {sumX, sumX2, sumX3, sumXY}, 
        {sumX2, sumX3, sumX4, sumX2Y} 
    };
    for (i = 0; i < 3; i++) {
        double factor = A[i][i];
        for (int j = 0; j < 4; j++) {
            A[i][j] /= factor;
        }
        for (int k = 0; k < 3; k++) {
            if (k != i) {
                factor = A[k][i];
                for (int j = 0; j < 4; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    double c = A[0][3]; 
    double b = A[1][3]; 
    double a = A[2][3]; 
    printf("\nThe parabolic equation that fits the given data is:\n");
    printf("y = %.5lf * x^2 + %.5lf * x + %.5lf\n", a, b, c);
    return 0;
}
