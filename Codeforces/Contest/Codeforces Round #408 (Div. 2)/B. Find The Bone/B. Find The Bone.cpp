#include <cstdio>
int n, m, k;
int x, y, nw = 1;
bool h[1000002];
int main() {
    scanf("%d %d %d", &n, &m, &k);
    while(m--) {
        scanf("%d", &x);
        h[x] = true;
    }
    while(k--) {
        scanf("%d %d", &x, &y);
        if(h[nw]) {
            printf("%d\n", nw);
            return 0;
        }
        if(nw == x)     nw = y;
        else if(nw == y)    nw = x;
        if(h[nw]) {
            printf("%d\n", nw);
            return 0;
        }
    }
    printf("%d\n", nw);
    return 0;
}
