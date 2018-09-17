#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    if(n%2){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                if(i+j==n/2||i+j==n/2*3||i-j==n/2||j-i==n/2)
                    printf("*");
                else    printf("-");
            printf("\n");
        }
    }
   else{
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++)
                if(i+j==n/2-1||j-i==n/2-1||i-j==n/2||i+j==n/2*3-2)
                    printf("*");
                else    printf("-");
            printf("\n");
        }
    }
    return 0;
}
