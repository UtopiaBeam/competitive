#include<cstdio>
char a[1005];
int n,dp[1005][1005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&a[i]);
    for(int i=n;i>0;i--)
        for(int j=i+1;j<=n;j++)
            if(a[i]==a[j])      dp[i][j]=1+dp[i+1][j-1];
            else{
                int max=-10;
                for(int k=i;k<j;k++)
                    if(max<dp[i][k]+dp[k+1][j])
                        max=dp[i][k]+dp[k+1][j];
                dp[i][j]=max;
            }
    printf("%d\n",dp[1][n]);
    return 0;
}
