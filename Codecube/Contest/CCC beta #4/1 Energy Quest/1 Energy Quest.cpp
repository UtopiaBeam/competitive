#include<cstdio>
#include<vector>
#define P pair<int,long long>
#define F first
#define S second
using namespace std;
vector<P> adj[100002];
vector<int> path;
int b[100002],n,s,e,t;
long long p[100002],sum=0,w;
void dfs(int u,int v,long long d){
    b[u]=1,d+=p[u],path.push_back(u);
    if(u==v){
        for(int i=0;i<path.size();i++)  p[path[i]]=0;
        sum+=d;
    }
    else for(int i=0;i<adj[u].size();i++){
        int nx=adj[u][i].F;
        long long w=adj[u][i].S;
        if(!b[nx])  dfs(nx,v,d-w);
    }
    b[u]=0,path.pop_back();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %lld",&s,&e,&w);
        adj[s].push_back(P(e,w)),adj[e].push_back(P(s,w));
    }
    for(int i=1;i<=n;i++)   scanf("%lld",&p[i]);
    scanf("%d %d %d",&s,&e,&t);
    dfs(s,t,0);    dfs(t,e,0);
    printf("%lld\n",sum);
    return 0;
}
