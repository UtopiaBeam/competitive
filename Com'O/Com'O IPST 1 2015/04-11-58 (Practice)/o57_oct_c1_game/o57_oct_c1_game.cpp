#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
stack<int> S;
vector<int> G[5002],Gt[5002];
int n,m,s,e,scc[5002],b[5002],rnk[5002],cnt[5002],lim=0;
void dfs(int u){
    b[u]=1;
    for(int i=0;i<G[u].size();i++)
        if(!b[G[u][i]])     dfs(G[u][i]);
    S.push(u);
}
void dfst(int u){
    scc[u]=s;       b[u]=0;
    for(int i=0;i<Gt[u].size();i++)
        if(b[Gt[u][i]])     dfst(Gt[u][i]);
        else if(scc[Gt[u][i]]<s){
            if(rnk[s]<rnk[scc[Gt[u][i]]]+1)
                rnk[s]=rnk[scc[Gt[u][i]]]+1;
        }
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        G[s].push_back(e);
        Gt[e].push_back(s);
    }
    for(int i=0;i<n;i++)
        if(!b[i])   dfs(i);
    s=0;
    while(!S.empty()){
        if(b[S.top()]){
            dfst(S.top());
            lim=max(lim,rnk[s++]);
        }
        S.pop();
    }
    for(int i=0;i<n;i++)
        cnt[rnk[scc[i]]]++;
    for(int i=0;i<=lim;i++)
        printf("%d ",cnt[i]);
    return 0;
}
