#include<cstdio>
long long n,dp[505][505];
int main(){
    scanf("%I64d",&n);
    for(int i=0;i<=n;i++)   dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(i>=j)   dp[i][j]+=dp[i-j][j-1];
        }
    }
    printf("%I64d\n",dp[n][n-1]);
    return 0;
}
