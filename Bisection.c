//bisection method
#include<stdio.h>
#include<math.h>
float f(float x){
    double a=log10(x);
    return((x*a)-1.2);
}
int main(){
    float x,x1,x2,er;
    int flag = 0, itr = 0;
    do{
        printf("\n Enter the Value of x1 and x2 :");
        scanf("%f %f",&x1,&x2);
        if(f(x1)*f(x2)<0){
            flag=1;
            printf("\n The Root Lies between %f and %f  ",x1,x2);
        }
        else{
            printf("The entered values are wrong , try again ");
        }
    }while (flag!=1);
    printf("\n Enter the allowed error for the equation");
    scanf("%f",&er);
    do
    {
        itr++;
        x=(x1+x2)/2;
        printf("\n %d Iterations , value of x is %f , value of (%f) is %f", itr , x , x , f(x));
        if((fabs(f(x)))<=er){
            flag=0;
            printf("\n The Root of the equation is %f after %d iterations ",x,itr);
        }
        else if (f(x)*f(x1)<0)
        {
            x2=x;
        }
        else{
            x1=x;
        }
    } while (flag!=0);
    return 0;
}
