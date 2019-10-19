#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,s,e,w,dp[502][502],g[502][502],cnt[502][502],ans[502][502];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        dp[s][e]=dp[e][s]=g[s][e]=g[e][s]=w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(!dp[i][j])   dp[i][j]=1e9;
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j && dp[i][j]!=1e9)
                for(int k=1;k<=n;k++)
                    if(g[k][j] && dp[i][j]==dp[i][k]+g[k][j])
                        cnt[i][j]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j && dp[i][j]!=1e9)
                for(int k=1;k<=n;k++)
                    if(dp[i][k]+dp[k][j]==dp[i][j])
                        ans[i][j]+=cnt[i][k];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            printf("%d ",ans[i][j]);
    return 0;
}
