#include <cstdio>
int n, m, p, t, ans, rx, ry;
int r[100002], ls[100002], chk[100002];
int fr(int x) {
    if(x == r[x])   return x;
    return r[x] = fr(r[x]);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        r[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p);
        rx = fr(i);
        while(p--) {
            scanf("%d", &t);
            ry = fr(ls[t]);
            if(ry != 0)     r[ry] = rx;
            ls[t] = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        rx = fr(i);
        ans += 1 - chk[rx];
        chk[rx] = 1;
    }
    printf("%d\n", ans-1);
    return 0;
}
