#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,A,B,k,dp[35][105][105][25],x[35],y[35],v[35];
int main(){
    scanf("%d",&q);
    while(q--){
        int ans=0;
        scanf("%d %d %d %d",&n,&A,&B,&k);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d %d %d",&x[i],&y[i],&v[i]);
        for(int i=1;i<=n;i++)
            for(int a=0;a<=A;a++)
                for(int b=0;b<=B;b++)
                    for(int j=0;j<=2*k;j++)
                        if(x[i]>=a && y[i]>=b)  dp[i][a][b][j]=dp[i-1][a][b][j];
                        else{
                            if(x[i]<a && j>0)   dp[i][a][b][j]=max(dp[i-1][a][b][j],dp[i-1][a-x[i]][b][j-1]+v[i]);
                            if(y[i]<b && j<2*k) dp[i][a][b][j]=max(dp[i][a][b][j],dp[i-1][a][b-y[i]][j+1]+v[i]);
                        }
        for(int a=0;a<=A;a++)
            for(int b=0;b<=B;b++)
                for(int j=0;j<=2*k;j++)
                    ans=max(ans,dp[n][a][b][j]);
        printf("%d\n",ans);
    }
    return 0;
}
