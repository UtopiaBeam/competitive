#include <cstdio>
#include <cstring>
#define L long long
#define MOD (L)(1e9 + 7)
int n, k, d;
L dp[102], t;
L f(int n, int k) {
    if(n == 0)          return 1;
    if(n < 0)           return 0;
    if(dp[n] >= 0)      return dp[n];
    L tmp = 0;
    for(int i = 1; i <= k; i++)
        tmp = (tmp + f(n-i, k)) % MOD;
    return dp[n] = tmp;
}
int main() {
    scanf("%d %d %d", &n, &k, &d);
    memset(dp, -1, sizeof(dp));
    t = f(n, k);
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n", (t - f(n, d-1) + MOD) % MOD );
    return 0;
}
