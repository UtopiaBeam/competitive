#include<cstdio>
int n,dp[5005][3];
char a[5005];
int main(){
    scanf("%d %s",&n,a);
    for(int l=2;l<=n;l++)
        for(int i=0;i<=n-l;i++){
            if(a[i]==a[i+l-1])  dp[i][l%3]=dp[i+1][(l-2)%3];
            else    dp[i][l%3]=(dp[i][(l-1)%3]<dp[i+1][(l-1)%3])*dp[i][(l-1)%3]+(dp[i][(l-1)%3]>=dp[i+1][(l-1)%3])*dp[i+1][(l-1)%3]+1;
        }
    printf("%d\n",dp[0][n%3]);
    return 0;
}
