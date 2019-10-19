#include <cstdio>
#include <algorithm>
int q, n;
int dp[1000002];
int main() {
    for(int i = 2; i <= 1000000; i++) {
        dp[i] = dp[i-1]+1;
        if(i%2 == 0)    dp[i] = std::min(dp[i], dp[i/2]+1);
        if(i%3 == 0)    dp[i] = std::min(dp[i], dp[i/3]+1);
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
