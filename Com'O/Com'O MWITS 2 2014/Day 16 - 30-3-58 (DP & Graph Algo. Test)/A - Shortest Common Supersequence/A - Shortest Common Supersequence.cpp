#include<cstdio>
#include<algorithm>
using namespace std;
char a[5005],b[5005];
int m,n,dp[5005][5005];
int main(){
    scanf("%d %d %s %s",&m,&n,a,b);
    for(int i=1;i<=m;i++)
        dp[i][0]=i;
    for(int i=1;i<=n;i++)
        dp[0][i]=i;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i]==b[j])      dp[i+1][j+1]=dp[i][j]+1;
            else    dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][j])+1;
    printf("%d\n",dp[m][n]);
    return 0;
}
