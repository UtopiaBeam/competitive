#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> g[100002];
int q, n, m;
int s, e;
int cl[100002];
bool chk;
void dfs(int u, int col) {
    if(!chk || cl[u] == col)
        return;
    cl[u] = col;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(cl[v] == 0 || cl[v] == -col)
            dfs(v, -col);
        else {
            chk = false;
            return;
        }
    }
}
int main() {
    scanf("%d", &q);
    while(q--) {
        chk = true;
        memset(cl, 0, sizeof(cl));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            g[i].clear();
        while(m--) {
            scanf("%d %d", &s, &e);
            g[s].push_back(e);
            g[e].push_back(s);
        }
        for(int i = 1; i <= n && chk; i++)
            if(cl[i] == 0)      dfs(i, 1);
        if(chk)     printf("yes\n");
        else        printf("no\n");
    }
    return 0;
}
