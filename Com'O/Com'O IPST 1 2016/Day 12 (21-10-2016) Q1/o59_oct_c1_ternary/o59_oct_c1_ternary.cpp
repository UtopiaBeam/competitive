#include<cstdio>
int n,p[102],in[102],cnt=0;
long long c[202]={1};
int main(){
    scanf("%d",&n);
    for(int i=0;i<=200;i++)
        for(int j=0;j<=i;j++)
            c[i+1]+=(c[j]%1000000007)*(c[i-j]%1000000007),c[i+1]%=1000000007;
    for(int i=0;i<n;i++)
        scanf("%d",p+i);
    for(int i=0;i<n;i++)
        scanf("%d",in+i);
    int s=0;
    for(int i=0;i<n;i++)
        if(p[s]==in[i])
            cnt++,s=i+1;
    printf("%lld\n",(c[cnt]%1000000007));
    return 0;
}
