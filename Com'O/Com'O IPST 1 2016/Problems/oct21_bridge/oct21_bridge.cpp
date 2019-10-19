#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[3002],b[3002],dp[2][3002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i&1][j]=max(dp[!(i&1)][j-1]+(a[i]==b[j]),max(dp[!(i&1)][j],dp[i&1][j-1]));
    printf("%d\n",dp[n&1][n]);
    return 0;
}
