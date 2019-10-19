#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k;
char a[1002], b[1002];
int dp[1002][1002][12][2];
int main() {
    scanf("%d %d %d", &n, &m, &k);
    scanf(" %s %s", a+1, b+1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int t = 1; t <= k; t++) {
                dp[i][j][t][0] = max(max(dp[i-1][j][t][0], dp[i][j-1][t][0]), max(dp[i-1][j][t][1], dp[i][j-1][t][1]) );
                if(a[i] == b[j])    dp[i][j][t][1] = max(dp[i-1][j-1][t][1], dp[i-1][j-1][t-1][0]) + 1;
            }
    printf("%d\n", max(dp[n][m][k][0], dp[n][m][k][1]) );
    return 0;
}
