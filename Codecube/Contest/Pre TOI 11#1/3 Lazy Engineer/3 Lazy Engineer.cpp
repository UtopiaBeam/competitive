#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1<<30
using namespace std;
typedef pair<int,int> PII;
vector<PII> adj[1005];
int dp[1005],mark[1005],ans,Min=INF,n,m;
void dfs(int now,int cnt,int d){
    if(now==n){
        if(!(cnt%2))   dp[now]=min(dp[now],d);
        return ;
    }
    if(mark[now])   return ;
    mark[now]=1;
    dp[now]=min(dp[now],d);
    for(int i=0;i<adj[now].size();i++)
        dfs(adj[now][i].first,cnt+1,d+adj[now][i].second);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int s,e,w;
        for(int j=2;j<=n;j++)   dp[j]=INF,mark[i]=0;
        scanf("%d %d %d",&s,&e,&w);
        adj[s].push_back(PII(e,w)),adj[e].push_back(PII(s,w));
        dfs(1,1,0);
        if(Min>dp[n])   Min=dp[n],ans=i;
    }
    printf("%d %d\n",ans,Min);
    return 0;
}
