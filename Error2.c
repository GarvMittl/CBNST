#include<stdio.h>
#include<math.h>
int main(){
    float x=1.0/3.0;
    printf("The true value of 1/3 is %f\n",x);
    float ea1=fabs(x-0.30);
    printf("The approximated value is 0.30\n");
    printf("The error is %f\n",ea1);
    float ea2=fabs(x-0.33);
    printf("The approximated value is 0.33\n");
    printf("The error is %f\n",ea2);
    float ea3=fabs(x-0.34);
    printf("The approximated value is 0.34\n");
    printf("The error is %f\n",ea3);
    if (ea1<ea2 && ea1<ea3)
    {
        printf("The best approximated value is 0.30\n");
    }
    else if (ea2<ea3 && ea2<ea1)
    {
        printf("The best approximated value is 0.33\n");
    }
    else if (ea3<ea2 && ea3<ea1)
    {
        printf("The best approximated value is 0.34\n");
    }
}