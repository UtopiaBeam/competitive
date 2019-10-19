#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
vector<int> g[5002],gt[5002];
int n,m,s,e,scc[5002],b[5002],rnk[5002],cnt[5002],lim=0;
void dfs(int u){
    b[u]=1;
    for(int i=0;i<g[u].size();i++)
        if(!b[g[u][i]])     dfs(g[u][i]);
    st.push(u);
}
void dfst(int u){
    scc[u]=s;       b[u]=0;
    for(int i=0;i<gt[u].size();i++)
        if(b[gt[u][i]])     dfst(gt[u][i]);
        else if(scc[gt[u][i]]<s){
            if(rnk[s]<rnk[scc[gt[u][i]]]+1)
                rnk[s]=rnk[scc[gt[u][i]]]+1;
        }
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        gt[e].push_back(s);
    }
    for(int i=0;i<n;i++)
        if(!b[i])   dfs(i);
    s=0;
    while(!st.empty()){
        if(b[st.top()]){
            dfst(st.top());
            lim=max(lim,rnk[s++]);
        }
        st.pop();
    }
    for(int i=0;i<n;i++)
        cnt[rnk[scc[i]]]++;
    for(int i=0;i<=lim;i++)
        printf("%d ",cnt[i]);
    return 0;
}

