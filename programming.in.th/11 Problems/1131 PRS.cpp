#include<cstdio>
#define MOD 2553
int dp[1000002],dr[1000002],ds[1000002],n,ans=1;
char a[1000002];
int main(){
    scanf("%d %s",&n,a);
    dp[1]=dr[1]=ds[1]=1;
    dp[2]=dr[2]=ds[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=(dr[i-2]+ds[i-2]+dr[i-1]+ds[i-1])%MOD;
        dr[i]=(dp[i-2]+ds[i-2]+dp[i-1]+ds[i-1])%MOD;
        ds[i]=(dp[i-2]+dr[i-2]+dp[i-1]+dr[i-1])%MOD;
    }
    for(int i=0;i<n;i++){
        if(a[i]=='R' || a[i]=='S'){
            if(i>1 && a[i-1]=='P' && a[i-2]=='P');
            else if(i>0 && i<n-1 && a[i-1]=='P')  ans=(ans+dr[n-i-1]+ds[n-i-1])%MOD;
            else    ans=(ans+dp[n-i])%MOD;
        }
        if(a[i]=='S'){
            if(i>1 && a[i-1]=='R' && a[i-2]=='R');
            else if(i>0 && i<n-1 && a[i-1]=='R')  ans=(ans+dp[n-i-1]+ds[n-i-1])%MOD;
            else    ans=(ans+dr[n-i])%MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
