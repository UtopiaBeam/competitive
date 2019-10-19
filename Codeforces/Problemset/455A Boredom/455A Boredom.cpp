#include <cstdio>
#include <algorithm>
#define N 100000
#define L long long
using namespace std;
int n, x;
L cnt[N+2], dp[N+2];
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        cnt[x]++;
    }
    dp[1] = cnt[1];
    for(int i = 2; i <= N; i++)
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);
    printf("%I64d\n", dp[N]);
    return 0;
}
