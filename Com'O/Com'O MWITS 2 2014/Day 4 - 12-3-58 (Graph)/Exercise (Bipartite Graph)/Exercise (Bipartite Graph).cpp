#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector <int> adj[50010];
int mark[50010];
bool dfs(int now,int color){    //1=blue,-1=red
    mark[now]=color;
    for(int i=0;i<(int)adj[now].size();i++){
        if(mark[adj[now][i]]==color)   return false;
        if(!mark[adj[now][i]]){
            if(!dfs(adj[now][i],(-1)*color))    return false;
        }
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=50000;i++)
            adj[i].clear();
        int n,m;
        scanf("%d %d",&n,&m);
        while(m--){
            int str,end;
            scanf("%d %d",&str,&end);
            adj[str].push_back(end),adj[end].push_back(str);
        }
        for(int i=1;i<=n;i++){
            if(!mark[i])
                if(!dfs(i,1)){
                    printf("G is not bipartite\n");    break;
                }
            if(i==n)    printf("G is bipartite\n");
        }
    }
    return 0;
}
