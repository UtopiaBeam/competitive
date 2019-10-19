#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
long long a[1000002],sum=0,mx=0,dp=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        a[i]+=a[i-1];
    }
    dp=mx=a[k];
    for(int i=k+1;i<=n;i++){
        dp=max(a[i]-a[i-k],dp+a[i]-a[i-1]);
        mx=max(dp,mx);
    }
    printf("%lld\n",mx);
    return 0;
}
