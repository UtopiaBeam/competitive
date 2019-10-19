#include <cstdio>
int n, m, x, y, rx, ry;
int r[100002];
int fr(int x) {
    if(x == r[x])   return x;
    return r[x] = fr(r[x]);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        r[i] = i;
    while(m--) {
        scanf("%d %d", &x, &y);
        rx = fr(x), ry = fr(y);
        r[rx] = ry;
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &x, &y);
        rx = fr(x), ry = fr(y);
        if(rx == ry)    printf("YES\n");
        else            printf("NO\n");
    }
    return 0;
}
