#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n%2==0)      printf("error\n");
    else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<i;j++)
                printf(" ");
            for(int j=0;j<n-2*i;j++)
                printf("*");
            printf("\n");
        }
        for(int i=n/2;i>=0;i--){
            for(int j=0;j<i;j++)
                printf(" ");
            for(int j=0;j<n-2*i;j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
