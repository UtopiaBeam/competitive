#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector <int> adj[25];
int n,m,s,e,mark[25],cnt=0;
void dfs(int now,int from,int chk){
    if(chk && now==from){
        cnt++;      return ;
    }
    if(mark[now])   return ;
    mark[now]=1;
    for(int i=0;i<adj[now].size();i++)
        dfs(adj[now][i],from,1);
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        adj[s].push_back(e),adj[e].push_back(s);
    }
    for(int i=1;i<=n;i++){
        dfs(i,i,0);
    }
    printf("%d\n",cnt);
    return 0;
}
