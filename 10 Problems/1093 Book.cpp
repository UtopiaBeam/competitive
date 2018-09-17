#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2002],dp[2][2002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        dp[0][i]=-1<<30;
    for(int i=1;i<=n;i++){
        dp[i&1][0]=max(dp[!(i&1)][2]-a[i],dp[!(i&1)][0]);
        for(int j=1;j<=n;j++)
            dp[i&1][j]=max(dp[!(i&1)][j-1]+a[i],dp[!(i&1)][j+2]-a[i]);
    }
    printf("%d\n",dp[n&1][0]);
    return 0;
}
