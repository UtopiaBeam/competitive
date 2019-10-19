#include <cstdio>
#include <algorithm>
#define INF 1<<30
int n, m, t;
int dp[1000002];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        dp[i] = INF;
    while(n--) {
        scanf("%d", &t);
        for(int i = t; i <= m; i++)
            dp[i] = std::min(dp[i], dp[i-t]+1);
    }
    if(dp[m] == INF)    printf("0\n");
    else                printf("%d\n", dp[m]);
    return 0;
}
