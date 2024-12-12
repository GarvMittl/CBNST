//newtonrapson
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return((x*x)-log(x)-12);
}
float df(float x){
    return((2*x)-(1/x));
}
int main(){
    float x0,x1,er;
    int flag = 0, itr = 0;
    do{
        printf("\n Enter the Value of x1 and x2 :");
        scanf("%f %f",&x0,&x1);
        if(f(x0)*f(x1)<0){
            flag=1;
            printf("\n The Root Lies between %f and %f  ",x0,x1);
        }
        else{
            printf("The entered values are wrong , try again ");
        }
    }while (flag!=1);
    printf("\n Enter the allowed error for the equation");
    scanf("%f",&er);
    do{
        itr++;
        x1=x0-(f(x0)/df(x0));
        printf("\n %d Iterations , value of x is %f , value of (%f) is %f", itr , x0 , x0 , f(x0));
        if((fabs(f(x1)))<=er){
            flag=0;
            printf("\n The Root of the equation is %f after %d iterations ",x0,itr);
        }
        else {
            x0=x1;
        }
    } while (flag!=0);
    return 0;
}
