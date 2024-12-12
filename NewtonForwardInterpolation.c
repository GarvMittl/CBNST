//newton forward interpolation
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int n,fact=1;
    printf("Enter the no. of datapoints:");
    scanf("%d",&n);
    float x[100],y[100][100];
    printf("Enter the values of x:");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }
    printf("Enter the values of y:");
    for(int i=0;i<n;i++){
        scanf("%f",&y[i][0]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            y[j][i+1]=y[j+1][i]-y[j][i];
        }
    }
    printf("The forward difference table is :\n");
    for(int i=0;i<n;i++){
        printf("%0.2f",x[i]);
        for(int j=0;j<n-i;j++){
            printf("\t%0.2f",y[i][j]);
        }
        printf("\n");
    }
    float a,u,h,x1,u1;
    printf("Enter the value x1 of which f(x1) should be calculated :");
    scanf("%f",&x1);
    h=(x[1]-x[0]);
    u=(x1-x[0])/h;
    u1=u;
    a=y[0][0];
    for(int j=1;j<n;j++){
        a=a+u1*y[0][j]/fact;
        u1=u1*(u-j);
        fact=fact*(j+1);
    }
    printf("the value of f(%d) is %0.8f",x1,a);
}    