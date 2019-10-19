#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[1002];
int n, m, ans = 0;
int s, e;
int v[1002], dp[1002], chk[1002];
int dfs(int u) {
    if(chk[u])      return dp[u];
    chk[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
        dp[u] = max(dp[u], dfs(g[u][i]));
    return dp[u] += v[u];
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",v+i);
    while(m--) {
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
    }
    for(int i = 1; i <= n; i++)
        dfs(i);
    for(int i = 1; i <= n; i++)
        if(dp[ans] < dp[i])
            ans = i;
    printf("%d %d\n",ans,dp[ans]);
    return 0;
}
