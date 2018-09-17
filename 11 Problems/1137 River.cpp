#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1000005],dp[1000005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    dp[1]=a[1],dp[2]=a[2],dp[3]=a[1]+a[2]+a[3];
    for(int i=4;i<=n;i++)
        dp[i]=min(a[i]+a[1]+a[i-1]+a[1],a[2]+a[1]+a[i]+a[2])+dp[i-2];
    printf("%lld\n",dp[n]);
    return 0;
}
