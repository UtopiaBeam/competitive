#include <cstdio>
#include <algorithm>
int n, mx = 0;
int a[100002], ls[100002], p[100002];
int bs(int s, int e, int x) {
    if(s == e)      return s;
    int m = (s+e+1)/2;
    if(a[ls[m]] > x)    return bs(m, e, x);
    return bs(s, m-1, x);
}
int main() {
    a[0] = -1<<30;
    scanf("%d", &n);
    for(int i = n; i > 0; i--)
        scanf("%d", a+i);
    for(int i = 1; i <= n; i++) {
        int l = bs(0, mx, a[i])+1;
        p[i] = ls[l-1];
        ls[l] = i;
        mx = std::max(mx, l);
    }
    printf("%d\n", mx);
    int nw = ls[mx];
    for(int i = 0; i < mx; i++) {
        printf("%d ", a[nw]);
        nw = p[nw];
    }
    return 0;
}
