#include <cstdio>
int r, c, n;
int xs, ys, xe, ye;
int dp[1002][1002];
int main() {
    scanf("%d %d %d", &c, &r, &n);
    while(n--) {
        scanf("%d %d %d %d", &ys, &xs, &ye, &xe);
        dp[xs][ys]++;       dp[xe+1][ys]--;
        dp[xs][ye+1]--;     dp[xe+1][ye+1]++;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            printf("%d", dp[i][j]&1);
        }
        printf("\n");
    }
    return 0;
}
