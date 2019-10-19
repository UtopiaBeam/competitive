#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=2*n;i++)
        printf("*");
    printf("\n");
    for(int i=1;i<2*n;i++){
        if(i%2==0){
            for(int j=0;j<i/2;j++)  printf("**");
            for(int j=0;j<n-i/2;j++)    printf("*-");
        }
        else{
            printf("*-");
            for(int j=0;j<i/2;j++)  printf("--");
            for(int j=1;j<n-i/2;j++)    printf("*-");
        }
        printf("*\n");
    }
    for(int i=0;i<=2*n;i++)
        printf("*");
    printf("\n");
    return 0;
}
