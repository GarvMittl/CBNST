//REGRESSION
#include <stdio.h>

int main() {
    int n, i;
    double x[100], y[100];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    double m1, c1, m2, c2;
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
        sumY2 += y[i] * y[i];
    }
    double meanX = sumX / n;
    double meanY = sumY / n;
    m1 = (sumXY - n * meanX * meanY) / (sumX2 - n * meanX * meanX);
    c1 = meanY - m1 * meanX;
    m2 = (sumXY - n * meanX * meanY) / (sumY2 - n * meanY * meanY);
    c2 = meanX - m2 * meanY;
    printf("\nThe regression line of y on x is:\n");
    printf("y = %.5lf * x + %.5lf\n", m1, c1);
    printf("\nThe regression line of x on y is:\n");
    printf("x = %.5lf * y + %.5lf\n", m2, c2);
    return 0;
}
