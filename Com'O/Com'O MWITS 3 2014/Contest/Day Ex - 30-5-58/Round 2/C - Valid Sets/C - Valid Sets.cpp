#include<cstdio>
#include<vector>
using namespace std;
vector<int> adj[2005];
int c[2005],a[2005],f[2005],n,d,s,e,sum=0,mod=(int)1e9+7;
void dfs(int u,int rt){
    c[u]=0,f[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(c[v]){
            if(a[v]<a[rt] || a[v]>a[rt]+d)      continue;
            if(a[v]==a[rt] && v<rt)     continue;
            dfs(v,rt);
            f[u]=((long long)(f[u])*(f[v]+1))%mod;
        }
    }
}
int main(){
    scanf("%d %d",&d,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        adj[s].push_back(e),adj[e].push_back(s);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   f[j]=0,c[j]=1;
        dfs(i,i);
        sum=(sum+f[i])%mod;
    }
    printf("%d\n",sum);
    return 0;
}
