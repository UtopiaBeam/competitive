#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[3005],b[3005],dp[3005][3005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])      dp[i][j]=dp[i-1][j-1]+1;
            else        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][n]);
    return 0;
}
