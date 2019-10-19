#include<cstdio>
#include<vector>
#include<queue>
#define L long long
using namespace std;
vector<int> g[1002];
priority_queue<L> q;
int n,m,k,s,e;
int sp[1002],b[1002];
L ans=0,sz[1002],cnt=0,mx;
void dfs(int u,int id){
    if(b[u])    return ;
    b[u]=1;     sz[id]++;
    for(int v:g[u]){
        cnt++;
        if(!b[v])       dfs(v,id);
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",sp+i);
    while(m--){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    for(int i=1;i<=k;i++){
        cnt=0;
        dfs(sp[i],i);
        ans+=(sz[i]*(sz[i]-1))/2-cnt/2;
        q.push(sz[i]);
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            cnt=0;  sz[0]=0;
            dfs(i,0);
            ans+=(sz[0]*(sz[0]-1))/2-cnt/2;
            if(!q.empty()){
                mx=q.top();
                q.pop();
                ans+=sz[0]*mx;
                mx+=sz[0];
                q.push(mx);
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
