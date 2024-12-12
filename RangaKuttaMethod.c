//Runge Kutta
#include<stdio.h>
#include<stdlib.h>
float f(float x,float y){
    return (((y*y)-(x*x))/((y*y)+(x*x)));
}
int main(){
    float x0,y0,xn,yn,h,k1,k2,k3,k4;
    int n;
    printf("\nEnter the value of x0: ");
    scanf("%f",&x0);
    printf("\nEnter the value of y0: ");
    scanf("%f",&y0);
    printf("\nEnter the value for x where y is to be calculated: ");
    scanf("%f",&xn);
    printf("\nEnter the no. of steps: ");
    scanf("%d",&n);
    h=(xn-x0)/n;
    printf("\nThe Intermediate Calculations are: ");
    printf("\nX\t\tY");
    for (int i = 0; i < n; i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2.0,y0+k1/2.0);
        k3=h*f(x0+h/2.0,y0+k2/2.0);
        k4=h*f(x0+h,y0+k3);
        yn=y0+((k1+2*k2+2*k3+k4)/6.0);
        x0=x0+h;
        y0=yn;
        printf("\n%f\t%f",x0,y0);
    }
    printf("\nThe value of x = (%f) at y = (%f)",xn,yn);
    return 0;
}