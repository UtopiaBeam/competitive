#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
vector <PII> adj[105];
int n,m,q,cnt,str,end,c;
void dfs(int from,int now,int col,int co){
    if(col && col!=co)   return ;
    if(now==end){
        cnt++;  return ;
    }
    for(int i=0;i<adj[now].size();i++){
        if(adj[now][i].first==from)     continue;
        if(co==0)   dfs(now,adj[now][i].first,adj[now][i].second,adj[now][i].second);
        else    dfs(now,adj[now][i].first,adj[now][i].second,co);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&str,&end,&c);
        adj[str].push_back(PII(end,c)),adj[end].push_back(PII(str,c));
    }
    scanf("%d",&q);
    while(q--){
        cnt=0;
        scanf("%d %d",&str,&end);
        for(int i=0;i<adj[str].size();i++)
            dfs(str,adj[str][i].first,adj[str][i].second,adj[str][i].second);
        printf("%d\n",cnt);
    }
    return 0;
}
