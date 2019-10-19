#include <cstdio>
#include <vector>
#define N 100000
using namespace std;
vector <int> g[N+2], ans;
int n, s, e;
int a[N+2], b[N+2];
int lz[N+2];
bool chk[N+2];
void dfs(int u) {
    if(chk[u])      return;
    chk[u] = true;
    if(lz[u]) {
        a[u] ^= 1;
        for(int t : g[u]) {
            if(chk[t])      continue;
            for(int v : g[t])
                lz[v] ^= 1;
        }
    }
    if(a[u] != b[u]) {
        ans.push_back(u);
        for(int t : g[u]) {
            if(chk[t])      continue;
            for(int v : g[t])
                lz[v] ^= 1;
        }
    }
    for(int v : g[u])
        dfs(v);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b+i);
    dfs(1);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
    return 0;
}
