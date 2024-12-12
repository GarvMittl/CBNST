//simpson's 3/8 rule
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return 1.0/(1.0+(x*x));
}
int main(){
    float a,b,h,x=0.0,y=0.0;
    int n;
    printf("\nEnter the no. of sub intervals:");
    scanf("%d",&n);
    if(n<=0 || n%3!=0){
        printf("\nThe no. of sub interval must be more than 0 and a multiple of 3 for simpson's 3/8 rule.");
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
        if(i%3==0){
        x = a + (i*h);
        sum = sum + (2*f(x));
        }
        if(i%3!=0){
            x = a + (i*h);
            sum = sum + (3*f(x));
        }
    }
    sum = (3.0*h/8.0)*sum;
    printf("\nSimpson's 3/8 Rule");
    printf("\nThe approximated value of the intergral is : %.6f",sum);
    float p=4*sum;
    printf("\n the value of pie is %.6f",p);
    return 0;
}