#include<cstdio>
#include<algorithm>
using namespace std;
int dp[505][505],n,a;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&dp[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
}
