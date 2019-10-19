#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++)  printf(".");
        printf("*");
        for(int j=0;j<2*i-1;j++)    printf("-");
        if(i && i<n-1)   printf("*");
        for(int j=0;j<2*n-3-2*i;j++)    printf(".");
        if(i)   printf("*");
        for(int j=0;j<2*i-1;j++)    printf("-");
        printf("*");
        for(int j=1;j<n-i;j++)  printf(".");
        printf("\n");
    }
    for(int i=0;i<2*n-2;i++){
        for(int j=0;j<=i;j++)   printf(".");
        if(i<2*n-3)     printf("*");
        for(int j=0;j<4*n-7-2*i;j++)    printf("-");
        printf("*");
        for(int j=0;j<=i;j++)   printf(".");
        printf("\n");
    }
    return 0;
}
