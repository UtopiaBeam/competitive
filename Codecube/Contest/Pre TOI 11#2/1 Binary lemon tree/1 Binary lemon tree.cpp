#include<cstdio>
long long c[10005]={1};
int n;
int main(){
    for(int i=1;i<=10000;i++)
        for(int j=0;j<i;j++)
            c[i]+=c[j]*c[i-j-1],c[i]%=909091;
    scanf("%d",&n);
    printf("%lld\n",c[n]);
    return 0;
}
