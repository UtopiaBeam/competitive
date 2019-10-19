#include<cstdio>
#include<algorithm>
#define L long long
using namespace std;
int n;
L l,w[20002],h[20002],dp[20002],qs[20002];
int main(){
    scanf("%d %lld",&n,&l);
    for(int i=1;i<=n;i++){
        dp[i]=1<<30;
        scanf("%lld %lld",&h[i],&w[i]);
    }
    for(int i=1;i<=n;i++)
        qs[i]=qs[i-1]+w[i];
    for(int i=1;i<=n;i++){
        L mx=0;
        for(int j=i;j>0 && qs[i]-qs[j-1]<=l;j--){
            mx=max(mx,h[j]);
            dp[i]=min(dp[i],dp[j-1]+mx);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
