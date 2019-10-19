#include<cstdio>
int n,m,a[505],dp[2][50005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==a[i])     dp[i%2][j]=1;
            else            dp[i%2][j]=0;
            dp[i%2][j]+=dp[(i+1)%2][j];
            if(j>=a[i])     dp[i%2][j]+=dp[(i+1)%2][j-a[i]];
            dp[i%2][j]%=1000007;
        }
    }
    printf("%d\n",dp[n%2][m]);
    return 0;
}
