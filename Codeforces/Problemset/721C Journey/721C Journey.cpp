#include<cstdio>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,s,e,p[5002][5002],dp[5002][5002],w,t;
vector<P> g[5002];
void dfs(int u,int w,int cnt){
    if(dp[u][cnt]<=w || w>t)   return ;
    dp[u][cnt]=w;
    for(int i=0;i<g[u].size();i++)
        if(w+g[u][i].S<dp[g[u][i].F][cnt+1]){
            p[g[u][i].F][cnt+1]=u;
            dfs(g[u][i].F,w+g[u][i].S,cnt+1);
        }
}
void prn(int u,int cnt){
    if(cnt==0)      return ;
    prn(p[u][cnt],cnt-1);
    printf("%d ",u);
}
int main(){
    scanf("%d %d %d",&n,&m,&t);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        g[s].push_back(P(e,w));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=1<<30;
    dfs(1,0,1);
    for(int i=n;i>0;i--){
        if(dp[n][i]<=t){
            printf("%d\n",i);
            prn(n,i);
            return 0;
        }
    }
}
