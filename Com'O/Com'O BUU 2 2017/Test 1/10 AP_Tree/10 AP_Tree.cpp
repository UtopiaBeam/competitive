#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define INF (L)1e18
using namespace std;
vector<int> g[100002];
int q, n;
int s, e;
L a[100002], dp[100002], sum = 0, mn = INF;
bool chk[100002];
void dfs(int u) {
    if(chk[u])      return;
    chk[u] = true;
    dp[u] += a[u];
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!chk[v]) {
            dfs(v);
            dp[u] += dp[v];
            mn = min(mn, abs(sum - 2*dp[v]) );
        }
    }
}
int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        mn = INF;   sum = 0;
        for(int i = 1; i <= n; i++) {
            g[i].clear();
            dp[i] = 0;
            chk[i] = false;
        }
        for(int i = 1; i < n; i++) {
            scanf("%d %d", &s, &e);
            g[s].push_back(e);
            g[e].push_back(s);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%lld", a+i);
            sum += a[i];
        }
        dfs(1);
//        for(int i = 1; i <= n; i++)
//            printf("%lld ", dp[i]);
//        printf("\n");
        printf("%lld\n", mn);
    }
    return 0;
}
