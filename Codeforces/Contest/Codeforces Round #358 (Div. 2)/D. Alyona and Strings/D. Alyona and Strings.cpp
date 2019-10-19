#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p,dp[1002][1002][12],mx=0;
char a[1002],b[1002];
int main(){
    scanf("%d %d %d %s %s",&n,&m,&p,a+1,b+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                for(int k=1;k<=p;k++)
                    dp[i][j][k]=dp[i-1][j-1][k]+1;
            else
                for(int k=1;k<=p;k++)
                    dp[i][j][k]=max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
    printf("%d\n",dp[n][m][p]);
//    for(int i=1;i<=p;i++)
//        mx=max(mx,dp[n][m][i]);
//    printf("%d\n",mx);
    return 0;
}
