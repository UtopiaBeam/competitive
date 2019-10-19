#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],mx=0;
int dp[100005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        dp[i+1]=max(dp[i+1],dp[i]);
        dp[i+3]=max(dp[i+3],dp[i]+a[i+2]);
    }
    for(int i=0;i<n+5;i++)
        mx=max(mx,dp[i]);
    printf("%d\n",mx);
    return 0;
}
