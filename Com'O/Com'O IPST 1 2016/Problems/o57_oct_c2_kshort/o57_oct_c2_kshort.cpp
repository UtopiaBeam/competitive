#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
#define INF 1<<30
using namespace std;
priority_queue<PP> q;
vector<PP> g[10002];
int d[10002][52],n,m,s,k,u,v,w,cnt;
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&k);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(PP(0,P(v,w)));
    }
    while(s--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(PP(1,P(v,w)));
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            d[i][j]=INF;
    q.push(PP(0,P(1,0)));
    while(!q.empty()){
        w=-q.top().F,u=q.top().S.F,cnt=q.top().S.S;
        q.pop();
        if(d[u][cnt]<=w)    continue;
        d[u][cnt]=w;
        for(int i=0;i<g[u].size();i++)
            if(cnt+g[u][i].F<=k && d[g[u][i].S.F][cnt+g[u][i].F]>w+g[u][i].S.S)
                q.push(PP(-w-g[u][i].S.S,P(g[u][i].S.F,cnt+g[u][i].F)));
    }
    int mn=INF;
    for(int i=0;i<=k;i++)
        mn=min(mn,d[n][i]);
    printf("%d\n",mn);
    return 0;
}
