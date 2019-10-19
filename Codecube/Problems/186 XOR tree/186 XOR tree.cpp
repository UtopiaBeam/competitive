#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100000
#define P pair<int, int>
#define F first
#define S second
using namespace std;

vector<P> g[N+2];
int dp[N+2];
bool chk[N+2];
int n, m;

void dfs(int u) {
    if (chk[u])     return;
    chk[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].F, w = g[u][i].S;
        dp[v] = dp[u]^w;
        dfs(v);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int s, e, w;
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &s, &e, &w);
        g[s].push_back( P(e, w) );
        g[e].push_back( P(s, w) );
    }

    dfs(1);

    while (m--) {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s]^dp[e]);
    }
    return 0;
}