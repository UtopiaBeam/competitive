#include <cstdio>
#include <algorithm>
int n, m, v, w, mx;
int dp[10002];
int main() {
    scanf("%d %d", &n, &m);
    while(n--) {
        scanf("%d %d", &v, &w);
        for(int i = m; i >= w; i--) {
            dp[i] = std::max(dp[i], dp[i-w]+v);
            mx = std::max(mx, dp[i]);
        }
    }
    printf("%d\n", mx);
    return 0;
}
