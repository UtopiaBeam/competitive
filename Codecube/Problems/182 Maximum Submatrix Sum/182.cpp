#include <cstdio>
#include <algorithm>
#define L long long
#define N (int)(1e5)

int n, h, w;
L a[N+2], b[N+2]; 

int main() {
    scanf("%d %d %d", &n, &h, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b+i);
        b[i] += b[i-1];
    }

    L mxa = 0, mxb = 0;
    for (int i = h; i <= n; i++)
        mxa = std::max(mxa, a[i]-a[i-h]);
    for (int i = w; i <= n; i++)
        mxb = std::max(mxb, b[i]-b[i-w]);
    printf("%lld\n", w*mxa + h*mxb);
    return 0;
}