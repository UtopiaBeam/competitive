#include<cstdio>
#include<algorithm>
using namespace std;
int a[5002][5002],dp[5002],n,f[5002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+a[i-1][i];
    dp[1]=a[1][2];
    for(int i=3;i<=n;i++){
        int mn1=1<<30,mn2=1<<30;
        for(int j=1;j<i-1;j++)
            mn1=min(mn1,dp[j]+a[i-1][i]);
        for(int j=1;j<i-1;j++){
            mn2=min(mn2,dp[j]+a[j][i]);
            dp[j]+=a[i-1][i];
        }
        dp[i-1]=mn2;
        dp[i]=min(mn1,mn2);
    }
    printf("%d\n",dp[n]);
    return 0;
}
