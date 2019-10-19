#include<cstdio>
int n,m,k;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    printf("%d %d ",((k+1)/2-1)/m+1,((k+1)/2-1)%m+1);
    if(k&1)     printf("L\n");
    else        printf("R\n");
    return 0;
}
