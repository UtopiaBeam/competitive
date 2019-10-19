#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define P pair<int, L>
#define F first
#define S second
#define INF (L)1e18
using namespace std;
vector<P> g[100002];
int n, p, cnt[100002];
L w, a[100002], d[100002], mn[100002];
int dfs(int u, int cmd) {
    if(cmd == 0) {
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].F;
            w = g[u][i].S;
            d[v] = d[u] + w;
            mn[v] = min(mn[u], d[v]);
            cnt[u] += dfs(v, 0);
        }
        return ++cnt[u];
    } else {
        if(d[u] - mn[u] > a[u])     return cnt[u];
        if(g[u].empty())        return 0;
        int tmp = 0;
        for(int i = 0; i < g[u].size(); i++)
            tmp += dfs(g[u][i].F, 1);
        return tmp;
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", a+i);
    for(int i = 2; i <= n; i++) {
        scanf("%d %I64d", &p, &w);
        g[p].push_back( P(i, w) );
    }
    dfs(1, 0);
    printf("%d\n", dfs(1, 1) );
    return 0;
}
