#include<cstdio>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
vector<int> adj[100005],re[100005];
stack<int> st;
int n,m,s,e;
long long c[100005],mark[100005],scc[100005],c_scc[100005],sum=0,ans=1,cnt[100005];
void dfs(int now){
    mark[now]=1;
    for(int i=0;i<adj[now].size();i++)
        if(!mark[adj[now][i]])  dfs(adj[now][i]);
    st.push(now);
}
void dfst(int now){
    scc[now]=e,mark[now]=0;
    int t=c[now];
    for(int i=0;i<re[now].size();i++)
        if(mark[re[now][i]])    dfst(re[now][i]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&c[i]);
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&s,&e);
        adj[s].push_back(e);
        re[e].push_back(s);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])    dfs(i);
    e=1;
    while(!st.empty()){
        s=st.top();
        st.pop();
        if(mark[s])     dfst(s),e++;
    }
    for(int i=1;i<e;i++)
        c_scc[i]=LLONG_MAX;
    for(int i=1;i<=n;i++){
        int com=scc[i];
        if(c_scc[com]>c[i])     c_scc[com]=c[i],cnt[com]=1;
        else if(c[i]==c_scc[com])   cnt[com]++;
    }
    for(int i=1;i<e;i++)
        sum+=c_scc[i],ans*=cnt[i],ans%=1000000007;
    printf("%I64d %I64d\n",sum,ans);
    return 0;
}
