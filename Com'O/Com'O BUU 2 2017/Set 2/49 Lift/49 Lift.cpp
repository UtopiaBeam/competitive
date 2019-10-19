#include <cstdio>
#define N 45000
int n, t, sum = 0;
int w[102], dp[N+2] = {1};
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        dp[t] = true;
        sum += t;
        for(int i = N; i >= t; i--)
            dp[i] |= dp[i-t];
    }
    for(int i = sum/2; i >= 0; i--)
        if(dp[i] && dp[sum-i]) {
            printf("%d %d\n", i, sum-i);
            return 0;
        }
}
