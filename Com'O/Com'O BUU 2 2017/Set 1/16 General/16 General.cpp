#include <cstdio>
#include <algorithm>
int n, m;
int x, y, rx, ry;
int v[100002], r[100002];
int fd(int u) {
    if(u == r[u])   return u;
    return r[u] = fd(r[u]);
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", v+i);
        r[i] = i;
    }
    while(m--) {
        scanf("%d %d", &x, &y);
        rx = fd(x);     ry = fd(y);
        if(rx == ry)    printf("-1\n");
        else {
            if(rx > ry)     std::swap(rx, ry);
            if(v[rx] >= v[ry]) {
                v[rx] += v[ry]/2;
                r[ry] = rx;
                printf("%d\n", rx);
            } else {
                v[ry] += v[rx]/2;
                r[rx] = ry;
                printf("%d\n", ry);
            }
        }
    }
    return 0;
}
