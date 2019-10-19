#include<cstdio>
#include<cstring>
int n,k,dp[1002][10002];
int f(int n,int k){
    if(dp[n][k]!=-1)    return dp[n][k];
    if(n==0)    return dp[n][k]=0;
    if(k==0)    return dp[n][k]=1;
    int t=0;
    for(int i=0;i<n && k-i>=0;i++){
        t+=f(n-1,k-i);
        t%=1000000007;
    }
    return dp[n][k]=t;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&k);
    f(n,k);
    printf("%d\n",dp[n][k]);
    return 0;
}
