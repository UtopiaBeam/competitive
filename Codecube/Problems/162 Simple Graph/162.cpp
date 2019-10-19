#include <cstdio>
#include <algorithm>
#define N 100000
#define L long long
using namespace std;

L d[N+2], qs[N+2];
int n, q;

L bs(L s, L e, L k) {
    if (s > e)      return n;
    if (s == e)     return s;
    int m = (s+e+1)/2;
    if (k > d[m])   return bs(s, m-1, k);
    return bs(m, e, k);
}

bool erdos() {
    // Erdős–Gallai theorem
    if (qs[n] % 2)      return false;

    for (L k = 1; k <= n; k++) {
        L idx = bs(k+1, n, k);
        L sum = k*(k-1) + qs[n] - qs[idx] + k*(idx-k);
        if (qs[k] > sum)        return false;
    }
    return true;
}

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", d+i);

        sort(d+1, d+n+1, [](L a, L b) { return a > b; });

        for (int i = 1; i <= n; i++)
            qs[i] = qs[i-1] + d[i];
        
        if (erdos())        printf("Yes\n");
        else        printf("No\n");
    }
    return 0;
}