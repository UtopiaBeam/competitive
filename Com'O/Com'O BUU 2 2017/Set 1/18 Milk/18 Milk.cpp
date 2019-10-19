#include <cstdio>
int r[100002];
int n, q;
int x, y, rx, ry;
char ch;
int fr(int u) {
    if(u == r[u])       return u;
    return r[u] = fr(r[u]);
}
int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        r[i] = i;
    while(q--) {
        scanf(" %c %d %d", &ch, &x, &y);
        rx = fr(x);     ry = fr(y);
        if(ch == 'c')   r[rx] = ry;
        else {
            if(rx == ry)    printf("yes\n");
            else            printf("no\n");
        }
    }
    return 0;
}
