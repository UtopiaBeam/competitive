#include <cstdio>
#define N 200000
int n, t;
int ft[N+2], a[N+2];
void ud(int x, int v) {
    for(; x <= n; x += -x&x)   ft[x] += v;
}
int qr(int x) {
    int sum = 0;
    for(; x; x -= -x&x)     sum += ft[x];
    return sum;
}
int bs(int s, int e) {
    if(s == e)      return s;
    int m = (s+e)/2;
    int tmp = qr(m);
    if(t <= tmp)     return bs(s, m);
    return bs(m+1, e);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        ud(i, 1);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        int idx = bs(1, n);
        printf("%d\n", a[idx]);
        ud(idx, -1);
    }
    return 0;
}
