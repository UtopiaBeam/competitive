#include <cstdio>
#include <algorithm>
int n, m, k, x, mn = 1<<30;
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x != 0 && x <= k)      mn = std::min(mn, 10*std::abs(i-m));
    }
    printf("%d\n", mn);
    return 0;
}
