#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2-i;j++)
            printf("-");
        for(int j=0;j<=2*i;j++)
            printf("*");
        for(int j=0;j<n/2-i;j++)
            printf("-");
        printf("\n");
    }
    for(int i=n/2;i>=0;i--){
        for(int j=0;j<n/2-i;j++)
            printf("-");
        for(int j=0;j<=2*i;j++)
            printf("*");
        for(int j=0;j<n/2-i;j++)
            printf("-");
        printf("\n");
    }
    return 0;
}
