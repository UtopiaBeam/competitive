#include<cstdio>
int dp[102][102],n,m,t;
int main(){
    dp[0][0]=1,dp[1][0]=1;
    for(int i=2;i<=100;i++){
        for(int j=0;j<=100;j++){
            dp[i][j]=dp[i-1][j]+dp[i-2][j]+(j>0)*dp[i-2][j-1];
            dp[i][j]%=9241;
            if(i>2){
                for(int k=0;k<=i-3;k++){
                    dp[i][j]+=2*dp[k][j-2];
                    dp[i][j]%=9241;
                }
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int sum=0;
        for(int i=0;i<=m;i++)   sum+=dp[n][i],sum%=9241;
        printf("%d\n",sum);
    }
    return 0;
}
