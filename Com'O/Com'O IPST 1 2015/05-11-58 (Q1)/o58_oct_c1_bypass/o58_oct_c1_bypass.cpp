#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> g[1002];
int n,s,e,c[1002][1002],b[1002],x,y,u,v,mx=0;
int dfs(int u,int v){
    int cnt=1;
    b[u]=1;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!=v && !b[g[u][i]])
            cnt+=dfs(g[u][i],v);
    b[u]=0;
    return cnt;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);      g[e].push_back(s);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            if(!c[i][g[i][j]])
                c[i][g[i][j]]=c[g[i][j]][i]=dfs(i,g[i][j])*dfs(g[i][j],i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(mx<c[i][j])
                mx=c[i][j],x=i,y=j;
    mx=0;
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=y && c[x][g[x][i]]>mx)    mx=c[x][g[x][i]],u=g[x][i];
    mx=0;
    for(int i=0;i<g[y].size();i++)
        if(g[y][i]!=x && c[y][g[y][i]]>mx)    mx=c[y][g[y][i]],v=g[y][i];
    printf("%d\n",dfs(u,x)*dfs(v,y));
    return 0;
}
