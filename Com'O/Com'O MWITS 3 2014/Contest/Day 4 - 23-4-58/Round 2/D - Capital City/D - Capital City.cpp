#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector <int> adj[100005],re[100005],g[100005],topo,ans;
stack <int> s;
int n,m,mark[100005],scc[100005],in[100005],com=1;
void dfs(int now){
    if(mark[now])   return ;
    mark[now]=1;
    for(int i=0;i<adj[now].size();i++)
        dfs(adj[now][i]);
    s.push(now);
}
void re_dfs(int now){
    if(!mark[now])      return ;
    mark[now]=0,scc[now]=com;
    for(int i=0;i<re[now].size();i++)
        re_dfs(re[now][i]);
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v),re[v].push_back(u);
    }
    //SCC to get DAG
    for(int i=1;i<=n;i++)
        if(!mark[i])    dfs(i);
    while(!s.empty()){
        if(mark[s.top()])   re_dfs(s.top()),com++;
        s.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++)
            if(scc[i]!=scc[adj[i][j]])  g[scc[i]].push_back(scc[adj[i][j]]),in[scc[adj[i][j]]]++;
    }
    //Topo
    for(int i=1;i<com;i++)
        if(!in[i])  s.push(i);
    while(!s.empty()){
        int now=s.top();    s.pop();
        topo.push_back(now);
        for(int i=0;i<g[now].size();i++){
            in[g[now][i]]--;
            if(!in[g[now][i]])  s.push(g[now][i]);
        }
    }
    for(int i=1;i<=n;i++)
        if(scc[i]==topo[topo.size()-1]) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
