#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q,k,n,x,y,dp[2][302],mn,t;
int main(){
    scanf("%d",&q);
    while(q--){
        mn=1<<30;
        scanf("%d %d",&n,&k);
        for(int i=0;i<=k<<1;i++)
            dp[0][i]=1<<30;
        dp[0][k]=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            for(int j=0;j<=k<<1;j++){
                if(j==0)            dp[i&1][j]=dp[!(i&1)][j+1]+y;
                else if(j==k<<1)    dp[i&1][j]=dp[!(i&1)][j-1]+x;
                else    dp[i&1][j]=min(dp[!(i&1)][j-1]+x,dp[!(i&1)][j+1]+y);
            }
        }
        for(int i=0;i<=2*k;i++)
            mn=min(mn,dp[n&1][i]);
        printf("%d\n",mn);
    }
    return 0;
}
