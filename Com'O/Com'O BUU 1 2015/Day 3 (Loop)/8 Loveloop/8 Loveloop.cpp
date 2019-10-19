#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",i+j);
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",(i+j)%n+1);
        printf("\n");
    }
    return 0;
}
