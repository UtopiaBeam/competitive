#include<cstdio>
#include<vector>
using namespace std;
vector <int> adj[105];
int chk=1,n,a[105],d[105],root[105],m[105];
void dfs(int now,int r){
    if(m[now])      return ;
    m[now]=1,root[now]=r;
    for(int i=0;i<adj[now].size();i++)
        dfs(adj[now][i],r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        root[i]=i;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for(int i=1;i<=n;i++){
        if(i-d[i]>0)    adj[i].push_back(i-d[i]),adj[i-d[i]].push_back(i);
        if(i+d[i]<=n)   adj[i].push_back(i+d[i]),adj[i+d[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!m[i])   dfs(i,i);
    for(int i=1;i<=n && chk;i++)
        if(root[i]!=root[a[i]])     printf("NO\n"),chk=0;
    if(chk)     printf("YES\n");
    return 0;
}
