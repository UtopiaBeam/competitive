#include<cstdio>
#include<cstring>
int q,dp[5005][5005];
char a[5005];
int main(){
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof(dp));
        scanf(" %s",a);
        int n=strlen(a);
        for(int l=2;l<=n;l++)
            for(int i=0;i<=n-l;i++){
                if(a[i]==a[i+l-1])  dp[i][i+l-1]=dp[i+1][i+l-2];
                else    dp[i][i+l-1]=(dp[i][i+l-2]<dp[i+1][i+l-1])*dp[i][i+l-2]+(dp[i][i+l-2]>=dp[i+1][i+l-1])*dp[i+1][i+l-1]+1;
            }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
