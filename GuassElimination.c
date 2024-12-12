//guass elimination
#include<stdio.h>
int main(){
    int n;
    float c;
    float M[20][20],X[10];
    printf("Enter the order of matrix :");
    scanf("%d",&n);
    printf("Enter the elements of augmented matrix row wise : ");
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ;  j<=n+1 ; j++){
            printf("M[%d][%d] : ",i,j);
            scanf("%f",&M[i][j]);
        }
    }
    for(int j =1 ; j<=n ; j++){
        for(int i =1 ; i<=n ; i++){
            if(i>j){
                c=M[i][j]/M[j][j];
            for(int k=1; k<=n+1 ; k++){
                M[i][k]=M[i][k]-(c*(M[j][k]));
            }
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ;  j<=n+1 ; j++){
            printf("%f ",M[i][j]);
        }
        printf("\n");
    }
    X[n]=M[n][n+1]/M[n][n];
    for(int i=n-1 ; i>=1 ; i--){
        float sum=0;
        for(int j=i+1 ; j<=n ; j++){
            sum = sum + M[i][j]*X[j];
        }
        X[i]=(M[i][n+1]-sum)/M[i][i];
    }
    printf("\n The solution for the equations is :\n");
    for(int i=1 ; i<=n ; i++){
        printf("\n x%d = %f \t ",i,X[i]);
    }
    return 0;
}
