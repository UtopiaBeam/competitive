#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> adj[2005];
int n,mark[2005],h;
void dfs(int now,int d){
    if(adj[now].size()==0){
        h=max(h,d);     return ;
    }
    mark[now]=1;
    for(int i=0;i<adj[now].size();i++)
        dfs(adj[now][i],d+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h);
        if(h>0)     adj[h].push_back(i);
    }
    h=0;
    for(int i=1;i<=n;i++)
        if(!mark[i])    dfs(i,1);
    printf("%d\n",h);
    return 0;
}
