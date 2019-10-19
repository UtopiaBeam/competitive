#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
long long sum[5005],a[5005],dp[5005][5005];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<m;i++)
        sum[i]=a[i]+(i>0)*sum[i-1];
    for(int i=m;i<n;i++)
        sum[i]=sum[i-1]+a[i]-a[i-m];
    for(int i=0;i<n;i++)
        for(int j=1;j<=k;j++)
            dp[i][j]=sum[i];
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(i>=m)    dp[i][j]=max(dp[i][j],dp[i-m][j-1]+sum[i]);
        }
    }
    printf("%I64d\n",dp[n-1][k]);
    return 0;
}
