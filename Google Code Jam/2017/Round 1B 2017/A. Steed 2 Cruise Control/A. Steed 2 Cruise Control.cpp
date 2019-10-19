#include <cstdio>
#include <algorithm>
#define D double
#define P pair<D, D>
#define F first
#define S second
#define INF 1e18
using namespace std;
int q, n, r[1002];
D d;
P a[1002];
void fileIO() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
}
D cal(int x) {
    return (d - a[x].F)/a[x].S;
}
void solve(int q) {
    scanf("%lf %d",&d ,&n);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &a[i].F, &a[i].S);
        r[i] = i;
    }
    sort(a, a+n);
    for(int i = 1; i < n; i++)
        if(cal(i-1) < cal(i))
            r[i-1] = i;
    D mx = -INF;
    for(int i = 0; i < n; i++)
        if(r[i] == i)
            mx = max(mx, cal(i));
    printf("Case #%d: %lf\n", q, d/mx);
}
int main() {
    fileIO();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        solve(i);
    return 0;
}
