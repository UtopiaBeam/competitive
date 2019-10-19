#include <cstdio>
int r, c, n, x, y;
int a[52][52];
long long dp[52][52];
int main() {
    scanf("%d %d", &c, &r);
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &y, &x);
        a[x][y] = 1;
    }
    dp[1][1] = 1 - a[1][1];
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(a[i][j] == 1)    dp[i][j] = 0;
            else        dp[i][j] += dp[i-1][j] + dp[i][j-1];
    printf("%lld\n", dp[r][c]);
    return 0;
}
