#include<stdio.h>
#include<math.h>
int main(){
    float a;
    float b;
    printf("Enter the approximated value of underroot 2:\n");
    scanf("%f",&b);
    a=sqrt(2);
    printf("The accurate value of underroot 2 is %f\n",a);
    float eq=fabs(a-b);
    float er=fabs(eq/a);
    float ep=er*100;
    printf("The absloute error is %f\n",eq);
    printf("The relative error is %f\n",er);
    printf("The percentage error is %f\n",ep);
    return 0;
}