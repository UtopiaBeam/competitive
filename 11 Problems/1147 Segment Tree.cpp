#include <cstdio>
#include <algorithm>
#define N (int)(3e5)
#define INF_MIN -1<<30
using namespace std;

int st[3*N+2];
int n, m;
int x, v, l, r;

void bd(int s, int e, int idx) {
    if (s == e) {
        st[idx] = INF_MIN;      return;
    }
    int m = (s+e)>>1;
    bd(s, m, idx<<1);   bd(m+1, e, idx<<1|1);
    st[idx] = max(st[idx<<1], st[idx<<1|1]);
}

void ud(int s, int e, int idx) {
    if (s == e) {
        st[idx] = v;    return;
    }
    int m = (s+e)>>1;
    if (x <= idx)       ud(s, m, idx<<1);
    else        ud(m+1, e, idx<<1|1);
    st[idx] = max(st[idx<<1], st[idx<<1|1]);
}

int qr(int s, int e, int idx) {
    if (e < l || r < s)     return INF_MIN;
    if (l <= s && e <= r)   return st[idx];
    int m = (s+e)>>1;
    return max(qr(s, m, idx<<1), qr(m+1, e, idx<<1|1));
}

int main() {
    scanf("%d %d", &n, &m);
    bd(1, n, 1);
    while (m--) {
        char op;
        scanf(" %c", &op);
        if (op == 'U') {
            scanf("%d %d", &x, &v);
            ud(1, n, 1);
        } else if (op == 'P') {
            scanf("%d %d", &l, &r);
            printf("%d\n", qr(1, n, 1));
        }
    }
    return 0;
}