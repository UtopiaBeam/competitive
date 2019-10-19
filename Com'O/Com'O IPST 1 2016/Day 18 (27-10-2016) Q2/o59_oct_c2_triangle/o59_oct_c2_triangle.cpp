#include<cstdio>
#define MOD (int)(1e9+7)
int dp[102][102],k;
int f(int n,int m,int cnt,int lv){
//    for(int i=0;i<lv;i++)   printf(" ");
//    printf("f(%d, %d, %d)\n",n,m,cnt);
    if(n<0 || m<0)      return 0;
    if(n==0 || m==0){
        if(cnt==0)      return 0;
//        for(int i=0;i<lv;i++)   printf(" ");
//        printf("+1\n");
        return 1;
    }
    if(dp[n][m])    return 1;
    for(int i=1;i<=k;i++)
        dp[n][m]=(dp[n][m]+f(n-1,m-1-i,cnt+1,lv+1))%MOD;
    for(int i=1;i<=k;i++)
        dp[n][m]=(dp[n][m]+f(n-1-i,m-1,cnt+1,lv+1))%MOD;
    dp[n][m]=(dp[n][m]+f(n-1,m,cnt,lv+1))%MOD;
    dp[n][m]=(dp[n][m]+f(n,m-1,cnt,lv+1))%MOD;
    return dp[n][m];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&k);
    printf("%d\n",f(n,n,0,0));
    return 0;
}
