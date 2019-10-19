#include<cstdio>
int n,m;
long long cnt=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        cnt+=m/5+(m%5>=5-(i%5));
    printf("%I64d\n",cnt);
    return 0;
}
