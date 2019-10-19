#include<cstdio>
int n,sum=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("1 ");
        for(int j=2;j<=i;j++)
            printf("+ %d ",j);
        printf("= %d\n",(i*(i+1))/2);
        sum+=(i*(i+1))/2;
    }
    printf("sum = %d\n",sum);
    return 0;
}
