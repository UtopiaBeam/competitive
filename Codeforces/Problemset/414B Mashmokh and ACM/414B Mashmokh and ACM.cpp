#include<cstdio>
int n,m,dp[2002][2002],sum;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        dp[1][i]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k+=j){
                dp[i][k]+=dp[i-1][j];
                dp[i][k]%=(int)(1e9+7);
            }
    for(int i=1;i<=n;i++){
        sum+=dp[m][i];  sum%=(int)(1e9+7);
    }
    printf("%d\n",sum);
    return 0;
}
