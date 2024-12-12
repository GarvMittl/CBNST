//lagrange's formula 
#include<stdio.h>
#include<conio.h>
int main()
{
	 float x[100], y[100], x1, y1=0, p;
	 int i,j,n;
	 printf("Enter number of data: ");
	 scanf("%d",&n);
	 printf("Enter the value of x:\n");
	 for(i=0;i<n;i++)
	 {
        scanf("%f",&x[i]);
	 }
     printf("Enter the value of y:\n");
	 for(i=0;i<n;i++)
	 {
        scanf("%f",&y[i]);
	 }
	 printf("Enter the value x1 of which f(x1) should be calculated: ");
	 scanf("%f", &x1);
	 for(i=0;i<n;i++)
	 {
		  p=1;
		  for(j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p * (x1 - x[j])/(x[i] - x[j]);
			   }
		  }
		  y1 = y1 + p * y[i];
	 }
	 printf("The value of y  at %.3f is %.3f.", x1, y1);
     return 0;
}