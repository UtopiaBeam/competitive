#include<cstdio>
#include<algorithm>
#define f t*(1-2*(i%2))
using namespace std;
int dp[3],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        dp[2]=min(min(dp[0],dp[1]),dp[2])+f;
        dp[1]=min(dp[0],dp[1])-f;
        dp[0]+=f;
    }
    printf("%d\n",min(min(dp[0],dp[1]),dp[2]));
    return 0;
}
