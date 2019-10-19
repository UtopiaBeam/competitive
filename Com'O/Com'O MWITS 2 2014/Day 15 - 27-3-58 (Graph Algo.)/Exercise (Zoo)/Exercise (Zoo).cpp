#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int v[20005],deg[20005],dp[20005];
vector <int> adj[20005],topo;
stack <int> zero;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    while(k--){
        int str,end;
        scanf("%d %d",&str,&end);
        adj[end].push_back(str);
        deg[str]++;
    }
    //Toposort
    for(int i=1;i<=n;i++)
        if(!deg[i])     zero.push(i);
    while(!zero.empty()){
        int now=zero.top();
        zero.pop();
        topo.push_back(now);
        for(int i=0;i<(int)adj[now].size();i++){
            deg[adj[now][i]]--;
            if(!deg[adj[now][i]])   zero.push(adj[now][i]);
        }
    }
    for(int i=1;i<=n;i++)
        dp[i]=v[i];
    for(int i=0;i<(int)topo.size();i++){
        int now=topo[i];
        for(int j=0;j<(int)adj[now].size();j++)
            if(dp[adj[now][j]]<dp[now]+v[adj[now][j]])    dp[adj[now][j]]=dp[now]+v[adj[now][j]];
    }
    int max=1;
    for(int i=2;i<=n;i++)
        if(dp[max]<dp[i])   max=i;
    printf("%d %d\n",max,dp[max]);
    return 0;
}
