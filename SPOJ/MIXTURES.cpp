#include<cstdio>
#include<algorithm>
int n,dp[102][102][2];    //0 = color, 1 = smoke
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d",&dp[i][i][0]);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                dp[i][j][1]=dp[j][i][1]=(int)1e9;
        for(int i=1;i<n;i++)
            for(int j=0;j<n-i;j++)
                for(int k=0;k<i;k++)
                    if(dp[j][i+j][1]>dp[j][j+k][0]*dp[j+k+1][i+j][0]+dp[j][j+k][1]+dp[j+k+1][j+i][1]){
                        dp[j][i+j][1]=dp[j][j+k][0]*dp[j+k+1][i+j][0]+dp[j][j+k][1]+dp[j+k+1][j+i][1];
                        dp[j][i+j][0]=(dp[j][j+k][0]+dp[j+k+1][i+j][0])%100;
                    }
        printf("%d\n",dp[0][n-1][1]);
    }
    return 0;
}
