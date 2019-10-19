#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define P pair<int, L>
#define F first
#define S second
using namespace std;
vector<P> g[100002];
int q, n;
int s, e;
L m, w, mx = 0;
void dfs(int u, L d) {
    mx = max(mx, d);
    for(int i = 0; i < g[u].size(); i++)
        dfs(g[u][i].F, d+g[u][i].S);
}
int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d %lld", &n, &m);
        for(int i = 1; i <= n; i++)
            g[i].clear();
        mx = 0;
        for(int i = 1; i < n; i++) {
            scanf("%d %d %lld", &s, &e, &w);
            g[s].push_back( P(e, w) );
        }
        dfs(1, 0);
        if(mx < m)      printf("-1\n");
        else            printf("%lld\n", mx);
    }
    return 0;
}
