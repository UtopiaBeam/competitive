#include <cstdio>
#include <algorithm>
#define L long long
int n;
L a[1000002], dp[1000002];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        dp[i] = std::max(dp[i-1], (i>1)*(dp[i-2]+a[i]-a[i-1]));
    }
    printf("%lld\n", dp[n]);
    return 0;
}
