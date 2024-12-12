//secant method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return ((x*x)*(exp((-x)/2.0))-1);
}
int main(){
    float x0,x1,x2,er;
    int itr=0,flag=0;
    do
    {
        printf("\n Enter the Value of x0 and x1 :");
        scanf("%f %f",&x0,&x1);
        if((f(x0)*f(x1))<0){
            flag=1;
            printf("\n The Root Lies between %f and %f  ",x0,x1);
        }
        else{
            printf("The entered values are wrong , try again ");
        }
    } while (flag!=1);
    printf("\nEnter the allowed error : ");
    scanf("%f",&er);
    do{
        itr++;
        x2=(x1-(((x1-x0)/(f(x1)-f(x0)))*f(x1)));
        printf("\n %d Iterations , value of x is %f , value of (%f) is %f", itr , x2 , x2 , f(x2));
        if(fabs(f(x2))<=er){
            flag=0;
            printf("\n The real root of equation is %f after %d iterations",x2,itr);
        }
        else{
            x0=x1;
            x1=x2;
        }
    }while(flag!=0);    
}