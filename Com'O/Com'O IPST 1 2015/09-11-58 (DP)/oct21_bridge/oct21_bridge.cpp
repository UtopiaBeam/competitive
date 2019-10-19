#include<cstdio>
#include<algorithm>
int n,a[3002],b[3002],dp[2][3002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])      dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            else        dp[i%2][j]=std::max(dp[(i-1)%2][j],dp[i%2][j-1]);
    printf("%d\n",dp[n%2][n]);
    return 0;
}
