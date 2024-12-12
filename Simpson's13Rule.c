//Simpson's 1/3 Rule
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return 1.0/(1.0+(x));
}
int main(){
    float a,b,h,x=0.0,y=0.0;
    int n;
    printf("\nEnter the no. of sub intervals:");
    scanf("%d",&n);
    if(n<=0 || n%2!=0){
        printf("\nThe no. of sub interval must be more than 0 and a even no for simpson's 1/3 rule.");
        return 1;
    }
    printf("\nEnter the lower limit and upper limit:");
    scanf("%f %f",&a,&b);
    if(b<=a){
        printf("\nThe upperlimit should be greater than the lower limit");
        retur  n 1;
    }
    h=(b-a)/n;
    float sum = sum + f(a) + f(b);
    for(int i=1;i<n;i++){
        if(i%2==0){
        x = a + (i*h);
        sum = sum + (2*f(x));
        }
        if(i%2!=0){
            x = a + (i*h);
            sum = sum + (4*f(x));
        }
    }
    sum = (h/3.0)*sum;
    printf("\nSimpson's 1/3 Rule");
    printf("\nThe approximated value of the intergral is : %.6f",sum);
    return 0;
}