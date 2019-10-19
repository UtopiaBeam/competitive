#include<cstdio>
#include<vector>
#include<queue>
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
#define INF 1<<30
using namespace std;
priority_queue<P> q;
vector<PP> g[50002];
int n,m,k,u,v,w;
int d[50002];
bool chk(int m){
    for(int i=1;i<=n;i++)
        d[i]=INF;
    q.push(P(0,1));
    while(!q.empty()){
        w=-q.top().F,u=q.top().S;
        q.pop();
        if(d[u]>w){
            d[u]=w;
            for(int i=0;i<g[u].size();i++){
                if(g[u][i].S.S>m)   continue;
                if(d[g[u][i].S.F]>w+g[u][i].F)
                    q.push(P(-w-g[u][i].F,g[u][i].S.F));
            }
        }
    }
    return d[n]<=k;
}
int bs(int s,int e){
    if(s==e){
        if(s>m)     return -1;
        return s;
    }
    int m=(s+e)/2;
    if(chk(m))      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(PP(w,P(v,i)));
        g[v].push_back(PP(w,P(u,i)));
    }
    printf("%d\n",bs(1,m+1));
    return 0;
}
