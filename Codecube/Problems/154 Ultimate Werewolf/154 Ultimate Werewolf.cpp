#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define N 100000
using namespace std;
vector<int> g[N+2];
queue<P> q;
bool chk[N+2], done[N+2];
int n, x;
int bfs(int u, int d) {
    q.push( P(u, d) );
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        chk[i] = false;
    while( !q.empty() ) {
        u = q.front().F;
        x = q.front().S;
        q.pop();
        if(chk[u])      continue;
        chk[u] = true;
        done[u] = true;
        if(x % 2 == 0)      cnt++;
        for(int i = 0; i < g[u].size(); i++)
            q.push( P(g[u][i], x+1) );
    }
    return cnt;
}
void solve() {
    int ans = n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        done[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(done[i])        continue;
        int mx = max(bfs(i, 0), bfs(i, 1));
        ans -= mx;
        printf("node %d, mx = %d\n", i, mx);
    }
    printf("%d\n", ans);
}
int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        solve();
    }
    return 0;
}
