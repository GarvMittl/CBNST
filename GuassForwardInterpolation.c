//gauss forward interpolation
#include <stdio.h>
#include <math.h>
int main() {
    int n, fact = 1;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[100], y[100][100];
    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("The forward difference table is:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.4f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%0.4f", y[i][j]);
        }
        printf("\n");
    }
    float x1, u, h, sum;
    printf("Enter the value of x1 to find f(x1): ");
    scanf("%f", &x1);
    h = x[1] - x[0]; 
    int index = 0;
    while (index < n - 1 && x1 > x[index]) {
        index++;
    }
    index--;
    u = (x1 - x[index]) / h;
    printf("the value of u is %0.3f\n",u);
    sum = y[index][0];
    float u_term = 1;
    for (int i = 1; i < n; i++) {
        u_term *= (u - i + 1);
        fact *= i;
        sum += (u_term * y[index][i]) / fact;
    }
    printf("The interpolated value of y at x = %0.6f is %0.6f\n", x1, sum);
    return 0;
}
