#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[2][5002],a[5002],b[5002];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i%2][j]=max(max(dp[i%2][j-1],dp[(i+1)%2][j]),dp[(i+1)%2][j-1]+abs(a[i]-b[j]));
    printf("%lld\n",dp[n%2][m]);
    return 0;
}
