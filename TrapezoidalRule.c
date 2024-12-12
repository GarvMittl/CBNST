//Trapezoidal Rule
#include<stdio.h>
float f(float x){
    return 1.0/(1.0+(x*x));
}
int main(){
    float n,a,b,h,x=0.0,y=0.0;
    printf("\nEnter the no. of sub intervals:");
    scanf("%f",&n);
    if(n<=0){
        printf("\nThe no. of sub interval must be more than Zero");
        return 1;
    }
    printf("\nEnter the lower limit and upper limit:");
    scanf("%f %f",&a,&b);
    if(b<=a){
        printf("\nThe upperlimit should be greater than the lower limit");
        return 1;
    }
    h=(b-a)/n;
    float sum = sum + f(a) + f(b);
    for(int i=1;i<n;i++){
        x = a + (i*h);
        sum = sum + (2*f(x));
    }
    sum = (h/2.0)*sum;
    printf("\nTrapezoidal Rule");
    printf("\nThe approximated value of the intergral is : %.6f ",sum);
    return 0;
}