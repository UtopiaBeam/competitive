#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
vector <PII> adj[100005];
int Max=0,mark[100005];
void dfs(int now,int dis){
    if(adj[now].size()==0)      return ;
    mark[now]=1;
    if(Max<dis)     Max=dis;
    for(int i=0;i<adj[now].size();i++)
        if(!mark[adj[now][i].first])
            dfs(adj[now][i].first,dis+adj[now][i].second);
}
int main(){
    int n;
    scanf("%d",&n);
    while(--n){
        int str,end,w;
        scanf("%d %d %d",&str,&end,&w);
        adj[str].push_back(PII(end,w)),adj[end].push_back(PII(str,w));
    }
    dfs(1,0);
    printf("%d\n",Max);
    return 0;
}
