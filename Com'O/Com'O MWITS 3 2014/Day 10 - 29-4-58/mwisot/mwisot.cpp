#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> adj[200005];
int w[200005],dp[200005],n,mark[200005];
int dfs(int i){
    if(dp[i])   return dp[i];
    mark[i]=1;
    vector <int> next;
    int tmp1=0,tmp2=w[i];
    for(int j=0;j<adj[i].size();j++)
        if(!mark[adj[i][j]])    next.push_back(adj[i][j]);
    for(int j=0;j<next.size();j++)
        tmp1+=dfs(next[j]);
    for(int j=0;j<next.size();j++)
        for(int k=0;k<adj[next[j]].size();k++)
            if(adj[next[j]][k]!=i)  tmp2+=dfs(adj[next[j]][k]);
    return dp[i]=max(tmp1,tmp2);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        adj[s].push_back(e),adj[e].push_back(s);
    }
    printf("%d\n",dfs(0));
    return 0;
}
