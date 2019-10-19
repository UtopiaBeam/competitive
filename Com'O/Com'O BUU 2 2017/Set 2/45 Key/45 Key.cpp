#include <cstdio>
int n, m;
int x, y, k;
int dp[1005][1005];
int main() {
    scanf("%d %d", &n, &m);
    while(n--) {
        scanf("%d %d", &x, &y);
        dp[x+1][y+1]++;
    }
    for(int i = 1; i <= 1001; i++)
        for(int j = 1; j <= 1001; j++)
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    while(m--) {
        int xs, ys, xe, ye;
        scanf("%d %d %d", &x, &y, &k);
        if(x-k < 0)     xs = 0;
        else            xs = x-k;
        if(y-k < 0)     ys = 0;
        else            ys = y-k;
        if(x+k > 1000)  xe = 1001;
        else            xe = x+k+1;
        if(y+k > 1000)  ye = 1001;
        else            ye = y+k+1;
        printf("%d\n", dp[xe][ye] - dp[xs][ye] - dp[xe][ys] + dp[xs][ys]);
    }
    return 0;
}
