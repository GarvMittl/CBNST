// newton backward interpolation
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
    for(int i=1;i<n;i++){
        for(int j=n-1;j>=i;j--){
            y[j][i]=y[j][i-1]-y[j-1][i-1];
        }
    }
    printf("The forward difference table is :\n");     
    for(int i=0;i<n;i++){
        printf("%0.2f",x[i]);
        for(int j=0;j<=i;j++){
            printf("\t%0.2f",y[i][j]);
        }
        printf("\n");
    }
    float a,u,h,x1,u1;
    printf("Enter the value x1 of which f(x1) should be calculated :");
    scanf("%f",&x1);
    h=(x[1]-x[0]);
    u=(x1-x[n-1])/h;
    u1=u;
    a=y[n-1][0];
    for(int j=1;j<n;j++){
        a=a+u1*y[n-1][j]/fact;
        u1=u1*(u+j);
        fact=fact*(j+1);
    }
    printf("the value of f(%d) is %0.8f",x1,a);
}    