#include<cstdio>
#include<vector>
#define L long long
#define P pair<int,L>
#define F first
#define S second
using namespace std;
int n,p,d[100002],b[100002],cnt=0;
L w,a[100002],s[100002];
vector<P> g[100002];
int dfs(int u,L sum){
    int t=0;
    if(b[u])    return 0;
    b[u]=1;     s[u]=sum;
    for(int i=0;i<g[u].size();i++)
        t+=dfs(g[u][i].F,sum+g[u][i].S);
    return d[u]=t+1;
}
void ans(int u){
    if(!b[u])   return ;
    b[u]=0;
    if(s[u]>a[u]){
        cnt+=d[u];
        return ;
    }
    for(int i=0;i<g[u].size();i++)
        ans(g[u][i].F);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=2;i<=n;i++){
        scanf("%d %I64d",&p,&w);
        g[i].push_back(P(p,w));
        g[p].push_back(P(i,w));
    }
    dfs(1,0);
    ans(1);
    printf("%d\n",cnt);
    return 0;
}
