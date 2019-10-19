#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define L long long
#define P pair<L, int>
#define F first
#define S second
#define N 500000
using namespace std;
P x[N+2], y[N+2];
int n;
L w;
int ptt(P *a, int s, int m, int e) {
    swap(a[m], a[e]);
    int md = s;
    for(int i = s; i < e; i++) {
        if(a[i].F <= a[e].F)
            swap(a[md++], a[i]);
    }

    swap(a[md], a[e]);
    return md;
}
int med(P *a, int s, int e) {
    if(s == e)          return a[s].F;

    L ws = 0;
    for(int i = 1; i < s; i++)
        ws += a[i].S;

    if(e-s == 1) {
        if(2*(ws + a[s].S) >= w)    return a[s].F;
        return a[e].F;
    }

    int m = ptt(a, s, rand() % (e-s+1) + s, e);
    for(int i = s; i <= m; i++)
        ws += a[i].S;

    if(2*ws >= w)       return med(a, s, m);
    return med(a, m+1, e);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %d", &x[i].F, &y[i].F, &x[i].S);
        y[i].S = x[i].S;
        w += x[i].S;
    }

    L xm = med(x, 1, n), ym = med(y, 1, n);

    L ans = 0;
    for(int i = 1; i <= n; i++)
        ans += abs(x[i].F - xm) * x[i].S + abs(y[i].F - ym) * y[i].S;

    printf("%lld\n", ans);
    return 0;
}
