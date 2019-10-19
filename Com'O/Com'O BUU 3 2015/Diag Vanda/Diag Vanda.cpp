#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[402][402],dp[2][402][402],mx=-1e9;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            dp[0][i][j]=a[i][j]+dp[0][i-1][j-1];
            dp[1][i][j]=a[i][j]+dp[1][i-1][j+1];
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n-k+1;i++)
            for(int j=1;j<=n-k+1;j++)
                mx=max(mx,dp[0][i+k-1][j+k-1]-dp[0][i-1][j-1]-dp[1][i+k-1][j]+dp[1][i-1][j+k]);
    printf("%d\n",mx);
    return 0;
}