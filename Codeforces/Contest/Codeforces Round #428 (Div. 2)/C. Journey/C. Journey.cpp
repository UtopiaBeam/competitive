#include <cstdio>
#include <vector>
#define D double
#define N 100000
using namespace std;
vector <int> g[N+2];
int n, s, e;
bool chk[N+2];
D ans = 0;
void dfs(int u, int d, D p) {
    chk[u] = true;
    bool isFin = true;
    int cnt = 0;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!chk[v]) {
            cnt++;
            isFin = false;
        }
    }
    if(isFin) {
        ans += p * d;
        return;
    }
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!chk[v])     dfs(v, d+1, p/cnt);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    dfs(1, 0, 1);
    printf("%lf\n", ans);
    return 0;
}
