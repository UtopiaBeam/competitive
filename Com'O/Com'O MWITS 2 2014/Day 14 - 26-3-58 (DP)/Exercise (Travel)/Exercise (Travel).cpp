#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1505],adj[1505][1505];
//sum[i] = sum of costs from 1 to i
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    dp[1]=adj[1][2];
    for(int i=3;i<=n;i++){
        int Min=1<<20,Min2=1<<20;
        for(int j=1;j<i-1;j++)
            Min=min(Min,dp[j]+adj[i][i-1]);
        for(int j=1;j<i-1;j++)
            Min2=min(Min2,dp[j]+adj[i][j]),dp[j]+=adj[i][i-1];
        dp[i-1]=Min2;
        dp[i]=min(Min,Min2);
    }
    printf("%d\n",dp[n]);
    return 0;
}
