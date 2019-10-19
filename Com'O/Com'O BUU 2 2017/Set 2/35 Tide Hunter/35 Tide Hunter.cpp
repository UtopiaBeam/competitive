#include <cstdio>
int q;
int n, m, t, d;
int l[1002], b[1002];
void dfs(int u, int d) {
    if(l[u] == 0)       return;
    l[u] -= d;
    if(l[u] < 0)    l[u] = 0;
    dfs(b[u], d);
}
int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d %d", l+i, b+i);
        while(m--) {
            scanf("%d %d", &t, &d);
            if(d > 0)       dfs(t, d);
            for(int i = 0; i < n; i++)
                printf("%d ", l[i]);
            printf("\n");
        }
    }
    return 0;
}
