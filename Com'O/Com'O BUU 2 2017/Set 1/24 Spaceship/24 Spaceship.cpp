#include <cstdio>
#include <algorithm>
struct S {
    int x, y, z;
    int m, k, c;
    int dist (int x, int y, int z) {
        return (this->x - x) * (this->x - x)
            + (this->y - y) * (this->y - y)
            + (this->z- z) * (this->z - z);
    }
}a[22];
int n, q, x, y, z;
int mn = 1<<30;
int chk[22];
void dfs(int x, int y, int z, int m, int k, int c, int cost) {
    if(m >= n && k >= n && c >= n) {
        mn = std::min(mn, cost);
        return;
    }
    for(int i = 0; i < q; i++) {
        if(chk[i])      continue;
        chk[i] = 1;
        dfs(a[i].x, a[i].y, a[i].z, m+a[i].m, k+a[i].k, c+a[i].c, cost+a[i].dist(x, y, z));
        chk[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
        scanf("%d %d %d", &a[i].m, &a[i].k, &a[i].c);
    }
    dfs(x, y, z, 0, 0, 0, 0);
    printf("%d\n", mn);
    return 0;
}
