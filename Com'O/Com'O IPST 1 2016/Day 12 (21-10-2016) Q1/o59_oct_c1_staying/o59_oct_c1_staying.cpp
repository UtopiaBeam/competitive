#include<cstdio>
#define MOD (int)(1e9+7)
int n,a,b,c,dp[1002][3];
int main(){
    scanf("%d %d %d %d",&n,&a,&b,&c);
    dp[1][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c && j<i;j++)
            dp[i][0]=(dp[i][0]+dp[i-j][2])%MOD;
        for(int j=1;j<=a && j<i;j++){
            dp[i][1]=(dp[i][1]+dp[i-j][0])%MOD;
            dp[i][2]=(dp[i][2]+dp[i-j][0])%MOD;
        }
        for(int j=1;j<=b && j<i;j++)
            dp[i][2]=(dp[i][2]+dp[i-j][1])%MOD;
    }
    int sum=0;
    for(int i=0;i<3;i++)
        sum=(sum+dp[n][i])%MOD;
    printf("%d\n",sum);
    return 0;
}
