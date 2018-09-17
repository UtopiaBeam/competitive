#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int n,m,s,e,a[500002],b[500002],c[500002],d[500002],chk[500002],mx=-1e9;
stack<int> st,dfs;
vector<int> g[500002],gt[500002];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        g[s].push_back(e),gt[e].push_back(s);
    }
    for(int i=1;i<=n;i++)
        if(!b[i]){
            dfs.push(i);
            while(!dfs.empty()){
                int u=dfs.top();
                if(b[u]){
                    st.push(dfs.top());
                    dfs.pop();
                    continue;
                }
                b[u]=1;
                for(int j=0;j<g[u].size();j++)
                    if(!b[g[u][j]])    dfs.push(g[u][j]);
            }
        }
    e=1;
    while(!st.empty()){
        if(b[st.top()]){
            dfs.push(st.top());
            while(!dfs.empty()){
                int u=dfs.top();
                dfs.pop();
                b[u]=0;     c[u]=e;
                d[e]+=a[u];
                for(int j=0;j<gt[u].size();j++)
                    if(b[gt[u][j]])     dfs.push(gt[u][j]);
            }
            e++;
        }
        st.pop();
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[c[i]]+=a[i];
        a[i]=0;
    }
    scanf("%d %d",&s,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&e);
        chk[c[e]]=1;
    }
    for(int i=1;i<=n;i++)
        gt[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            if(c[i]!=c[g[i][j]])
                gt[c[i]].push_back(c[g[i][j]]);
    for(int i=c[s];i<e;i++)    a[i]=d[i];
    for(int i=c[s];i<e;i++)
        for(int j=0;j<gt[i].size();j++)
            if(a[gt[i][j]]<a[i]+d[gt[i][j]])
                a[gt[i][j]]=a[i]+d[gt[i][j]];
    for(int i=1;i<e;i++)
        if(chk[i] && mx<a[i])      mx=a[i];
    printf("%d\n",mx);
    return 0;
}
