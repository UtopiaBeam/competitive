#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,dp[1005][1005][2],a[1005],b[1005];
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
    dp[0][0][1]=1;
    for(int i=1;i<=n;i++){
        dp[0][i][0]=dp[0][i-1][0]+a[i],dp[0][i][1]=dp[0][i-1][1];
        dp[i][0][0]=dp[i-1][0][0]+b[i],dp[i][0][1]=dp[i-1][0][1];
        if(dp[0][i][0]>m)   dp[0][i][1]++,dp[0][i][0]=a[i];
        if(dp[i][0][0]>m)   dp[i][0][1]++,dp[i][0][0]=b[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int m1=dp[i-1][j][0]+b[i],m2=dp[i][j-1][0]+a[j],d1=dp[i-1][j][1],d2=dp[i][j-1][1];
            if(m1>m)    d1++,m1=b[i];
            if(m2>m)    d2++,m2=a[j];
            if(d1<d2)   dp[i][j][0]=m1,dp[i][j][1]=d1;
            else if(d1>d2)  dp[i][j][0]=m2,dp[i][j][1]=d2;
            else dp[i][j][0]=min(m1,m2),dp[i][j][1]=d1;
        }
    printf("%d\n%d\n",dp[n][n][1],dp[n][n][0]);
    return 0;
}
