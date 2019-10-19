#include <cstdio>
#include <algorithm>
#define L long long
#define N 200000
using namespace std;
int w, h, n;
char op[N+2];
int t[N+2];
L l[N+2], r[N+2], u[N+2], d[N+2], mxw, mxh;
L ans[N+2];
int main() {
    scanf("%d %d %d", &w, &h, &n);
    r[w] = 1;   u[h] = 1;
    for(int i = 1; i <= n; i++) {
        scanf(" %c %d", op+i, t+i);
        if(op[i] == 'H')    u[t[i]] = 1;
        else                r[t[i]] = 1;
    }
    int p = 0;
    for(int i = 1; i <= w; i++) {
        if(r[i] == 1) {
            l[i] = p;
            r[p] = i;
            mxw = max(mxw, (L)(i-p));
            p = i;
        }
    }
    p = 0;
    for(int i = 1; i <= h; i++) {
        if(u[i] == 1) {
            u[p] = i;
            d[i] = p;
            mxh = max(mxh, (L)(i-p));
            p = i;
        }
    }
    ans[n] = mxw * mxh;
    for(int i = n; i > 1; i--) {
        int x = t[i];
        if(op[i] == 'V') {
            r[l[x]] = r[x];
            l[r[x]] = l[x];
            mxw = max(mxw, r[x] - l[x]);
        }
        else {
            u[d[x]] = u[x];
            d[u[x]] = d[x];
            mxh = max(mxh, u[x] - d[x]);
        }
        ans[i-1] = mxw * mxh;
    }
    for(int i = 1; i <= n; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}
