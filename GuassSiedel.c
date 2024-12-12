//Guass Siedel
#include<stdio.h>
#include<math.h>
float f1(int x , int y , int z){
    return((44-y-(2*z))/10.0);
}
float f2(int x , int y , int z){
    return ((51-(2*x)-z)/10.0);
}
float f3(int x , int y , int z){
    return ((61-x-(2*y))/10.0);
}
int main(){
    float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
    int count=1;
    printf("\nenter the allowed error : ");
    scanf("%f", &e);
    if(fabs(10)>=fabs(-1)+fabs(-2) && fabs(10)>=fabs(-2)+fabs(-1) && fabs(10)>=fabs(-1)+fabs(-2)){
        do{
            x1=f1(x0,y0,z0);
            y1=f2(x1,y0,z0);
            z1=f3(x1,y1,z0);
            printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count,x1,y1,z1);
            e1=fabs(x0-x1);
            e2=fabs(y0-y1);
            e3=fabs(z0-z1);
            x0=x1;
            y0=y1;
            z0=z1;
            count++;
        }while (e1>e && e2>e && e3>e);
        printf("\n The value of \n x is %0.4f \n y is %0.4f \n z is %0.4f \n",x1,y1,z1);
        return 0;
    }
}