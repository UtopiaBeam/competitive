#include<cstdio>
int x,n,k,t=1;
int main(){
    scanf("%d %d %d",&x,&k,&n);
    for(int i=k-x%k;i<=n-x;i+=k)
        printf("%d ",i),t=0;
    if(t)   printf("-1\n");
    return 0;
}
