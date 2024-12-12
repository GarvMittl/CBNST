//Iteration method 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return ((x*x*x)-(4*x)-9);
}
float q(float x){
    return (pow((4*x+9),1.0/3.0));
}
float dq(float x){
    return (pow((4.0/3.0)*(4*x+9),-2.0/3.0));
}
int main(){
    float er,x0,x;
    int flag=1,itr=0;
    do{
    printf("\nEnter the value of x0:");
    scanf("%f",&x0);
    if(fabs(dq(x0))<1){
        flag=1;
        printf("\nCondition Satisified");
    }
    else{
        printf("\nChange the Function");
        exit;
    }
    }while (flag!=1);
    printf("\nEnter the allowed error : ");
    scanf("%f",&er);
    do{
        itr++;
        printf("\n %d Iterations , value of x is %f , value of (%f) is %f", itr , x0 , x0 , f(x0));
        if(fabs(f(x0))<er){
        flag=0;
        printf("\n The real root of equation is %f after %d iterations",x0,itr);
        }
        else{
            x0=q(x0);
        }
    }while (flag!=0);    
}