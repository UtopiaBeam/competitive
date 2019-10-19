#include <cstdio>
#include <algorithm>
#define D double
#define PCS 0.01
int n, m;
D a[100002];
D abs(D x) {
    return (x > 0)? x : -x;
}
bool chk(D x) {
    int cnt = 0;
    D nw = -1e6, d;
    for(int i = 0; i < n; i++) {
        d = abs(a[i] - nw);
        if(d-x > PCS) {
            cnt++;
            nw = a[i] + x;
        }
    }
    return cnt <= m;
}
D bs(D s, D e) {
    if( abs(s-e) <= PCS )      return s;
    D md = (s+e)*0.5;
    if( chk(md) )   return bs(s, md);
    return bs(md, e);
}
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", a+i);
    std::sort(a, a+n);
    printf("%.1lf\n", bs(0, 1e6));
    return 0;
}
