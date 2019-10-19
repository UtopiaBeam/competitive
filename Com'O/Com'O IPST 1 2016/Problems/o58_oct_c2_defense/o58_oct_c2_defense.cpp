#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[3002],dp[3002][2];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=1<<30;
        for(int j=max(1,i-k);j<i;j++){
            dp[i][1]=min(dp[i][1],dp[j][1]+a[i]);
        }
    }
    return 0;
}
