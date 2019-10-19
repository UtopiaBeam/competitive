#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[102],dp[102][3];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if(a[i]&1)      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
        if(a[i]&2)      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
    }
    printf("%d\n",n-max(dp[n][0],max(dp[n][1],dp[n][2])));
    return 0;
}
