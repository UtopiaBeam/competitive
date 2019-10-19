#include<cstdio>
#include<vector>
using namespace std;
vector<int> g[100002];
int a[100002],s,e,n,m,ans=0,b[100002];
void dfs(int u,int cnt){
//    printf("dfs(%d, %d)\n",u,cnt);
    if(b[u])    return ;
    b[u]=1;
    if(a[u])    cnt++;
    else        cnt=0;
    if(cnt>m)      return ;
    bool chk=true;
    for(int i=0;i<g[u].size();i++)
        if(!b[g[u][i]])     dfs(g[u][i],cnt),chk=false;
    if(chk)     ans++;
    b[u]=0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
