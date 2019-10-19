#include<stdio.h>

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n-1;j++)
            if(i+j==n+1||j-i==n-1)    printf("*");
            else if(i+j>n&&j-i<n-1)   printf("-");
            else    printf(".");
        for(j=1;j<=2*n-2;j++)
            if(i+j==n||j-i==n-2)    printf("*");
            else if(i+j>n&&j-i<n-1)   printf("-");
            else    printf(".");
        printf("\n");
    }
    for(i=1;i<=2*n-2;i++){
        for(j=1;j<=4*n-3;j++)
            if(j==i+1||i+j==4*n-3)      printf("*");
            else if(j>i+1&&i+j<4*n-3)   printf("-");
            else    printf(".");
        printf("\n");
    }
    return 0;
}
